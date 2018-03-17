// OpenCV ���� ��� ������ #include
#include "opencv2/opencv.hpp"
#include <iostream>

// OpenCV & STL ���� �����̽� ����
using namespace cv;
using namespace std;

int main(void) {
	cout << "Hello OpenCV " << CV_VERSION << endl;

	// �Է� ������ ���� ����
	Mat img;

	// lenna.bmp ������ �ҷ�����
	img = imread("lenna.bmp");

	// ���� ���� �ҷο��� ���� �� ���� �޽��� ��� �� ���α׷� ����
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// "image" ��� �̸��� �� â�� �����, ���⿡ img ���� ���
	namedWindow("image");
	imshow("image", img);
	// Ű���� �Է��� ���� ������ ���α׷��� ���߰� ��� ( waitkey(2000) �̸� 2�� �� ���� )
	waitKey(0);
	return 0;
}
