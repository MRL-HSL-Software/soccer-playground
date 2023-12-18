#include "soccerPlayground.hpp"

int main() {
    // Create an RGB matrix
    cv::Mat rgbMatrix(windowLength, windowWidth, CV_8UC3, cv::Scalar(9, 16, 9));

    MainRectangle main_rectangle;
    leftGoal left_goal;
    rightGoal right_goal;
    leftPenaltyArea left_penalty_area;
    rightPenaltyArea right_penalty_area;
    leftGoalArea left_goal_area;
    rightGoalArea right_goal_area;
    midLine mid_line;
    centerCircle center_circle;
    insideCenterCircle inside_center_circle;
    leftPenaltyMarkCircle left_penalty_mark;
    rightPenaltyMarkCircle right_penalty_mark;

    // Draw the rectangles and circles on the RGB matrix

    // Draw left goal rectangle
    cv::rectangle(rgbMatrix, left_goal.topLeft, left_goal.bottomRight, left_goal.color, left_goal.thickness);

    // Draw right goal rectangle
    cv::rectangle(rgbMatrix, right_goal.topLeft, right_goal.bottomRight, right_goal.color, right_goal.thickness);

    // Draw left penalty area
    cv::rectangle(rgbMatrix, left_penalty_area.topLeft, left_penalty_area.bottomRight, left_penalty_area.color, left_penalty_area.thickness);

    // Draw right penalty area
    cv::rectangle(rgbMatrix, right_penalty_area.topLeft, right_penalty_area.bottomRight, right_penalty_area.color, right_penalty_area.thickness);

    // Draw left goal area
    cv::rectangle(rgbMatrix, left_goal_area.topLeft, left_goal_area.bottomRight, left_goal_area.color, left_goal_area.thickness);

    // Draw right goal area
    cv::rectangle(rgbMatrix, right_goal_area.topLeft, right_goal_area.bottomRight, right_goal_area.color, right_goal_area.thickness);

    //Draw mid line
    cv::line(rgbMatrix, mid_line.startPoint, mid_line.endPoint, mid_line.color, mid_line.thickness);

    // Draw center circle
    cv::circle(rgbMatrix, center_circle.center, center_circle.radius, center_circle.color, center_circle.thickness);

    // Draw dot inside center circle
    cv::circle(rgbMatrix, inside_center_circle.center, inside_center_circle.radius, inside_center_circle.color, cv::FILLED);

    // Draw left penalty mark
    cv::circle(rgbMatrix, left_penalty_mark.center, left_penalty_mark.radius, left_penalty_mark.color, cv::FILLED);

    // Draw right penalty mark
    cv::circle(rgbMatrix, right_penalty_mark.center, right_penalty_mark.radius, right_penalty_mark.color, cv::FILLED);

    // Draw main rectangle
    cv::rectangle(rgbMatrix, main_rectangle.topLeft, main_rectangle.bottomRight, main_rectangle.color, main_rectangle.thickness);


    // Display the RGB matrix with the rectangles and circles in a window
    cv::imshow("RGB Matrix with Rectangle", rgbMatrix);

    // Wait for a key event and then close the window
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}