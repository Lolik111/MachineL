#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <string.h>
#include <iostream>

using namespace std;
using namespace cv;

void PedestriansRecognize(const string& in){
	Mat img = cv::imread(in);
	Mat img2;
	cv::resize(img, img2, cv::Size(0, 0), 2, 2);
	cv::HOGDescriptor hog(cv::Size(64, 128), cv::Size(16, 16), cv::Size(8, 8), cv::Size(8, 8), 9);
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	assert(hog.checkDetectorSize());
	vector<Rect> vv;
	hog.detectMultiScale(img2, vv);
	for each (Rect r in vv)
	{
		rectangle(img2, r, { 0, 0, 255 });
	}
	cv::resize(img2, img2, cv::Size(0, 0), 0.5, 0.5);
	cv::imshow("lalka", img2);
	cv::waitKey(0);
}

int main(){
	try{
		PedestriansRecognize("C:\\Users\\œ¿’¿–‹\\Desktop\\PedestriansPhoto.jpeg");
	}
	catch (Exception e){
		cout << e.err;
	}
	system("pause");
}