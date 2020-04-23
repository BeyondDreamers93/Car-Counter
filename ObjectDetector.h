#pragma once

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class objectDetector {

public:
	void detector(std::string classifierName, std::string videoPath);
};
