#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// ���ڰ� 3�� ���� �۴ٸ� ���� ȣ��
	if (argc < 3) {
		cout << "Usage: ocvrt.exe <src_image> <dst_image> [JPEG_QUALITY]" << endl;
		return 0;
	}
	
	// �Է��� ������ �о��
	Mat img = imread(argv[1], IMREAD_UNCHANGED);

	// ������ ��� �ִٸ� ���� ȣ��
	if (img.empty()) {
		cerr << "image load failed" << endl;
		return -1;
	}

	// ���� ���� �ɼ� ����(3������ ���� ��� ����, �ƴ� ����Ʈ)
	vector<int> params;
	if (argc == 4) {
		params.push_back(IMWRITE_JPEG_QUALITY);
		params.push_back(atoi(argv[3]));
	}

	// ���� �����ϱ�
	bool ret = imwrite(argv[2], img, params);

	if (ret) {
		cout << argv[1] << " is successfully saved ad " << argv[2] << endl;
	}
	else {
		cout << "File save failed!" << endl;
	}

	return 0;
}
