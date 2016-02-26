#pragma once
#include <GDAL/gdal_priv.h>
#include <string>
using namespace std;
class HazePerfection
{
public:
	HazePerfection();
	~HazePerfection();
	void setHotImagePath(const string hotPath);               //����HOTӰ���·��
	void setMaskImagePath(const string maskPath);
	void setMarkImagePath(const string markPath);
	void setTotalChangeImagePath(const string tcPath);
	void setMaxChangeImagePath(const string mcPath);
	void setErodeImagePath(const string erodePath);     //������̬ѧ��ʴ���ͼ��·��
	void setResultImagePath(const string resultPath);
	void setErodeTimes(const int times);//������ʴ����
	void setHighThreshold(const float mc, const float tc);//����maxChange��totalChange����ֵ���ж�ֵ��
	void setBinaryImagePath(const string binaryPath);

	void morphfill();//�����㷨       1ʹ��setHotImagePath��setInvertA��setMarkB��setMaskImagePath��setMarkImagePath
	void removePeak();  //����   2ʹ��setTotalChangeImagePath��setMaxChangeImagePath��setErodeImagePath��setErodeTimes��setHighThreshold��setResultImagePath��setBinaryImagePath


private:
	void readHotImage();                                                    //��ȡHOTӰ��
	void invertImage(GDALDataset *pDataset, GDALDataset *dstDataset, float a);                //��ͼ���� 
	void morphologicalReconstruction(GDALDataset *asMarkDataset, GDALDataset *asMaskDataset);//��̬ѧ�ؽ�
	void morphologicalErode(GDALDataset *morphDataset);//��̬ѧ��ʴ
	void detectionPeak();//���������������������binaryDataset�ڴ˴���

	void setInvertA(const float A);//������ʱ��inverta��ֵ
	void setMarkB(const float B);//���ô���MarkӰ��ʱb��ֵ

	int nXSize;
	int nYSize;
	int nBandCount;
	float inverta;//ȡ��ʱ��a��ֵ
	float markB;  //markӰ���ֵ
	int erodeN;  //��ʴ�Ĵ���
	float thresholdMC;
	float thresholdTC;
	double sGeoTrans[6];
	void createMask();//����maskDataset
	void createMark(float b);//����markDataset
	void createChangeImage();  //����totalChangeDataset��maxChangeDataset��erodeDataset
	void createResultImage();//����resultDataset
	float minA(float a[],int n);
	float maxA(float a[], int n);
	void difference(GDALDataset *aDataset, GDALDataset *bDataset);

	string m_hotfilename;
	GDALDataset *hotDataset;   //�����HOTͼ��
	string m_maskfilename;
	string m_markfilename;
	GDALDataset *maskDataset;    //�����㷨ʱ��maskӰ��
	GDALDataset *markDataset;    //�����㷨ʱ��markӰ��

	string m_totalchangefilename;
	string m_maxchangefilename;
	string m_erodefileName;
	GDALDataset *totalChangeDataset;    //�����㷨ʱTCӰ��
	GDALDataset *maxChangeDataset;     //�����㷨ʱMCӰ��
	GDALDataset *erodeDataset;               //��̬ѧ��ʴ���ͼ��

	string m_binaryfilename;
	GDALDataset *binaryDataset;              //����TC��MCӰ��Ķ�ֵ��ͼ�񣬼�ͼ���ϸ����ȶ����������Ӱ��

	string m_resultfilename;
	GDALDataset *resultDataset;
};

