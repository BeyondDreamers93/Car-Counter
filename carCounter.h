#pragma once
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

class carCounter {
private:
	int carCount = 0;
public:
	bool countCars(float ReferencePt, float lineReferencePtY);
};
