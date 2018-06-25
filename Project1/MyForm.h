#pragma once
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


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace cv;

	std::vector<Mat> imgs;
	std::string videoFilePath;
	char *fileNameToSave;
	std::string fileNameToSave_ = "";

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	bool sortX(cv::Point a, cv::Point b)
	{
		bool ret = false;
		if (a.x == a.x)
			if (b.x == b.x)
				ret = a.x < b.x;

		return ret;
	}

	bool sortY(cv::Point a, cv::Point b)
	{
		bool ret = false;
		if (a.y == a.y)
			if (b.y == b.y)
				ret = a.y < b.y;


		return ret;
	}
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			resources->ApplyResources(this->openFileDialog1, L"openFileDialog1");
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			resources->ApplyResources(this->comboBox1, L"comboBox1");
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				resources->GetString(L"comboBox1.Items"), resources->GetString(L"comboBox1.Items1"),
					resources->GetString(L"comboBox1.Items2")
			});
			this->comboBox1->Name = L"comboBox1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// progressBar1
			// 
			resources->ApplyResources(this->progressBar1, L"progressBar1");
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// checkBox1
			// 
			resources->ApplyResources(this->checkBox1, L"checkBox1");
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// folderBrowserDialog1
			// 
			resources->ApplyResources(this->folderBrowserDialog1, L"folderBrowserDialog1");
			this->folderBrowserDialog1->ShowNewFolderButton = false;
			// 
			// MyForm
			// 
			this->AcceptButton = this->button2;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::Control;
			resources->ApplyResources(this, L"$this");
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Opacity = 0.95;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		void SetProgressBarText()
		{

			this->label3->Text = "Extracting frames...";
			this->progressBar1->Visible = true;
		}
		void DeleteProgressBarText()
		{

			this->label3->Text = "Extraction done!..";
			this->progressBar1->Visible = false;
			this->label3->Visible = false;
			this->button2->Enabled = true;
		}
		void extract_frames_thread()
		{
			try {
				this->Invoke(gcnew Action(this, &MyForm::SetProgressBarText));
				std::vector<int> compression_params;
				compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
				compression_params.push_back(100);
				//open the video file
				VideoCapture cap(videoFilePath); // open the video file
												 //this->label1->Text += " FPS: " + Convert::ToString(int(cap.get(CV_CAP_PROP_FPS) + 0.5)) + " Video resolution: " + Convert::ToString(cap.get(CV_CAP_PROP_FRAME_HEIGHT)) + "*" + Convert::ToString(cap.get(CV_CAP_PROP_FRAME_WIDTH));
				float every_frame = floor(cap.get(CV_CAP_PROP_FPS)*cap.get(CV_CAP_PROP_FRAME_COUNT) / 100);
				if (!cap.isOpened())  // check if we succeeded
					CV_Error(CV_StsError, "Cannot open video file!");
				for (unsigned int frameNum = 0; frameNum < cap.get(CV_CAP_PROP_FRAME_COUNT); frameNum++)
				{
					Mat frame;
					cap >> frame;
					if (frameNum % static_cast<int>(every_frame) == 0)
					{
						imgs.push_back(frame);
					}
				}
				this->Invoke(gcnew Action(this, &MyForm::DeleteProgressBarText));
				Thread::Sleep(100);
			}
			catch (cv::Exception& e) {
				MessageBox::Show("Something wrong with extracting frames from video!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				exit(0);
			}
		}
		void extract_frames(const std::string &videoFilePath) {
			try {
				std::vector<int> compression_params;
				compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
				compression_params.push_back(100);
				//open the video file
				VideoCapture cap(videoFilePath); // open the video file
				this->label1->Text += " FPS: " + Convert::ToString(int(cap.get(CV_CAP_PROP_FPS) + 0.5)) + " Video resolution: " + Convert::ToString(cap.get(CV_CAP_PROP_FRAME_HEIGHT)) + "*" + Convert::ToString(cap.get(CV_CAP_PROP_FRAME_WIDTH));
				float time = floor(cap.get(CV_CAP_PROP_FPS)*cap.get(CV_CAP_PROP_FRAME_COUNT) / 100);
				if (!cap.isOpened())  // check if we succeeded
					CV_Error(CV_StsError, "Cannot open video file!");
				//cap.get(CV_CAP_PROP_FRAME_COUNT) contains the number of frames in the video;
				for (unsigned int frameNum = 0; frameNum < cap.get(CV_CAP_PROP_FRAME_COUNT); frameNum++)
				{
					Mat frame;
					cap >> frame; // get the next frame from video
					if (frameNum % static_cast<int>(time) == 0)
					{
						imgs.push_back(frame);
					}
				}
			}
			catch (cv::Exception& e) {
				MessageBox::Show("Something wrong with extracting frames from video!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				exit(0);
			}

		}
		/*std::wstring s2ws(const std::string& s)
		{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
		}*/
		//bool checkInteriorExterior(const cv::Mat&mask, const cv::Rect&interiorBB, int&top, int&bottom, int&left, int&right)
		//{

		//	bool returnVal = true;

		//	cv::Mat sub = mask(interiorBB);

		//	unsigned int x = 0;
		//	unsigned int y = 0;

		//	unsigned int cTop = 0; // top row
		//	unsigned int cBottom = 0; // bottom row
		//	unsigned int cLeft = 0; // left column
		//	unsigned int cRight = 0; // right column
		//							  and choose that side for reduction where mose exterior pixels occured (that's the heuristic)

		//	for (y = 0, x = 0; x < sub.cols; ++x)
		//	{
		//		 if there is an exterior part in the interior we have to move the top side of the rect a bit to the bottom
		//		if (sub.at<unsigned char>(y, x) == 0)
		//		{
		//			returnVal = false;
		//			++cTop;
		//		}
		//	}

		//	for (y = sub.rows - 1, x = 0; x < sub.cols; ++x)
		//	{
		//		 if there is an exterior part in the interior we have to move the bottom side of the rect a bit to the top
		//		if (sub.at<unsigned char>(y, x) == 0)
		//		{
		//			returnVal = false;
		//			++cBottom;
		//		}
		//	}

		//	for (y = 0, x = 0; y < sub.rows; ++y)
		//	{
		//		 if there is an exterior part in the interior
		//		if (sub.at<unsigned char>(y, x) == 0)
		//		{
		//			returnVal = false;
		//			++cLeft;
		//		}
		//	}

		//	for (x = sub.cols - 1, y = 0; y < sub.rows; ++y)
		//	{
		//		 if there is an exterior part in the interior
		//		if (sub.at<unsigned char>(y, x) == 0)
		//		{
		//			returnVal = false;
		//			++cRight;
		//		}
		//	}

		//	 that part is ugly and maybe not correct, didn't check whether all possible combinations are handled. Check that one please. The idea is to set `top = 1` iff it's better to reduce the rect at the top than anywhere else.
		//	if (cTop > cBottom)
		//	{
		//		if (cTop > cLeft)
		//			if (cTop > cRight)
		//				top = 1;
		//	}
		//	else
		//		if (cBottom > cLeft)
		//			if (cBottom > cRight)
		//				bottom = 1;

		//	if (cLeft >= cRight)
		//	{
		//		if (cLeft >= cBottom)
		//			if (cLeft >= cTop)
		//				left = 1;
		//	}
		//	else
		//		if (cRight >= cTop)
		//			if (cRight >= cBottom)
		//				right = 1;



		//	return returnVal;
		//}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *fileName = new char[openFileDialog1->FileName->Length];
			for (unsigned int i = 0; i < openFileDialog1->FileName->Length; i++)
			{
				fileName[i] = (char)openFileDialog1->FileName[i];
			}
			std::string tmp = "";
			for (unsigned int i = 0; i < openFileDialog1->FileName->Length; i++)
			{
				tmp += openFileDialog1->FileName[i];
			}
			videoFilePath = tmp;
			label1->Text = System::Convert::ToString(openFileDialog1->FileName);
			ThreadStart^ myThreadDelegate = gcnew ThreadStart(this, &MyForm::extract_frames_thread);
			Thread^ thread1 = gcnew Thread(myThreadDelegate);
			thread1->Start();
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkBox1->Checked)
		{
			if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				for (unsigned int i = 0; i <folderBrowserDialog1->SelectedPath->Length; i++)
				{
					fileNameToSave_ += folderBrowserDialog1->SelectedPath->default[i];
				}
			}
			
			double duration;
			Mat pano;
			std::string s = "\"" + videoFilePath + "\" "+ fileNameToSave_ +"";
			std::string argumenst = "";
			std::clock_t start;
			std::wstring stemp = MainFunctions::s2ws(s);
			LPCWSTR result = stemp.c_str();
			start = std::clock();
			ShellExecute(NULL, L"open", L"PanoramaMultiThreading.exe", result, NULL, SW_SHOWMINIMIZED);
			while (pano.empty())
			{
				pano = imread(fileNameToSave_+"\\result.jpg", CV_LOAD_IMAGE_COLOR);
			}
			Mat input = pano;
			Mat gray;
			cvtColor(input, gray, CV_BGR2GRAY);
			Mat mask = gray > 0;
			std::vector<std::vector<cv::Point> > contours;
			std::vector<cv::Vec4i> hierarchy;
			findContours(mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, cv::Point(0, 0));
			cv::Mat contourImage = cv::Mat::zeros(input.size(), CV_8UC3);
			unsigned int maxSize = 0;
			unsigned int id = 0;
			for (unsigned int i = 0; i < contours.size(); ++i)
			{
				if (contours.at(i).size() > maxSize)
				{
					maxSize = contours.at(i).size();
					id = i;
				}
			}
			cv::Mat contourMask = cv::Mat::zeros(input.size(), CV_8UC1);
			drawContours(contourMask, contours, id, cv::Scalar(255), -1, 8, hierarchy, 0, cv::Point());
			std::vector<cv::Point> cSortedX = contours.at(id);
			std::sort(cSortedX.begin(), cSortedX.end(), sortX);
			std::vector<cv::Point> cSortedY = contours.at(id);
			std::sort(cSortedY.begin(), cSortedY.end(), sortY);
			unsigned int minXId = 0;
			unsigned int maxXId = cSortedX.size() - 1;
			unsigned int minYId = 0;
			unsigned int maxYId = cSortedY.size() - 1;
			Rect interiorBB;
			while ((minXId < maxXId) && (minYId < maxYId))
			{
				cv::Point min(cSortedX[minXId].x, cSortedY[minYId].y);
				cv::Point max(cSortedX[maxXId].x, cSortedY[maxYId].y);
				interiorBB = cv::Rect(min.x, min.y, max.x - min.x, max.y - min.y);
				int ocTop = 0;
				int ocBottom = 0;
				int ocLeft = 0;
				int ocRight = 0;
				bool finished = MainFunctions::checkInteriorExterior(contourMask, interiorBB, ocTop, ocBottom, ocLeft, ocRight);
				if (finished)
				{
					break;
				}
				if (ocLeft)++minXId;
				if (ocRight) --maxXId;

				if (ocTop) ++minYId;
				if (ocBottom)--maxYId;
			}
			Mat mask2 = cv::Mat::zeros(input.rows, input.cols, CV_8UC1);
			rectangle(mask2, interiorBB, cv::Scalar(255), -1);
			Mat maskedImage;
			input.copyTo(maskedImage);
			for (unsigned int y = 0; y < maskedImage.rows; ++y)
				for (unsigned int x = 0; x < maskedImage.cols; ++x)
				{
					maskedImage.at<cv::Vec3b>(y, x) = 1;
				}
			input.copyTo(maskedImage, mask2);
			maskedImage = MainFunctions::cropBlackBoundaries(maskedImage);
			imwrite("Panorama(multithreading).png", maskedImage);
			cvNamedWindow("Panorama(multithreading)", CV_WINDOW_AUTOSIZE);
			imshow("Panorama(multithreading)", maskedImage);
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			MessageBox::Show("Stitching time (multithreading mode) is: " + Convert::ToString(duration) + " sec.\n" + "Picture resolution: " + Convert::ToString(maskedImage.size().width) + "*" + Convert::ToString(maskedImage.size().height) + " pixels.", "Mosaiching done", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			Mat pano;
			double duration;
#pragma region Stitching Image
			std::clock_t start;
			start = std::clock();
			Stitcher stitcher = Stitcher::createDefault(false);
			if (this->comboBox1->SelectedIndex == 0)
			{
				stitcher.setRegistrationResol(0.2);
				stitcher.setSeamEstimationResol(0.1);
				stitcher.setCompositingResol(0.4);
				stitcher.setPanoConfidenceThresh(1);
				stitcher.setSeamFinder(new detail::GraphCutSeamFinder(detail::GraphCutSeamFinderBase::COST_COLOR_GRAD));
				stitcher.setBlender(detail::Blender::createDefault(detail::Blender::MULTI_BAND, false));
				stitcher.setExposureCompensator(detail::ExposureCompensator::createDefault(detail::ExposureCompensator::GAIN_BLOCKS));
				stitcher.setWaveCorrection(true);
				stitcher.setWaveCorrectKind(detail::WAVE_CORRECT_HORIZ);
				stitcher.setFeaturesMatcher(
					new detail::BestOf2NearestMatcher(false, 0.3, 6, 6));
				stitcher.setBundleAdjuster(new detail::BundleAdjusterRay());
			}
			else if (this->comboBox1->SelectedIndex == 1)
			{
				stitcher.setRegistrationResol(0.6);
				stitcher.setSeamEstimationResol(0.4);
				stitcher.setCompositingResol(0.8);
				stitcher.setPanoConfidenceThresh(1);
				stitcher.setSeamFinder(new detail::GraphCutSeamFinder(detail::GraphCutSeamFinderBase::COST_COLOR_GRAD));
				stitcher.setBlender(detail::Blender::createDefault(detail::Blender::MULTI_BAND, false));
				stitcher.setExposureCompensator(detail::ExposureCompensator::createDefault(detail::ExposureCompensator::GAIN_BLOCKS));
				stitcher.setWaveCorrection(true);
				stitcher.setWaveCorrectKind(detail::WAVE_CORRECT_HORIZ);
				stitcher.setFeaturesMatcher(
					new detail::BestOf2NearestMatcher(false, 0.3, 6, 6));
				stitcher.setBundleAdjuster(new detail::BundleAdjusterRay());
			}
			else if (this->comboBox1->SelectedIndex == 2)
			{
				stitcher.setRegistrationResol(0.8);
				stitcher.setSeamEstimationResol(0.6);
				stitcher.setCompositingResol(1);
				stitcher.setPanoConfidenceThresh(1);
				stitcher.setSeamFinder(new detail::GraphCutSeamFinder(detail::GraphCutSeamFinderBase::COST_COLOR_GRAD));
				stitcher.setBlender(detail::Blender::createDefault(detail::Blender::MULTI_BAND, false));
				stitcher.setExposureCompensator(detail::ExposureCompensator::createDefault(detail::ExposureCompensator::GAIN_BLOCKS));
				stitcher.setWaveCorrection(true);
				stitcher.setWaveCorrectKind(detail::WAVE_CORRECT_HORIZ);
				stitcher.setFeaturesMatcher(
					new detail::BestOf2NearestMatcher(false, 0.3, 6, 6));
				stitcher.setBundleAdjuster(new detail::BundleAdjusterRay());
			}
			else if (this->comboBox1->SelectedIndex == 1)
			{
				stitcher.setRegistrationResol(1);
				stitcher.setSeamEstimationResol(0.8);
				stitcher.setCompositingResol(1);
				stitcher.setPanoConfidenceThresh(1);
				stitcher.setSeamFinder(new detail::GraphCutSeamFinder(detail::GraphCutSeamFinderBase::COST_COLOR_GRAD));
				stitcher.setBlender(detail::Blender::createDefault(detail::Blender::MULTI_BAND, false));
				stitcher.setExposureCompensator(detail::ExposureCompensator::createDefault(detail::ExposureCompensator::GAIN_BLOCKS));
				stitcher.setWaveCorrection(true);
				stitcher.setWaveCorrectKind(detail::WAVE_CORRECT_HORIZ);
				stitcher.setFeaturesMatcher(
					new detail::BestOf2NearestMatcher(false, 0.3, 6, 6));
				stitcher.setBundleAdjuster(new detail::BundleAdjusterRay());
			}
			Stitcher::Status status = stitcher.stitch(imgs, pano);
			if (status != Stitcher::OK)
			{
				MessageBox::Show("Cannot stitch images!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				exit(0);
			}
#pragma endregion
			imwrite("raw_picture.png", pano);
			imshow("Panorama", pano);
			Mat input = pano;
			Mat gray;
			cvtColor(input, gray, CV_BGR2GRAY);
			Mat mask = gray > 0;
			std::vector<std::vector<cv::Point> > contours;
			std::vector<cv::Vec4i> hierarchy;
			findContours(mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, cv::Point(0, 0));
			cv::Mat contourImage = cv::Mat::zeros(input.size(), CV_8UC3);
			unsigned int maxSize = 0;
			unsigned int id = 0;
			for (unsigned int i = 0; i < contours.size(); ++i)
			{
				if (contours.at(i).size() > maxSize)
				{
					maxSize = contours.at(i).size();
					id = i;
				}
			}
			cv::Mat contourMask = cv::Mat::zeros(input.size(), CV_8UC1);
			drawContours(contourMask, contours, id, cv::Scalar(255), -1, 8, hierarchy, 0, cv::Point());
			std::vector<cv::Point> cSortedX = contours.at(id);
			std::sort(cSortedX.begin(), cSortedX.end(), sortX);
			std::vector<cv::Point> cSortedY = contours.at(id);
			std::sort(cSortedY.begin(), cSortedY.end(), sortY);
			unsigned int minXId = 0;
			unsigned int maxXId = cSortedX.size() - 1;
			unsigned int minYId = 0;
			unsigned int maxYId = cSortedY.size() - 1;
			Rect interiorBB;
			while ((minXId < maxXId) && (minYId < maxYId))
			{
				cv::Point min(cSortedX[minXId].x, cSortedY[minYId].y);
				cv::Point max(cSortedX[maxXId].x, cSortedY[maxYId].y);
				interiorBB = cv::Rect(min.x, min.y, max.x - min.x, max.y - min.y);
				int ocTop = 0;
				int ocBottom = 0;
				int ocLeft = 0;
				int ocRight = 0;
				bool finished = MainFunctions::checkInteriorExterior(contourMask, interiorBB, ocTop, ocBottom, ocLeft, ocRight);
				if (finished)
				{
					break;
				}
				if (ocLeft)++minXId;
				if (ocRight) --maxXId;

				if (ocTop) ++minYId;
				if (ocBottom)--maxYId;
			}
			Mat mask2 = cv::Mat::zeros(input.rows, input.cols, CV_8UC1);
			rectangle(mask2, interiorBB, cv::Scalar(255), -1);
			Mat maskedImage;
			input.copyTo(maskedImage);
			for (unsigned int y = 0; y < maskedImage.rows; ++y)
				for (unsigned int x = 0; x < maskedImage.cols; ++x)
				{
					maskedImage.at<cv::Vec3b>(y, x) = 1;
				}
			input.copyTo(maskedImage, mask2);
			maskedImage = MainFunctions::cropBlackBoundaries(maskedImage);
			imwrite("Panorama.png", maskedImage);
			cvNamedWindow("Panorama", CV_WINDOW_AUTOSIZE);
			imshow("Panorama", maskedImage);
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			MessageBox::Show("Stitching time is: " + Convert::ToString(duration) + " sec.\n" + "Picture resolution: " + Convert::ToString(maskedImage.size().width) + "*" + Convert::ToString(maskedImage.size().height) + " pixels.", "Mosaiching done", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkBox1->Checked)
		{
			this->comboBox1->Enabled = false;
		}
		else if (!this->checkBox1->Checked)
		{
			this->comboBox1->Enabled = true;
		}
	}
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		remove((fileNameToSave_+"\\result.jpg").c_str());
		//clear our garbage
		//
	}

	};
}
