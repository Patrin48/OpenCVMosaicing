#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "MainFunctions.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
using namespace cv;
using namespace std;
Mat MainFunctions::cropBlackBoundaries(Mat &image) {
	Mat cropped, grayed, thresh, result;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<Vec4i> hierarchy;
	cvtColor(image, grayed, CV_BGR2GRAY);
	threshold(grayed, thresh, 1, 255, THRESH_BINARY);
	findContours(thresh, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

	std::vector<int> x, y;
	for (unsigned int i = 0; i < contours.size(); i++) {
		for (unsigned int j = 0; j < contours.at(i).size(); j++) {
			x.push_back(contours[i][j].x);
			y.push_back(contours[i][j].y);
		}
	}

	auto xVals = std::minmax_element(x.begin(), x.end());
	auto yVals = std::minmax_element(y.begin(), y.end());

	Rect rect(*xVals.first, *yVals.first, (*xVals.second) - (*xVals.first), (*yVals.second) - (*yVals.first));
	cropped = image(rect);
	return cropped;
}
std::wstring MainFunctions::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
bool MainFunctions::checkInteriorExterior(const cv::Mat&mask, const cv::Rect&interiorBB, int&top, int&bottom, int&left, int&right)
{
	bool returnVal = true;

	cv::Mat sub = mask(interiorBB);

	unsigned int x = 0;
	unsigned int y = 0;

	unsigned int cTop = 0; // top row
	unsigned int cBottom = 0; // bottom row
	unsigned int cLeft = 0; // left column
	unsigned int cRight = 0; // right column
							 // and choose that side for reduction where mose exterior pixels occured (that's the heuristic)

	for (y = 0, x = 0; x < sub.cols; ++x)
	{
		// if there is an exterior part in the interior we have to move the top side of the rect a bit to the bottom
		if (sub.at<unsigned char>(y, x) == 0)
		{
			returnVal = false;
			++cTop;
		}
	}

	for (y = sub.rows - 1, x = 0; x < sub.cols; ++x)
	{
		// if there is an exterior part in the interior we have to move the bottom side of the rect a bit to the top
		if (sub.at<unsigned char>(y, x) == 0)
		{
			returnVal = false;
			++cBottom;
		}
	}

	for (y = 0, x = 0; y < sub.rows; ++y)
	{
		// if there is an exterior part in the interior
		if (sub.at<unsigned char>(y, x) == 0)
		{
			returnVal = false;
			++cLeft;
		}
	}

	for (x = sub.cols - 1, y = 0; y < sub.rows; ++y)
	{
		// if there is an exterior part in the interior
		if (sub.at<unsigned char>(y, x) == 0)
		{
			returnVal = false;
			++cRight;
		}
	}

	// that part is ugly and maybe not correct, didn't check whether all possible combinations are handled. Check that one please. The idea is to set `top = 1` iff it's better to reduce the rect at the top than anywhere else.
	if (cTop > cBottom)
	{
		if (cTop > cLeft)
			if (cTop > cRight)
				top = 1;
	}
	else
		if (cBottom > cLeft)
			if (cBottom > cRight)
				bottom = 1;

	if (cLeft >= cRight)
	{
		if (cLeft >= cBottom)
			if (cLeft >= cTop)
				left = 1;
	}
	else
		if (cRight >= cTop)
			if (cRight >= cBottom)
				right = 1;



	return returnVal;
}