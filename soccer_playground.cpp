#include <opencv2/opencv.hpp>

double feildLength = 9;
double feildWidth = 6;
double goalDepth = 0.6;
double goalwidth = 2.6;
double goalAreaLength = 1;
double goalAreaWidth = 3;
double penaltyMarkDistance = 1.5;
double centreCircleDiameter = 1.5;
double borderStripWidth = 1;
double penaltyAreaLength = 2;
double penaltyAreaWidth = 5;

int contractPixel = 105;

int windowWidth = (feildLength + borderStripWidth * 2) * contractPixel;
int windowLength = (feildWidth + borderStripWidth * 2)  * contractPixel;

struct MainRectangle {
    cv::Point topLeft;
    cv::Point bottomRight;
    cv::Scalar color;
    int thickness;

    // Constructor to initialize the members
    MainRectangle() : 
        topLeft(borderStripWidth * contractPixel, borderStripWidth * contractPixel),
        bottomRight((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + feildWidth) * contractPixel),
        color(255, 255, 255),  // White color
        thickness(1) {}
};

struct leftGoal {
    cv::Point topLeft;
    cv::Point bottomRight;
    cv::Scalar color;
    int thickness;

    // Constructor to initialize the members
    leftGoal() :
        topLeft((borderStripWidth - goalDepth) * contractPixel, (borderStripWidth + (feildWidth - goalwidth) / 2) * contractPixel),
        bottomRight(borderStripWidth * contractPixel, (borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth)  * contractPixel),
        color(255, 255, 0),
        thickness(1) {}
};

struct rightGoal {
    cv::Point topLeft;
    cv::Point bottomRight;
    cv::Scalar color;
    int thickness;

    // Constructor to initialize the members
    rightGoal() :
        topLeft((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + (feildWidth - goalwidth) / 2) * contractPixel),
        bottomRight((borderStripWidth + feildLength + goalDepth) * contractPixel, (borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth)  * contractPixel),
        color(0, 255, 255),
        thickness(1) {}
};

struct leftPenaltyArea {
    cv::Point topLeft;
    cv::Point bottomRight;
    cv::Scalar color;
    int thickness;

    // Constructor to initialize the members
    leftPenaltyArea() :
        topLeft(borderStripWidth * contractPixel, (borderStripWidth + (feildWidth - penaltyAreaWidth) / 2) * contractPixel),
        bottomRight((borderStripWidth + penaltyAreaLength) * contractPixel, (borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth)  * contractPixel),
        color(255, 255, 255),
        thickness(1) {}
};

struct rightPenaltyArea {
    cv::Point topLeft;
    cv::Point bottomRight;
    cv::Scalar color;
    int thickness;

    // Constructor to initialize the members
    rightPenaltyArea() :
        topLeft(((borderStripWidth + feildLength) - penaltyAreaLength) * contractPixel, (borderStripWidth + (feildWidth - penaltyAreaWidth) / 2) * contractPixel),
        bottomRight((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth)  * contractPixel),
        color(255, 255, 255),
        thickness(1) {}
};

struct leftGoalArea {
    cv::Point topLeft;
    cv::Point bottomRight;
    cv::Scalar color;
    int thickness;

    // Constructor to initialize the members
    leftGoalArea() :
        topLeft(borderStripWidth * contractPixel, (borderStripWidth + (feildWidth - goalAreaWidth) / 2) * contractPixel),
        bottomRight((borderStripWidth + goalAreaLength) * contractPixel, (borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth)  * contractPixel),
        color(255, 255, 255),
        thickness(1) {}
};

struct rightGoalArea {
    cv::Point topLeft;
    cv::Point bottomRight;
    cv::Scalar color;
    int thickness;

    // Constructor to initialize the members
    rightGoalArea() :
        topLeft(((borderStripWidth + feildLength) - goalAreaLength) * contractPixel, (borderStripWidth + (feildWidth - goalAreaWidth) / 2) * contractPixel),
        bottomRight((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth)  * contractPixel),
        color(255, 255, 255),
        thickness(1) {}
};

struct midLine {
    cv::Point startPoint;
    cv::Point endPoint;
    cv::Scalar color;
    int thickness;

    midLine() :
        startPoint((borderStripWidth + (feildLength / 2)) * contractPixel, borderStripWidth * contractPixel),
        endPoint((borderStripWidth + (feildLength / 2)) * contractPixel, (borderStripWidth + feildWidth) * contractPixel),
        color(255, 255, 255),
        thickness(1) {}
};

int main() {
    // Create an RGB matrix (for example, a green image)

    cv::Mat rgbMatrix(windowLength, windowWidth, CV_8UC3, cv::Scalar(9, 16, 9));  // Set the green channel to 255
    MainRectangle MainRectangle;
    leftGoal leftGoal;
    rightGoal rightGoal;
    leftPenaltyArea leftPenaltyArea;
    rightPenaltyArea rightPenaltyArea;
    leftGoalArea leftGoalArea;
    rightGoalArea rightGoalArea;
    midLine midLine;

    // Draw the rectangle on the RGB matrix
    cv::rectangle(rgbMatrix, leftGoal.topLeft, leftGoal.bottomRight, leftGoal.color, leftGoal.thickness);
    cv::rectangle(rgbMatrix, rightGoal.topLeft, rightGoal.bottomRight, rightGoal.color, rightGoal.thickness);
    cv::rectangle(rgbMatrix, leftPenaltyArea.topLeft, leftPenaltyArea.bottomRight, leftPenaltyArea.color, leftPenaltyArea.thickness);
    cv::rectangle(rgbMatrix, rightPenaltyArea.topLeft, rightPenaltyArea.bottomRight, rightPenaltyArea.color, rightPenaltyArea.thickness);
    cv::rectangle(rgbMatrix, leftGoalArea.topLeft, leftGoalArea.bottomRight, leftGoalArea.color, leftGoalArea.thickness);
    cv::rectangle(rgbMatrix, rightGoalArea.topLeft, rightGoalArea.bottomRight, rightGoalArea.color, rightGoalArea.thickness);
    cv::line(rgbMatrix, midLine.startPoint, midLine.endPoint, midLine.color, midLine.thickness);
    cv::rectangle(rgbMatrix, MainRectangle.topLeft, MainRectangle.bottomRight, MainRectangle.color, MainRectangle.thickness);



    // Display the RGB matrix with the rectangle in a window
    cv::imshow("RGB Matrix with Rectangle", rgbMatrix);

    // Wait for a key event and then close the window
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}