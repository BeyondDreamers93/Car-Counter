#include "ObjectDetector.h"
#include <vector>
#include "Visualiser.h"
#include "carCounter.h"


void objectDetector::detector(std::string classifierName, std::string videoPath) {
	cv::VideoCapture cap(videoPath);
	cv::Mat frame;
	cv::Mat grayscale_frame;
	cv::CascadeClassifier classifier(classifierName);
	std::vector<cv::Rect> boundingBox;
	visualiser visualiser;
	carCounter carCounterObj;
	int carCount=0;
	if (!cap.isOpened()) {
	cout << "Video not captured" << endl;
	return;
	}

	
	while (cap.isOpened())
	{
		if (cap.read(frame))  
		{
			
			//const int cropSize = 128;

			cv::cvtColor(frame, grayscale_frame, cv::COLOR_BGR2GRAY);
			const int offsetW = 210;
			const int offsetH = 150;
			Point CropImageTopLeftPt;
			CropImageTopLeftPt.x = (grayscale_frame.cols-100) / 2;
			CropImageTopLeftPt.y = (grayscale_frame.rows-60) / 2;
			const Rect roi(CropImageTopLeftPt.x, CropImageTopLeftPt.y, offsetW, offsetH);
			cv::Mat grayscale_frame_roi = grayscale_frame(roi).clone();
			classifier.detectMultiScale(grayscale_frame_roi, boundingBox, 1.1, 3, 0 | CASCADE_FIND_BIGGEST_OBJECT | CASCADE_SCALE_IMAGE, Size(30, 30), Size(200, 200));
			Point LineStartPt;
			LineStartPt.x = CropImageTopLeftPt.x;
			LineStartPt.y = CropImageTopLeftPt.y + 65;

			Point lineEndPt;
			lineEndPt.x = CropImageTopLeftPt.x + offsetW;
			lineEndPt.y = LineStartPt.y;
			
			cv::line(frame, LineStartPt, lineEndPt, cv::Scalar(255, 0, 0), 1);
			std::vector<cv::Point> centerPtVector = visualiser.visualiseBoundingBox(boundingBox, frame, CropImageTopLeftPt, carCount);
			for (std::vector<cv::Point>::iterator it = centerPtVector.begin(); it != centerPtVector.end(); ++it) {
				float CarCenterPtY = it->y;
				
				if (carCounterObj.countCars(CarCenterPtY, LineStartPt.y))
				{
					carCount++;
					CarCenterPtY = grayscale_frame.rows;
				}
			}


		

		}
		if (waitKey(30) == 13)
		{
			break;
		}
	}


	cap.release();
	destroyAllWindows();

	
	return;
}