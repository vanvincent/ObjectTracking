#include <cv.h>
#include <highgui.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"

#define PI 3.14159

using namespace std;
using namespace cv;
//initialize parameters
int lowerH=0;
int lowerS=0;
int lowerV=0;

int upperH=180;
int upperS=256;
int upperV=256;
int lowerR=0;
int upperR=200;
Mat image2,frame2;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );

//This function threshold the HSV image and create a binary image
IplImage* GetThresholdedImage(IplImage* imgHSV){
	IplImage* imgThresh=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
	cvInRangeS(imgHSV, cvScalar(lowerH,lowerS,lowerV), cvScalar(upperH,upperS,upperV), imgThresh);
	return imgThresh;
}
//This function create two windows and 6 trackbar
void setwindowSettings(){
	//cvNamedWindow("Video");
	cvNamedWindow("Object");
	cvCreateTrackbar("LowerH", "Object", &lowerH, 180, NULL);
        cvCreateTrackbar("UpperH", "Object", &upperH, 180, NULL);
	cvCreateTrackbar("LowerS", "Object", &lowerS, 256, NULL);
        cvCreateTrackbar("UpperS", "Object", &upperS, 256, NULL);
	cvCreateTrackbar("LowerV", "Object", &lowerV, 256, NULL);
        cvCreateTrackbar("UpperV", "Object", &upperV, 256, NULL);
}

int main(){
	CvCapture* capture =0;
	capture = cvCaptureFromCAM(1);
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640 );
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480 );
	if(!capture){
		printf("Capture failure\n");	
		return -1;
	}
	
        IplImage* frame=0;
	setwindowSettings();
	//iterate through each frames of the video
	while(true){
		frame = cvQueryFrame(capture);
		if(!frame)  break;
		frame=cvCloneImage(frame);
		frame2=cvCloneImage(frame);
		IplImage* imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
		cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV
		IplImage* imgThresh = GetThresholdedImage(imgHSV);
		cv::Mat image1(imgThresh); //change IplImage to Mat format
		//imshow("mat image",image1);
		image2=image1.clone();
		blur( image2, image2, Size(3,3) );//blur the image
		namedWindow( "Source", CV_WINDOW_AUTOSIZE );
 		imshow( "Source", image1 );
  		createTrackbar( " Threshold:", "Source", &thresh, max_thresh, thresh_callback );
                createTrackbar( " Radius:", "Source", &lowerR, upperR, thresh_callback );
  		thresh_callback( 0, 0 );
		cvShowImage("Object", imgThresh);
		//cvShowImage("Video", frame);

		//Clean up used images
		cvReleaseImage(&imgHSV);
		cvReleaseImage(&imgThresh);
		cvReleaseImage(&frame);
		
		//Wait 80mS
		int c = cvWaitKey(80);
		//If 'ESC' is pressed, break the loop
		if((char)c==27 ) break;
		}	

	cvDestroyAllWindows();
	cvReleaseCapture(&capture);

	return 0;
}


void thresh_callback(int, void* )
{
	Mat threshold_output;
 	vector<vector<Point> > contours;
  	vector<Vec4i> hierarchy;
	//radius of object
	float robj,aobj;
	int width, height;
	float xobj,yobj;
	float distance;
  	/// Detect edges using Threshold
  	threshold( image2, threshold_output, thresh, 255, 1 );
  	//namedWindow( "threshold", CV_WINDOW_AUTOSIZE );
  	//imshow( "threshold", threshold_output );
  	/// Find contours
  	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	
  	/// Approximate contours to polygons + get bounding rects and circles
  	vector<vector<Point> > contours_poly( contours.size() );
  	vector<Rect> boundRect( contours.size() );
  	vector<Point2f>center( contours.size() );
  	vector<float>radius( contours.size() );
	
  	for( int i = 0; i < contours.size(); i++ )
     	{ 
		approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       		boundRect[i] = boundingRect( Mat(contours_poly[i]) );
       		minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
     	}


  /// Draw polygonal contour + bonding rects + circles
  	Mat drawing = cv::Mat::zeros( threshold_output.size(), CV_8UC3 );
  	for( int i = 0; i< contours.size(); i++ )
     	{
       		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       		//drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
       		//rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
       		//circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 );
                //draw on the orignal frame
		if(lowerR<(int)radius[i] && (int)radius[i]<upperR){
		drawContours( frame2, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
       		//rectangle( frame2, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
       		circle( frame2, center[i], (int)radius[i], color, 2, 8, 0 );
		robj=radius[i];
		xobj=center[i].x;
		yobj=center[i].y;
		}
     	}
	
	char buffer [50],buffer2[50];
	aobj=PI*robj*robj;
	if(robj!=0)
		distance=1187.0/robj;
  	sprintf (buffer, "Radius:%5.2f Distance:%5.2f(inch)",robj,distance);
	sprintf (buffer2, "Area:%5.2f Deviation from Center:%5.2f %5.2f ",aobj,xobj-320,yobj-240);	
	
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 0.3;
	int thickness = 1;  
	Point textOrg(10, 10),textOrg2(10,20),textOrg3(10,30);
	putText(frame2, buffer, textOrg, fontFace, fontScale, Scalar::all(255), thickness,8);
	putText(frame2, buffer2, textOrg2, fontFace, fontScale, Scalar::all(255), thickness,8);
	
        /// Show in a window
  	//namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  	//imshow( "Contours", drawing );
	namedWindow( "frame2", CV_WINDOW_AUTOSIZE );
  	imshow( "frame2", frame2 );
	
	//image size is 160*120 pixel
}
