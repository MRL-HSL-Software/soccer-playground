#include "play_gound.h"

int main() {
    PlayGround drawer(500, 500); // Initialize with width and height

    // Draw shapes
    drawer.drawRectangle();
    // drawer.drawCircle(cv::Point(300, 150), 100, cv::Scalar(255, 255, 255));
    // drawer.drawLine(cv::Point(350, 300), cv::Point(450, 400), cv::Scalar(255, 255, 255));

    drawer.showImage();

    return 0;
}
