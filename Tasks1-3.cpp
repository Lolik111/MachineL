#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <string.h>
#include <iostream>

using namespace std;
using namespace cv;

void CounterW(const string& in, const string& out){
	Mat img = cv::imread(in);
	Mat img2;
	vector<Mat> contours;
	cv:cvtColor(img, img2, COLOR_BGR2GRAY);
	cv::threshold(img2, img2, 127.0, 255.0, 0);
	cv::findContours(img2, contours, RetrievalModes::RETR_EXTERNAL, ContourApproximationModes::CHAIN_APPROX_SIMPLE);
	cv::drawContours(img, contours, -1, { 0, 0, 255 }, 3);
	cv::imwrite(out, img);
	cv::imshow("f", img);
	cv::waitKey(0);
}

void CounterW2(const string& in, const string& out){
	Mat img = cv::imread(in);
	Mat img2;
	vector<Mat> contours;
	cv:cvtColor(img, img2, COLOR_BGR2GRAY);
	cv::threshold(img2, img2, 127.0, 255.0, cv::ThresholdTypes::THRESH_TRUNC);
	cv::findContours(img2, contours, RetrievalModes::RETR_TREE, ContourApproximationModes::CHAIN_APPROX_SIMPLE);
	cv::drawContours(img, contours, -1, { 0, 0, 255 }, 3);
	cv::imwrite(out, img);
	cv::imshow("f", img);
	cv::waitKey(0);
}

void CounterW3(const string& in, const string& out){
 	const Mat img = cv::imread(in);
	Mat img2;
	Mat img3;
	vector<Mat> contours;
	for (int i = 0; i < 5; i++) {
		cout << i;
		img.copyTo(img3);
		cv:cvtColor(img.clone(), img2, COLOR_BGR2GRAY);
		cv::threshold(img2, img2, 127.0, 255.0, cv::ThresholdTypes::THRESH_TRUNC);
		if (i != 4){
			cv::findContours(img2, contours, i, ContourApproximationModes::CHAIN_APPROX_SIMPLE);
		} else {
			Mat imm;
			img2.clone().convertTo(imm, CV_32SC1);
			cv::findContours(imm, contours, i, ContourApproximationModes::CHAIN_APPROX_SIMPLE);
		}
		cv::drawContours(img3, contours, -1, { 0, 0, 255 }, 3);
		cv::imwrite(std::string:: out, img);
		cv::imshow("f", img3);
		cv::waitKey(0);
	}	
}





int main(){
	try{
		CounterW3("C:\\Users\\ÏÀÕÀÐÜ\\Desktop\\Kappasaurus Rekt.jpg", "C:\\Users\\ÏÀÕÀÐÜ\\Desktop\\Kappasaurus RektJuekt.jpg");
	}
	catch (Exception e){
		cout << e.err;
	}
	system("pause");
}
