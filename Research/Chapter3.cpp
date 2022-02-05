#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

///////////////// Resize and crop //////////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	//to resize
	Mat imgResize;

	// to get current image size: cout << img.size() << endl;

	//resize(img, imgResize, Size(640, 480)); //this one specifies a specific end size

	resize(img, imgResize, Size(), 0.5, 0.5);//this way just decreases size by 50% on each axis
	
	//cropping to region of interest (ROI)
	Mat imgCrop;

	Rect roi(200, 300, 300, 100);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop); 

	waitKey(0);
}
