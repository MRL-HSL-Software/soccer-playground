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

// wndow variables
int windowWidth = (feildLength + borderStripWidth * 2);
int windowLength = (feildWidth + borderStripWidth * 2);

struct MainRectangle {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    MainRectangle() {
        topLeft.x = borderStripWidth;
        topLeft.y = borderStripWidth;
        bottomRight.x = borderStripWidth + feildLength;
        bottomRight.y = borderStripWidth + feildWidth;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct leftGoal {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    leftGoal() {
        topLeft.x = borderStripWidth - goalDepth;
        topLeft.y = borderStripWidth + (feildWidth - goalwidth) / 2;
        bottomRight.x = borderStripWidth;
        bottomRight.y = borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth;
        color = Scalar(255, 255, 0);
        thickness = 1;
    }
};


struct rightGoal {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    rightGoal() {
        topLeft.x = borderStripWidth + feildLength;
        topLeft.y = borderStripWidth + (feildWidth - goalwidth) / 2;
        bottomRight.x = borderStripWidth + feildLength + goalDepth;
        bottomRight.y = borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth;
        color = Scalar(0, 0, 255);
        thickness = 1;
    }
};


    struct leftPenaltyArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    leftPenaltyArea() {
        topLeft.x = borderStripWidth;
        topLeft.y = borderStripWidth + (feildWidth - penaltyAreaWidth) / 2;
        bottomRight.x = borderStripWidth + penaltyAreaLength;
        bottomRight.y = borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct rightPenaltyArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    rightPenaltyArea() {
        topLeft.x = (borderStripWidth + feildLength) - penaltyAreaLength;
        topLeft.y = borderStripWidth + (feildWidth - penaltyAreaWidth) / 2;
        bottomRight.x = borderStripWidth + feildLength;
        bottomRight.y = borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct leftGoalArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    leftGoalArea() {
        topLeft.x = borderStripWidth;
        topLeft.y = borderStripWidth + (feildWidth - goalAreaWidth) / 2;
        bottomRight.x = borderStripWidth + goalAreaLength;
        bottomRight.y = borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct rightGoalArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    rightGoalArea() {
        topLeft.x = (borderStripWidth + feildLength) - goalAreaLength;
        topLeft.y = borderStripWidth + (feildWidth - goalAreaWidth) / 2;
        bottomRight.x = borderStripWidth + feildLength;
        bottomRight.y = borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct midLine {
    Point startPoint;
    Point endPoint;
    Scalar color;
    int thickness;

    midLine() {
        startPoint.x = borderStripWidth + (feildLength / 2);
        startPoint.y = borderStripWidth;
        endPoint.x = borderStripWidth + (feildLength / 2);
        endPoint.y = borderStripWidth + feildWidth;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct centerCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    centerCircle() {
        center.x = borderStripWidth + (feildLength / 2);
        center.y = borderStripWidth + (feildWidth / 2);
        radius = centreCircleDiameter / 2;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct leftPenaltyMarkCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    leftPenaltyMarkCircle() {
        center.x = borderStripWidth + penaltyMarkDistance;
        center.y = borderStripWidth + (feildWidth / 2);
        radius = 0.08 * M;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct rightPenaltyMarkCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    rightPenaltyMarkCircle() {
        center.x = borderStripWidth + (feildLength - penaltyMarkDistance);
        center.y = borderStripWidth + (feildWidth / 2);
        radius = 0.08 * M;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
};


struct insideCenterCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    insideCenterCircle() {
        center.x = borderStripWidth + (feildLength / 2);
        center.y = borderStripWidth + (feildWidth / 2);
        radius = 0.08 * M;
        color = Scalar(255, 255, 255);
        thickness = 1;
    }
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