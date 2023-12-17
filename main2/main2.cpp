#include <opencv2/opencv.hpp>
using namespace cv;

int Pixel = 100;
double M = Pixel;

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

int windowWidth = (feildLength + borderStripWidth * 2);
int windowLength = (feildWidth + borderStripWidth * 2);

struct MainRectangle {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    MainRectangle(int x1, int y1, int x2, int y2, Scalar col, int thick)
        : topLeft(x1, y1), bottomRight(x2, y2), color(col), thickness(thick) {}
    
    void render(Mat& rgbMatrix) const {
        rectangle(rgbMatrix, topLeft, bottomRight, color, thickness);
    }
};

struct Goal {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    Goal(int leftX, int rightX, int y, Scalar col, int thick)
        : topLeft(leftX, y),
          bottomRight(rightX, y + goalwidth),
          color(col),
          thickness(thick) {}

    void render(Mat& rgbMatrix) const {
        rectangle(rgbMatrix, topLeft, bottomRight, color, thickness);
    }
};

    struct PenaltyArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    PenaltyArea(int leftX, int rightX, int y, Scalar col, int thick)
        : topLeft(leftX, y),
          bottomRight(rightX, y + penaltyAreaWidth),
          color(col),
          thickness(thick) {}
    
    void render(Mat& rgbMatrix) const {
        rectangle(rgbMatrix, topLeft, bottomRight, color, thickness);
    }
};

struct GoalArea {
    Point topLeft;
    Point bottomRight;
    Scalar color;
    int thickness;

    GoalArea(int leftX, int rightX, int y, Scalar col, int thick)
        : topLeft(leftX, y),
          bottomRight(rightX, y + goalAreaWidth),
          color(col),
          thickness(thick) {}
    
    void render(Mat& rgbMatrix) const {
        rectangle(rgbMatrix, topLeft, bottomRight, color, thickness);
    }
};

struct MidLine {
    Point startPoint;
    Point endPoint;
    Scalar color;
    int thickness;

    MidLine(int startX, int startY, int endX, int endY, Scalar col, int thick)
        : startPoint(startX, startY), endPoint(endX, endY), color(col), thickness(thick) {}

    void render(Mat& rgbMatrix) const {
        line(rgbMatrix, startPoint, endPoint, color, thickness);
    }
};

struct CenterCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    CenterCircle(int centerX, int centerY, int rad, Scalar col, int thick)
        : center(centerX, centerY), radius(rad), color(col), thickness(thick) {}

    void render(Mat& rgbMatrix) const {
        circle(rgbMatrix, center, radius, color, thickness);
    }
};

struct PenaltyMarkCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    PenaltyMarkCircle(int centerX, int centerY, int rad, Scalar col, int thick)
        : center(centerX, centerY), radius(rad), color(col), thickness(thick) {}

    void render(Mat& rgbMatrix) const {
        circle(rgbMatrix, center, radius, color, FILLED);
    }
};

struct InsideCenterCircle {
    Point center;
    Scalar color;
    int radius;
    int thickness;

    InsideCenterCircle(int centerX, int centerY, int rad, Scalar col, int thick)
        : center(centerX, centerY), radius(rad), color(col), thickness(thick) {}

    void render(Mat& rgbMatrix) const {
        circle(rgbMatrix, center, radius, color, FILLED);
    }
};

int main() {

        Mat rgbMatrix(windowLength, windowWidth, CV_8UC3, Scalar(9, 16, 9));

        MainRectangle rectangles[] = {
        {borderStripWidth, borderStripWidth, borderStripWidth + feildLength, borderStripWidth + feildWidth, Scalar(255, 255, 255), 1}
    };

    for (const auto& rect : rectangles) {
        rect.render(rgbMatrix);
    }

    Goal goals[] = {
        {borderStripWidth - goalDepth, borderStripWidth, borderStripWidth + (feildWidth - goalwidth) / 2, Scalar(255, 255, 0), 1},
        {borderStripWidth + feildLength, borderStripWidth + feildLength + goalDepth, borderStripWidth + (feildWidth - goalwidth) / 2, Scalar(0, 0, 255), 1}
    };

    for (const auto& goal : goals) {
        goal.render(rgbMatrix);
    }

     PenaltyArea areas[] = {
        {borderStripWidth, borderStripWidth + penaltyAreaLength, borderStripWidth + (feildWidth - penaltyAreaWidth) / 2, Scalar(255, 255, 255), 1},
        {borderStripWidth + feildLength - penaltyAreaLength, borderStripWidth + feildLength, borderStripWidth + (feildWidth - penaltyAreaWidth) / 2, Scalar(255, 255, 255), 1}
    };

    for (const auto& area : areas) {
        area.render(rgbMatrix);
    }
    
    GoalArea goalAreas[] = {
        {borderStripWidth, borderStripWidth + goalAreaLength, borderStripWidth + (feildWidth - goalAreaWidth) / 2, Scalar(255, 255, 255), 1},
        {borderStripWidth + feildLength - goalAreaLength, borderStripWidth + feildLength, borderStripWidth + (feildWidth - goalAreaWidth) / 2, Scalar(255, 255, 255), 1}
    };

    for (const auto& area : goalAreas) {
        area.render(rgbMatrix);
    }

    MidLine midLines[] = {
        {borderStripWidth + (feildLength / 2), borderStripWidth, borderStripWidth + (feildLength / 2), borderStripWidth + feildWidth, Scalar(255, 255, 255), 1}
    };

    for (const auto& line : midLines) {
        line.render(rgbMatrix);
    }

    CenterCircle centerCircles[] = {
        {borderStripWidth + (feildLength / 2), borderStripWidth + (feildWidth / 2), centreCircleDiameter / 2, Scalar(255, 255, 255), 1}
    };

    for (const auto& circle : centerCircles) {
        circle.render(rgbMatrix);
    }

    PenaltyMarkCircle penaltyMarkCircles[] = {
        {borderStripWidth + penaltyMarkDistance, borderStripWidth + (feildWidth / 2), 0.08 * M, Scalar(255, 255, 255), 1},
        {borderStripWidth + (feildLength - penaltyMarkDistance), borderStripWidth + (feildWidth / 2), 0.08 * M, Scalar(255, 255, 255), 1}
    };

    for (const auto& circle : penaltyMarkCircles) {
        circle.render(rgbMatrix);
    }

    InsideCenterCircle insideCenterCircles[] = {
        {borderStripWidth + (feildLength / 2), borderStripWidth + (feildWidth / 2), 0.08 * M, Scalar(255, 255, 255), 1}
    };

    for (const auto& circle : insideCenterCircles) {
        circle.render(rgbMatrix);
    }
    
    imshow( " " , rgbMatrix);
    waitKey(0);
    destroyAllWindows();

    return 0;
}