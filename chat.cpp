#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // Create a black image as the background
    Mat soccerField = Mat::zeros(800, 1100, CV_8UC3);

    // Draw the field boundaries
    rectangle(soccerField, Point(50, 50), Point(1050, 750), Scalar(0, 255, 0), 2);

    // Draw the center circle
    circle(soccerField, Point(550, 400), 75, Scalar(0, 255, 0), 2);

    // Draw the goal areas
    rectangle(soccerField, Point(50, 250), Point(250, 750), Scalar(0, 255, 0), 2);
    rectangle(soccerField, Point(850, 250), Point(1050, 750), Scalar(0, 255, 0), 2);

    // Draw the goalposts
    rectangle(soccerField, Point(40, 350), Point(50, 450), Scalar(0, 255, 0), 2);
    rectangle(soccerField, Point(1050, 350), Point(1060, 450), Scalar(0, 255, 0), 2);

    // Draw the soccer ball
    circle(soccerField, Point(550, 400), 10, Scalar(0, 0, 255), FILLED);

    // Display the soccer field
    imshow("Soccer Field", soccerField);
    waitKey(0);

    return 0;
}
