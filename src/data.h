#ifndef OBJECT_DATA_H_
#define OBJECT_DATA_H_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int upperR=200;
const int lowerR=15;

class Object{
	public:
		Object(){}
		int lowerH;
		int lowerS;
		int lowerV;
		int upperH;
		int upperS;
		int upperV;
};

class Orangecup :  public Object{
	public:
		Orangecup() : Object(){
		lowerH=0;
	        lowerS=195;
		lowerV=170;
		upperH=21;
		upperS=256;
		upperV=256;
		}
};

class Bluecup :  public Object{
	public:
		Bluecup() : Object(){
		lowerH=75;
	        lowerS=0;
		lowerV=0;
		upperH=130;
		upperS=256;
		upperV=256;
		}
};

class Pinkcup :  public Object{
	public:
		Pinkcup() : Object(){
		lowerH=140;
	        lowerS=10;
		lowerV=180;
		upperH=180;
		upperS=256;
		upperV=256;
		}
};




#endif
