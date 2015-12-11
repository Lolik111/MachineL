#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <string.h>
#include <iostream>

using namespace std;
using namespace cv;

class Task4{
public:
	Task4(CascadeClassifier cc){
		_cc = cc;
	}

	void DoWork(const string file){
		VideoCapture vc(0);
		int width = int(vc.get(CV_CAP_PROP_FRAME_WIDTH));
		int height = int(vc.get(CV_CAP_PROP_FRAME_HEIGHT));
		VideoWriter writer(file, vc.get(CV_CAP_PROP_FOURCC), vc.get(CV_CAP_PROP_FPS), { width, height });
		while (true){
			Mat img;
			vc.read(img);
			img = detect(img);
			if (vc.isOpened()){
				writer.write(img);
			}
			cv::imshow("f", img);
			if (cv::waitKey(1) == 0x1b){
				break;
			}
		}
		vc.release();
		writer.release();
	}


private:
	CascadeClassifier _cc;
	Mat detect(const Mat& img){
		Mat a, b;
		a = img.clone();
		cv::cvtColor(a, b, COLOR_BGR2GRAY);
		vector<Rect> obj;
		_cc.detectMultiScale(b, obj, 1.5, 1, CV_HAAR_SCALE_IMAGE);
		for each (Rect r in obj)
		{
			rectangle(a, r, { 0, 0, 255 });
		}
		return a;
	}
};





int main(){
	try{
		CascadeClassifier cc("haarcascade_frontalface_alt.xml");
		Task4 t(cc);
		t.DoWork("C:\\Users\\œ¿’¿–‹\\Desktop\\HUIHUIHUI.avi");
	}
	catch (Exception e){
		cout << e.err;
	}
	system("pause");
}