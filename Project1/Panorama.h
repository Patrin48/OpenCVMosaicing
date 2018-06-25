#pragma once
#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport) 
#else
#define MATHFUNCSDLL_API __declspec(dllimport) 
#endif
#include <iostream>
#include <thread>
#include <array>
#include <string>
#include <Windows.h>
#include <stack>
#include <opencv2\opencv.hpp>
#include <opencv2\stitching.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <future>
#include <condition_variable>
using namespace std;
using namespace cv;
namespace MakePanorama {
	class Tasks {
	private:
		int task_id;
		array<Mat, 2> images;
	public:
		int GetTaskId();
		Tasks(int _task_id);
		Tasks();
		~Tasks();
		bool SetImagesArray(array<Mat, 2> tempImages);
		Mat getImage(Stitcher::Mode _mode);
	};
	class Worker {
	private:
		vector<array<Mat, 2>>images;
		string videopath;
	public:
		Worker(string _videopath);
		~Worker();
		bool splitter();
		vector<array<Mat, 2>> getImages();

	};
	class GetPanorama {
	private:
		
		map<bool, Mat> result;
	public:
		GetPanorama();
		map<bool, Mat> getResult(string filepath);
		
	};
}