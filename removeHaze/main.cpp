#include <iostream>
#include "RemoveHaze.h"
#include <string>
using namespace std;

int main()
{
	string hotImagePath;
	cout << "����HOTӰ���·����" << endl;
	cin >> hotImagePath;
	string maskImagePath;
	cout << "����maskӰ���·����" << endl;
	cin >> maskImagePath;
	string markImagePath;
	cout << "����markӰ���·����" << endl;
	cin >> markImagePath;
	string tcImagePath;
	cout << "����TotalChangeӰ���·����" << endl;
	cin >> tcImagePath;
	string mcImagePath;
	cout << "����MaxChangeӰ���·����" << endl;
	cin >> mcImagePath;
	string erodeIamgePath;
	cout << "������ʴ��Ӱ���·����" << endl;
	cin >> erodeIamgePath;
	string binaryImagePath;
	cout << "������ֵ����Ӱ���·����" << endl;
	cin >> binaryImagePath;
	string resultImagePath;
	cout << "�������Ӱ���·����" << endl;
	cin >> resultImagePath;
	HazePerfection *testHazePer = new HazePerfection;
	testHazePer->setHotImagePath(hotImagePath);
	testHazePer->setMaskImagePath(maskImagePath);
	testHazePer->setMarkImagePath(markImagePath);
	testHazePer->setTotalChangeImagePath(tcImagePath);
	testHazePer->setMaxChangeImagePath(mcImagePath);
	testHazePer->setErodeImagePath(erodeIamgePath);
	testHazePer->setBinaryImagePath(binaryImagePath);
	testHazePer->setResultImagePath(resultImagePath);

	//TODO:����ֵ��ȷ��
	testHazePer->setErodeTimes(5);
	testHazePer->setHighThreshold(10.0, 10.0);

	testHazePer->morphfill();
	testHazePer->removePeak();
	return 1;
}