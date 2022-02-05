#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;


///////////////// Colour Detection //////////////////////////

Mat imgHSV, mask;
int hmin = 30, smin = 49, vmin = 31;
int hmax = 84, smax = 217, vmax = 203;
//these values come from set stuff
//there are 6 values involved, so it takes a lot of time to get them proper
//instead, create track bars to change this stuff in real time

//later show how to find a different colour
//when moving track bars, start with mins at 0 and maxs at the largest value
//then move track bars inwards while keeping the colour of interest in WHITE

int main() {

	VideoCapture cap(0);
	Mat img;

	//first convert image to HSV space, since it is easier to get the colour


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


	cap.read(img); //sets img to webcam input
	cvtColor(img, imgHSV, COLOR_BGR2HSV); //outputs img converted to HSV type

	//lower and upper gives range of values to get the colour from
	Scalar lower(hmin, smin, vmin); //hue min, saturation minimum, value minimum
	Scalar upper(hmax, smax, vmax); //hue max, saturation max, value max

	inRange(imgHSV, lower, upper, mask);

	/// mat is a matrix data type introduced by open cv to deal with images
	/// mat is basically data type for images
	imshow("Image", img);
	imshow("Image HSV", imgHSV);
	imshow("Image Mask", mask);

	cout << img.size << endl;

	Mat maskResize, HSVresize;

	resize(mask, maskResize, Size(32, 24));
	resize(imgHSV, HSVresize, Size(32, 24));


	cout << maskResize.size << endl;

	cout << maskResize << endl;

	cout << HSVresize << endl;

	waitKey(0);


	return 0;


}

