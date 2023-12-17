#include "play_ground.h"
#include "config.h"

PlayGround::PlayGround(int baseIndex) {
    base_index = baseIndex;
    const int width = (MAIN_RECT_WIDTH * base_index) + (MAIN_RECT_MARGIN * base_index) * 2;
    const int height = (MAIN_RECT_HEIGHT * base_index) + (MAIN_RECT_MARGIN * base_index) * 2;
    image = cv::Mat::zeros(height, width, CV_8UC3);
}

void PlayGround::drawMainRect() {
    cv::Point main_rect_top_left(MAIN_RECT_MARGIN * base_index, MAIN_RECT_MARGIN * base_index);
    cv::Point main_rect_bottom_right((MAIN_RECT_WIDTH * base_index) + (MAIN_RECT_MARGIN * base_index), (MAIN_RECT_HEIGHT * base_index) + (MAIN_RECT_MARGIN * base_index));
    cv::rectangle(image, main_rect_top_left, main_rect_bottom_right, cv::Scalar(255, 255, 255), 1);
    cv::Point middle_line_starting(MAIN_RECT_MARGIN * base_index + (MAIN_RECT_WIDTH * base_index)/2, MAIN_RECT_MARGIN * base_index);
    cv::Point middle_line_ending(MAIN_RECT_MARGIN * base_index + (MAIN_RECT_WIDTH * base_index)/2, MAIN_RECT_HEIGHT * base_index + MAIN_RECT_MARGIN * base_index);
    cv::line(image, middle_line_starting, middle_line_ending, cv::Scalar(255, 255, 255), 1);
}

void PlayGround::drawMiddleCircle() {
    cv::Point middle_circle_coordinate(MAIN_RECT_MARGIN * base_index + (MAIN_RECT_WIDTH * base_index)/2, MAIN_RECT_MARGIN * base_index + (MAIN_RECT_HEIGHT * base_index) / 2);
    cv::circle(image, middle_circle_coordinate, MIDDLE_CIRCLE_RADIUS * base_index, cv::Scalar(255, 255, 255), 1);
}

void PlayGround::drawBigGoalRect(){
    cv::Point left_larg_goal_rect_top_left(
        (MAIN_RECT_MARGIN * base_index + MAIN_RECT_WIDTH * base_index) - (LARG_GOAL_RECT_WIDTH * base_index),
        (((MAIN_RECT_MARGIN * base_index)*2 + (MAIN_RECT_HEIGHT * base_index)) - (LARG_GOAL_RECT_HEIGHT * base_index))/2
        );
    cv::Point left_larg_goal_rect_buttom_right(
        MAIN_RECT_MARGIN * base_index + MAIN_RECT_WIDTH * base_index,
        ((((MAIN_RECT_MARGIN * base_index)*2 + (MAIN_RECT_HEIGHT * base_index)) - (LARG_GOAL_RECT_HEIGHT * base_index))/2) + (LARG_GOAL_RECT_HEIGHT * base_index)
        );
    cv::rectangle(image, left_larg_goal_rect_top_left, left_larg_goal_rect_buttom_right, cv::Scalar(255, 255, 255), 1);
}

// void ShapeDrawer::drawCircle() {
//     cv::circle(image, center, radius, color, -1);
// }

// void ShapeDrawer::drawLine() {
//     cv::line(image, pt1, pt2, color, 2);
// }

void PlayGround::showImage() {
    cv::imshow("Shapes", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
