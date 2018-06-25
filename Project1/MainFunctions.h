#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

class MainFunctions {
public:
	static cv::Mat cropBlackBoundaries(cv::Mat &image);
	static std::wstring s2ws(const std::string& s);
	static bool checkInteriorExterior(const cv::Mat&mask, const cv::Rect&interiorBB, int&top, int&bottom, int&left, int&right);
};