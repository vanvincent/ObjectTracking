#include <cv.h>
#include <highgui.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"
#include "data.h"

#include "ros/ros.h"
#include "colortrack_ros/GetDirection.h"

#define PI 3.14159

using namespace std;
using namespace cv;
//initialize parameters
RNG rng(12345);

colortrack_ros::GetDirection::Response response;
Object *cup = NULL;

bool GetDirection(colortrack_ros::GetDirection::Request  &req,
         colortrack_ros::GetDirection::Response &res)
{
  if(req.color.compare("orange") == 0)		
			cup= new Orangecup();
  else if(req.color.compare("blue") == 0)
			cup=new Bluecup();
	else if(req.color.compare("pink") == 0)
			cup=new Pinkcup();		
			//add functions here
  res = response ;
  return true;
}

/// Function header
void segmentation(cv::Mat,cv::Mat);

//This function threshold the HSV image and create a binary image
IplImage* GetThresholdedImage(IplImage* imgHSV,Object* obj){
	
	IplImage* imgThresh=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
	cvInRangeS(imgHSV, cvScalar(obj->lowerH,obj->lowerS,obj->lowerV), cvScalar(obj->upperH,obj->upperS,obj->upperV), imgThresh);
	return imgThresh;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "colortrack");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("GetDirection", GetDirection);

	CvCapture* capture =0;
	capture = cvCaptureFromCAM(1);
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640 );
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480 );
	Mat image2,frame2;

	
	
	if(!capture){
		printf("Capture failure\n");	
		return -1;
	}
	
   IplImage* frame=0;
	//setwindowSettings();
	//iterate through each frames of the video

	//make option
	
		int col;
			
	while(true){

    ros::spinOnce();
		//specify which object
		if (!cup)
        break;
		
		frame = cvQueryFrame(capture);
		if(!frame)  break;
		frame=cvCloneImage(frame);
		frame2=cvCloneImage(frame);
		IplImage* imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
		cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV
		IplImage* imgThresh = GetThresholdedImage(imgHSV,cup);
		cv::Mat image1(imgThresh); //change IplImage to Mat format
		
		blur( image1, image1, Size(3,3) );//blur the image
		
  		segmentation( image1 ,frame2);
		
		cvReleaseImage(&imgHSV);
		cvReleaseImage(&imgThresh);
		cvReleaseImage(&frame);
		frame2.release();
		image1.release();
		//Wait 80mS
		int c = cvWaitKey(80);
		//If 'ESC' is pressed, break the loop
		if((char)c==27 ) break;
		}	

	cvDestroyAllWindows();
	cvReleaseCapture(&capture);
	//delete cup;
	
	return 0;
}


void segmentation(cv::Mat image ,cv::Mat image2)
{
	Mat threshold_output;
 	vector<vector<Point> > contours;
  	vector<Vec4i> hierarchy;
	//radius of object
	float robj,aobj;
	float xobj,yobj;
	float distance;
  	/// Detect edges using Threshold
  	threshold( image, threshold_output, 100, 255, 1 );
  	/// Find contours
  	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	
  	/// Approximate contours to polygons + get bounding rects and circles
  	vector<vector<Point> > contours_poly( contours.size() );
  	vector<Rect> boundRect( contours.size() );
  	vector<Point2f>center( contours.size() );
  	vector<float>radius( contours.size() );
	
  	for(unsigned int i = 0; i < contours.size(); i++ )
     	{ 
		      approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       		boundRect[i] = boundingRect( Mat(contours_poly[i]) );
       		minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
     	}


  /// Draw polygonal contour + bonding rects + circles
  	Mat drawing = cv::Mat::zeros( threshold_output.size(), CV_8UC3 );
  	for(unsigned int i = 0; i< contours.size(); i++ )
     	{
       		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
                //draw on the orignal frame
		      if(lowerR<(int)radius[i] && (int)radius[i]<upperR){
		      drawContours( image2, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
       		//rectangle( image2, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
       		circle( image2, center[i], (int)radius[i], color, 2, 8, 0 );
		      robj=radius[i];
		      xobj=center[i].x;
		      yobj=center[i].y;
		    }
     	}
	
	char buffer [50],buffer2[50];
	aobj=PI*robj*robj;
	if(robj!=0)
		distance=1187.0/robj;
		
		//change response data
		response.left_distance = xobj-320;
		response.front_distance = distance;
		
  	sprintf (buffer, "Radius:%5.2f Distance:%5.2f(inch)",robj,distance);
	sprintf (buffer2, "Area:%5.2f Deviation from Center:%5.2f %5.2f ",aobj,xobj-320,yobj-240);	
	
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 0.3;
	int thickness = 1;  
	Point textOrg(10, 10),textOrg2(10,20),textOrg3(10,30);
	putText(image2, buffer, textOrg, fontFace, fontScale, Scalar::all(255), thickness,8);
	putText(image2, buffer2, textOrg2, fontFace, fontScale, Scalar::all(255), thickness,8);
	
	namedWindow( "Vision", CV_WINDOW_AUTOSIZE );
  	imshow( "Vision", image2 );
}
