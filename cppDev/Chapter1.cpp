#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/////////////////Importing Images//////////////////////////

//void main() {
//
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	/// mat is a matrix data type introduced by open cv to deal with images
//	/// mat is basically data type for images
//	imshow("Image", img);
//	waitKey(0);
//
//
//}


//////////// video ///////////////
//
//
//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//
//		cap.read(img);
//		
//		imshow("image", img);
//		waitKey(20);
//
//	}
//
//}



/////////////////// Webcam //////////////////////
///basically just changing the path - using ID number of camera
///if you only have one camera attached you can just write 0
/// if you have multiple, you could have camera ID 1, or something else
void main() {
	VideoCapture cap(0);
	Mat img, imgBlur, imgCanny, imgDil;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

	while (true) {
		cap.read(img);
		GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
		Canny(imgBlur, imgCanny, 50, 150);
		dilate(imgCanny, imgDil, kernel);
		
		imshow("Dilated Image", imgDil);
		waitKey(1);
	}
}