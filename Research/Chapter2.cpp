#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

///////////////// Basic functions //////////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	/// mat is a matrix data type introduced by open cv to deal with images
	/// mat is basically data type for images
	/// after reading, convert to grayscale
	

	Mat imgGray;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	//add blurs
	/// gaussianblur
	Mat imgBlur;

	GaussianBlur(img, imgBlur, Size(3,3),3,0);

	//edge detection
	// Canny edge detector (one of the most common)
	//common practice to use blur before edge detection

	Mat imgCanny;

	Canny(imgBlur, imgCanny, 50, 150);
	
	/// play around with variables to find optimal results - control click on the function to see its description in the header files

	///  can also use track bars to find optimum detection


	// how to dialate and erode an image
	//most of the time, edges are not joined, or very thin
	//dialate increases thickness, erode decreases thickness

	Mat imgDil, imgErode;
	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	// creates a Kernel you can use with dilation, higher values = more dialation
	// shoulduse only odd numbers

	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel); //brings back to the imgCanny? - not really
	// eroding from the thing makes it a bit different 
	//these functions come in handy when trying to detect the shapes of objects

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Canny", imgCanny);
	imshow("Canny dialate", imgDil);
	imshow("Canny erode", imgErode);
	waitKey(0);


}
