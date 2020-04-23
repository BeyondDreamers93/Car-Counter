#pragma once
#include <stdio.h>
#include <opencv2/opencv.hpp>


using namespace cv;

class visualiser
{

public:
	std::vector<cv::Point> visualiseBoundingBox(std::vector<cv::Rect> boundingBox, Mat frame, Point shiftPt,int count);
};