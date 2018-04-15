#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int gBrightness = 100; // �ִ� ����
Mat src, dst;

void on_brightness(int pos, void* data) {
	Mat* pSrc = (Mat*)data; // data�� ���� �� �� �ִ�. (�������� ��� ���� ��)
	cout << gBrightness << ", " << pos << endl; // �������� ����ص� �ǰ� pos ������ �̿��ص� �ȴ�. (pos �� Brightness �� �����ϰ� ���´�.)
	dst = src + (gBrightness - 100); // �ּڰ� ����
	imshow("dst", dst);
}

int main(void)
{
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	
	dst;
	dst.create(src.rows, src.cols, src.type());
	namedWindow("dst");
	imshow("src", src);

	// �ݵ�� createTrackbar�� imshow Ȥ�� namedWindow�ڿ� ���־�� trackbar�� �̿� �����Ѵ�.
	createTrackbar("Brightness", "dst", &gBrightness, 200, on_brightness,0);
	on_brightness(0, 0); // ó���� ���� �κ��� ����� �ش�.
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
