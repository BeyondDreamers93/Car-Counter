#include "ObjectDetector.h"
#include "Visualiser.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv) {
	objectDetector FaceDetector;
	if (argc != 3) {
		printf("Two arguments are required\n");
		printf("Usage: CarCounter.exe <Classifier_Path> <Video_Path>");
		return -1;
	}
	else {
		printf("Press 'Enter' Key to close the video\n");
		std::string classifierPath = argv[1];
		std::string videoPath = argv[2];
		FaceDetector.detector(classifierPath, videoPath);
	}
	return 0;
}