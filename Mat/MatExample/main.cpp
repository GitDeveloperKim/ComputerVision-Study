#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void func1();
void func2();
void func3();
void func4();

int main(void)
{
	func1(); getchar();
	func2(); getchar();
	func3(); getchar();
	func4(); getchar();

	return 0;
}

/**
	Mat Ŭ���� ��ü ���� & ��� ���� ������ ����
*/
void func1() {
	// Mat Ŭ���� ��ü ����
	int rows = 480, cols = 640;
	Mat img1(rows, cols, CV_8U);			// unsigned char
	Mat img2(rows, cols, CV_8UC3);			// unsigned char, 3 channel
	Mat img3(Size(cols, rows), CV_8UC3);	// Size(width, height)
	img3.create(rows, cols, CV_32F);		// float

	Mat img4 = imread("lenna.bmp");

	// Ư�� ������ ��,�� ���� ������
	cout << "Width: " << img4.cols << endl;
	cout << "Height: " << img4.rows << endl;

	// Ư�� ������ ä�� ���� �ҷ�����
	cout << "Channels: " << img4.channels() << endl;

	// Ư�� ������ Ÿ�� �ҷ�����
	if (img4.type() == CV_8UC1)
		cout << "img4 is a grayscale image" << endl;
	else if (img4.type() == CV_8UC3)
		cout << "img4 is a truecolor image" << endl;
}

void func2() {
	// ������ ���ÿ� ���� �� ����
	int nRows = 3, nCols = 4;
	Mat img1(nRows, nCols, CV_8U, Scalar(128));		// 128�� �ʱ�ȭ�� ��� ����
	Mat img2 = Mat::ones(3, 4, CV_8U);				// 1�� �ʱ�ȭ�� ��� ����
	Mat img3 = Mat::zeros(3, 4, CV_8U);				// 0���� �ʱ�ȭ�� ��� ����
	Mat img4 = Mat::ones(480, 640, CV_8U) * 255;	// 255�� �ʱ�ȭ�Ǿ� �ִ� ��� ����

	// img1 �� ���� ���� 0 (Ȥ�� �ٸ� ��)�� �ʱ�ȭ
	img1.setTo(0);

	// ��Ŀ� ���� ������ ������ �ʱ�ȭ ���� 
	float data[] = { 1,2,3,4,5,6 };
	Mat img5(2, 3, CV_32F, data);
	cout << "img5:\n" << img5 << endl;	// [ 1 2 3 �������� ���´�.
										//	 4 5 6 ]

	Mat mat5 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6);
}

void func3() {
	// ���� ���� & ����
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Mat img2 = img1;			// ���� (�A�� ����)
	Mat img3 = img1.clone();	// (����) ����
	Mat img4;			
	img1.copyTo(img4);			// (����) ����

	// �κ� ���� ���� & ����
	Mat img5 = img1(Rect(100, 100, 200, 200));
	Mat img6 = img4(Rect(100, 100, 200, 200)).clone();

	img5.setTo(0);
	img6.setTo(255);

	imshow("img1", img1); imshow("img2", img2); imshow("img3", img3); 
	imshow("img4", img4); imshow("img5", img5); imshow("img6", img6);
	waitKey();
	destroyAllWindows();
}

void func4() {
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32F, data);
	cout << "mat:\n" << mat1 << endl;

	// �����
	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;

	// ��ġ���
	cout << "mat1.t():\n" << mat1.t() << endl;

	// ��Ģ����
	cout << "mat1 + 3:\n" << mat1 + 3 << endl;
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;
}