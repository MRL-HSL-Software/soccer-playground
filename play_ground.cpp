#include "play_ground.h"
#include "config.h"

PlayGround::PlayGround(int width, int height) {
    image = cv::Mat::zeros(300, 500, CV_8UC3);
}

void ShapeDrawer::drawRectangle() {
    cv::rectangle(image, MAIN_RECT_WITDH, MAIN_RECT_HEIGHT, cv::Scalar(255, 255, 255), -1);
}

// void ShapeDrawer::drawCircle() {
//     cv::circle(image, center, radius, color, -1);
// }

// void ShapeDrawer::drawLine() {
//     cv::line(image, pt1, pt2, color, 2);
// }

void ShapeDrawer::showImage() {
    cv::imshow("Shapes", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
