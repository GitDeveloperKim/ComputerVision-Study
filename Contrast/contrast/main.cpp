#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat src;
	if (argc < 2) {
		src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	}
	else {
		src = imread(argv[1], IMREAD_GRAYSCALE);
	}

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	float alpha = 1.5f;
	Mat dst;

#if 0
	// Mat ������ ������ ���
	dst = src + (src - 128)*alpha; // ���� �̿�
#endif

#if 0
	// Mat �ȼ� ������ ���� ���
	dst = Mat::zeros(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		uchar* pSrc = src.ptr<uchar>(j);
		uchar* pDst = dst.ptr<uchar>(j);
		for (int i = 0; i < src.cols; i++) {
			// ���� �̿�
			pDst[i] = saturate_cast<uchar>(pSrc[i] + (pSrc[i] - 128)*alpha);
		}
	}
#endif
#if 1
	// ��� ��⸦ ����� ��Ϻ� ����
	int m = mean(src)[0];
	dst = src + (src - m)*alpha; // Ǯ�� src * (1+alpha) - m * alpha �� ����
#endif
	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
