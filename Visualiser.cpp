#include "Visualiser.h"



std::vector<cv::Point> visualiser::visualiseBoundingBox(std::vector<cv::Rect> boundingBox, Mat frame, Point shiftPt, int Count)
{
	std::vector<cv::Point> centerPoints;
	cv::String carCount = "Incoming Cars:" + std::to_string(Count);
	Point TextPt;
	TextPt.x = 30;
	TextPt.y = frame.rows-30;
	for (std::vector<cv::Rect>::iterator it = boundingBox.begin(); it != boundingBox.end(); ++it) {

		it->x = it->x + shiftPt.x;
		it->y = it->y + shiftPt.y;
		cv::rectangle(frame, *it, cv::Scalar(0, 0, 255));	
		Point centerPt;
		centerPt.x = it->x + ((it->width) / 2);
		centerPt.y = it->y + ((it->height) / 2);
		cv::circle(frame, centerPt, 3, cv::Scalar(0, 255, 0), -1);
		centerPoints.push_back(centerPt);
	}
	double fontScale = 1;
	int fontType = 2;
	int thickness = 2;
	cv::putText(frame, carCount, TextPt, fontType, fontScale, cv::Scalar(0, 255, 255), thickness);
	imshow("Classifier", frame);
	return centerPoints;
}