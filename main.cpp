#include <opencv2/opencv.hpp>
using namespace cv;

int Pixel = 100;
double M = Pixel;

// football-playground variables
double feildLength = 9 * M;
double feildWidth = 6 * M;
double goalDepth = 0.6 * M;
double goalwidth = 2.6 * M;
double goalAreaLength = 1 * M;
double goalAreaWidth = 3 * M;
double penaltyMarkDistance = 1.5 * M;
double centreCircleDiameter = 1.5 * M;
double borderStripWidth = 1 * M;
double penaltyAreaLength = 2 * M;
double penaltyAreaWidth = 5 * M;

// window variables
int windowWidth = (feildLength + borderStripWidth * 2);
int windowLength = (feildWidth + borderStripWidth * 2);

struct MainRectangle {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    // initialize the members
    MainRectangle() : 
        topLeft(borderStripWidth, borderStripWidth ),
        bottomRight((borderStripWidth + feildLength), (borderStripWidth + feildWidth)),
        color(255, 255, 255),
        thickness(1) {}
};

struct leftGoal {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    leftGoal() :
        topLeft((borderStripWidth - goalDepth), (borderStripWidth + (feildWidth - goalwidth) / 2) ),
        bottomRight(borderStripWidth , (borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth)),
        color(255, 255, 0),
        thickness(1) {}
};

struct rightGoal {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    rightGoal() :
        topLeft((borderStripWidth + feildLength) , (borderStripWidth + (feildWidth - goalwidth) / 2)),
        bottomRight((borderStripWidth + feildLength + goalDepth), (borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth)),
        color(0, 0, 255),
        thickness(1) {}
};

    struct leftPenaltyArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    leftPenaltyArea() :
        topLeft(borderStripWidth , (borderStripWidth + (feildWidth - penaltyAreaWidth) / 2)),
        bottomRight((borderStripWidth + penaltyAreaLength), (borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth)),
        color(255, 255, 255),
        thickness(1) {}
};

struct rightPenaltyArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    rightPenaltyArea() :
        topLeft(((borderStripWidth + feildLength) - penaltyAreaLength), (borderStripWidth + (feildWidth - penaltyAreaWidth) / 2)),
        bottomRight((borderStripWidth + feildLength), (borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth)),
        color(255, 255, 255),
        thickness(1) {}
};

struct leftGoalArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    leftGoalArea() :
        topLeft(borderStripWidth , (borderStripWidth + (feildWidth - goalAreaWidth) / 2)),
        bottomRight((borderStripWidth + goalAreaLength), (borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth) ),
        color(255, 255, 255),
        thickness(1) {}
};

struct rightGoalArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    rightGoalArea() :
        topLeft(((borderStripWidth + feildLength) - goalAreaLength) , (borderStripWidth + (feildWidth - goalAreaWidth) / 2) ),
        bottomRight((borderStripWidth + feildLength), (borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth)),
        color(255, 255, 255),
        thickness(1) {}
};

struct midLine {
    Point startPoint;
    Point endPoint;
    Scalar color;
    int thickness;

    midLine() :
        startPoint((borderStripWidth + (feildLength / 2)) , borderStripWidth ),
        endPoint((borderStripWidth + (feildLength / 2)) , (borderStripWidth + feildWidth)),
        color(255, 255, 255),
        thickness(1) {}
};

struct centerCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    centerCircle() :
        center((borderStripWidth + (feildLength / 2)), (borderStripWidth + (feildWidth / 2))),
        radius((centreCircleDiameter / 2)),
        color(255, 255, 255),
        thickness(1) {}
};

struct leftPenaltyMarkCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    leftPenaltyMarkCircle() :
        center((borderStripWidth + penaltyMarkDistance) , (borderStripWidth + (feildWidth / 2))),
        radius(.08 * M),
        color(255, 255, 255),
        thickness(1) {}
};

struct rightPenaltyMarkCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    rightPenaltyMarkCircle() :
        center((borderStripWidth + (feildLength - penaltyMarkDistance)), (borderStripWidth + (feildWidth / 2))),
        radius(.08 * M),
        color(255, 255, 255),
        thickness(1) {}
};

struct insideCenterCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    insideCenterCircle() :
        center((borderStripWidth + (feildLength / 2)), (borderStripWidth + (feildWidth / 2))),
        radius(.08 * M),
        color(255, 255, 255),
        thickness(1) {}
};


int main() {

    Mat rgbMatrix(windowLength, windowWidth, CV_8UC3, Scalar(9, 16, 9));

    MainRectangle MainRectangle;
    leftGoal leftGoal;
    rightGoal rightGoal;
    leftPenaltyArea leftPenaltyArea;
    rightPenaltyArea rightPenaltyArea;
    leftGoalArea leftGoalArea;
    rightGoalArea rightGoalArea;
    midLine midLine;
    centerCircle centerCircle;
    leftPenaltyMarkCircle leftPenaltyMark;
    rightPenaltyMarkCircle rightPenaltyMark;
    insideCenterCircle insideCenterCircle;

    rectangle(rgbMatrix, MainRectangle.topLeft, MainRectangle.bottomRight, MainRectangle.color, MainRectangle.thickness);
    rectangle(rgbMatrix, leftGoal.topLeft, leftGoal.bottomRight, leftGoal.color, leftGoal.thickness);
    rectangle(rgbMatrix, rightGoal.topLeft, rightGoal.bottomRight, rightGoal.color, rightGoal.thickness);
    rectangle(rgbMatrix, leftPenaltyArea.topLeft, leftPenaltyArea.bottomRight, leftPenaltyArea.color, leftPenaltyArea.thickness);
    rectangle(rgbMatrix, rightPenaltyArea.topLeft, rightPenaltyArea.bottomRight, rightPenaltyArea.color, rightPenaltyArea.thickness);
    rectangle(rgbMatrix, leftGoalArea.topLeft, leftGoalArea.bottomRight, leftGoalArea.color, leftGoalArea.thickness);
    rectangle(rgbMatrix, rightGoalArea.topLeft, rightGoalArea.bottomRight, rightGoalArea.color, rightGoalArea.thickness);
    line(rgbMatrix, midLine.startPoint, midLine.endPoint, midLine.color, midLine.thickness);
    circle(rgbMatrix, centerCircle.center, centerCircle.radius, centerCircle.color, centerCircle.thickness);
    circle(rgbMatrix, leftPenaltyMark.center, leftPenaltyMark.radius, leftPenaltyMark.color, FILLED);
    circle(rgbMatrix, rightPenaltyMark.center, rightPenaltyMark.radius, rightPenaltyMark.color, FILLED);
    circle(rgbMatrix, insideCenterCircle.center, insideCenterCircle.radius, insideCenterCircle.color,FILLED);

    imshow( " " , rgbMatrix);
    
    waitKey(0);
    destroyAllWindows();

    return 0;
}