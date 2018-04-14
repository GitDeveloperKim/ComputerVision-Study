#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat src;
	if (argv[1]) {
		src = imread(argv[1], IMREAD_GRAYSCALE);
	} 
	else {
		src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	}

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	
	Mat dst(src.rows, src.cols, src.type());

/* "+/-" �� �̿��� ��� ���� */
#if 0
	dst = src - 100;

#endif

/* �ȼ� �� ���� ����� �̿��� ��� ���� */
#if 0
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			// �̷��Ը� �� ��� saturate �� �ȵ�
			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100; 

			// �Ʒ� ó�� ��쿡 ���� �����ֵ��� �Ѵ�.
			int v = src.at<uchar>(j, i) + 100;
			dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;

			// Ȥ�� saturate_cast �Լ� ���
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
		}
	}
#endif

/* ��� ��� ���� */
#if 1
	int s = 0;
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			s += src.at<uchar>(j, i);
		}
	}
	int m1 = s / (src.rows * src.cols);
	// sum�� mean �� scalar ���̹Ƿ� 0��°�� �����´�.
	int m2 = sum(src)[0] / src.total();
	int m3 = mean(src)[0];

	dst = src + (128 - m3);
#endif

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
