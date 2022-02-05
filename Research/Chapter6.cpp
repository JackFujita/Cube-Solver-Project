#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

///////////////// Colour Detection //////////////////////////

//maybe need colour calibration function for the app?

Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;
//these values come from set stuff
//there are 6 values involved, so it takes a lot of time to get them proper
//instead, create track bars to change this stuff in real time

//later show how to find a different colour
//when moving track bars, start with mins at 0 and maxs at the largest value
//then move track bars inwards while keeping the colour of interest in WHITE

int main() {

	string path = "Resources/shapes.png";

	//first convert image to HSV space, since it is easier to get the colour

	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	//initially HSV image looks a bit weird
	//once converted, use inrange function to collect colour

	//create track bar
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179); //hue max value is 180
	//other max values are 255
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {


		//lower and upper gives range of values to get the colour from
		Scalar lower(hmin, smin, vmin); //hue min, saturation minimum, value minimum
		Scalar upper(hmax, smax, vmax); //hue max, saturation max, value max

		inRange(imgHSV, lower, upper, mask);

		/// mat is a matrix data type introduced by open cv to deal with images
		/// mat is basically data type for images
		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);

		waitKey(1);

	}

	return 0;


}

