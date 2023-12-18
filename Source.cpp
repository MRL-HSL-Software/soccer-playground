//   |--------second TASK MRL--------|
//   |*******************************|
//   |****----soccer field-------****|
//   |*******************************|
//=======================================
//  <<<<< !!!!if ypu wants to change parameters you must change meter to pixel !!!! >>>>>
//  <<< for change that you can use the ***change.cpp code *** ~/home/Decstope/MRL/soccerField >>>
// start to creat :) >>>>

#include <opencv2/opencv.hpp>
using namespace cv;

// parameters 
const double fieldLength = 1000; 
const double fieldWidth = 600;
const double goalDepth = 50;
const double goalWidth = 200;
const double goalHeight = 100;
const double goalAreaLength = 150;
const double goalAreaWidth = 400;
const double penaltyMarkDistance = 300;
const double centreCircleDiameter = 200;
const double borderStripWidth = 50;
const double penaltyAreaLength = 300;
const double penaltyAreaWidth = 500;
const double fieldPadding = 100;
const double middleLine = fieldLength / 2;

//colors 
const Scalar red = Scalar(0, 0, 255); // Right goal 
const Scalar yellow = Scalar(0, 255, 255); // left goal
const Scalar white = Scalar(255, 255, 255); // lines
const Scalar black = Scalar(0, 0, 0); // background

// line size 
const int lineSize = 1; 

// |---------------------<<Main>>-----------------------|

int main() {
	// Create padding and background 
	Mat image = Mat(fieldWidth + 2 * fieldPadding, fieldLength + 2 * fieldPadding, CV_8UC3, black);

	// Draw field outline a rectangle 
	rectangle(image, Point(fieldPadding, fieldPadding), Point(fieldLength + fieldPadding, fieldWidth + fieldPadding), white, lineSize);

	// Draw middle line
	line(image, Point(middleLine + fieldPadding, fieldPadding), Point(middleLine + fieldPadding, fieldWidth + fieldPadding), white, lineSize);

	// Draw centre circle
	circle(image, Point(middleLine + fieldPadding, fieldWidth / 2 + fieldPadding), centreCircleDiameter / 2, white, lineSize);

	// Draw left goal 
	rectangle(image, Point(fieldPadding - goalDepth, fieldWidth / 2 - goalWidth / 2 + fieldPadding), Point(fieldPadding, fieldWidth / 2 + goalWidth / 2 + fieldPadding), red, lineSize);

	// Draw left goal area
	rectangle(image, Point(fieldPadding, fieldWidth / 2 - goalAreaWidth / 2 + fieldPadding), Point(fieldPadding + goalAreaLength, fieldWidth / 2 + goalAreaWidth / 2 + fieldPadding), white, lineSize);

	// Draw left penalty area
	rectangle(image, Point(fieldPadding, fieldWidth / 2 - penaltyAreaWidth / 2 + fieldPadding), Point(fieldPadding + penaltyAreaLength, fieldWidth / 2 + penaltyAreaWidth / 2 + fieldPadding), white, lineSize);

	// Draw left penalty mark
	circle(image, Point(fieldPadding + penaltyMarkDistance , fieldWidth / 2 + fieldPadding), 5, white, lineSize);

	// Draw right goal
	rectangle(image, Point(fieldLength + fieldPadding, fieldWidth / 2 - goalWidth / 2 + fieldPadding), Point(fieldLength + fieldPadding + goalDepth, fieldWidth / 2 + goalWidth / 2 + fieldPadding), yellow, lineSize);

	// Draw right goal area
	rectangle(image, Point(fieldLength + fieldPadding - goalAreaLength, fieldWidth / 2 - goalAreaWidth / 2 + fieldPadding), Point(fieldLength + fieldPadding, fieldWidth / 2 + goalAreaWidth / 2 + fieldPadding), white, lineSize);

	// Draw right penalty area
	rectangle(image, Point(fieldLength + fieldPadding - penaltyAreaLength, fieldWidth / 2 - penaltyAreaWidth / 2 + fieldPadding), Point(fieldLength + fieldPadding, fieldWidth / 2 + penaltyAreaWidth / 2 + fieldPadding), white, lineSize);

	// Draw right penalty mark 
	circle(image, Point(fieldLength + fieldPadding - penaltyMarkDistance, fieldWidth / 2 + fieldPadding), 5, white, lineSize);

	// Show the image in a window
	imshow("Soccer Field", image);

	// Wait for a key press
	waitKey(0);

	// Return 0
	return 0;
}
