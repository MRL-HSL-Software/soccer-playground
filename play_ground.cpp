#include "play_ground.h"
#include "config.h"

PlayGround::PlayGround() {
    /*
    Calculate the size of entire window depending on
    field widht and height and its margines, then create
    the main window frame with generated sizes
    */
    const int width = (MAIN_RECT_WIDTH * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX) * 2;
    const int height = (MAIN_RECT_HEIGHT * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX) * 2;
    image = cv::Mat::zeros(height, width, CV_8UC3);
}

void PlayGround::drawMainRect() {
    /*
    Draw the main field rectangle with its middle line
    */
    cv::Point main_rect_top_left(MAIN_RECT_MARGIN * BASE_INDEX, MAIN_RECT_MARGIN * BASE_INDEX);
    cv::Point main_rect_bottom_right((MAIN_RECT_WIDTH * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX),
                                    (MAIN_RECT_HEIGHT * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX));
    cv::rectangle(
        image, main_rect_top_left,
        main_rect_bottom_right,
        cv::Scalar(255, 255, 255),
        LINE_WIDTH);

    cv::Point middle_line_starting(MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_WIDTH * BASE_INDEX)/2,
                                    MAIN_RECT_MARGIN * BASE_INDEX);
    cv::Point middle_line_ending(MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_WIDTH * BASE_INDEX)/2,
                                    MAIN_RECT_HEIGHT * BASE_INDEX + MAIN_RECT_MARGIN * BASE_INDEX);
    cv::line(
        image,
        middle_line_starting,
        middle_line_ending,
        cv::Scalar(255, 255, 255),
        LINE_WIDTH);
}

void PlayGround::drawMiddleCircle() {
    /*
    Draw the middle circle
    */
    cv::Point middle_circle_coordinate(
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_WIDTH * BASE_INDEX)/2,
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_HEIGHT * BASE_INDEX) / 2
        );
    cv::circle(
        image,
        middle_circle_coordinate,
        (MIDDLE_CIRCLE_RADIUS * BASE_INDEX)/2,
        cv::Scalar(255, 255, 255),
        LINE_WIDTH);
}

void PlayGround::drawBigGoalRect(){
    /*
    Draw the penalty area of both sides
    */
    cv::Point right_larg_goal_rect_top_left(
        (MAIN_RECT_MARGIN * BASE_INDEX + MAIN_RECT_WIDTH * BASE_INDEX) - (LARG_GOAL_RECT_WIDTH * BASE_INDEX),
        (((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            LARG_GOAL_RECT_HEIGHT * BASE_INDEX))/2
        );
    cv::Point right_larg_goal_rect_buttom_right(
        MAIN_RECT_MARGIN * BASE_INDEX + MAIN_RECT_WIDTH * BASE_INDEX,
        ((((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            LARG_GOAL_RECT_HEIGHT * BASE_INDEX))/2) + (LARG_GOAL_RECT_HEIGHT * BASE_INDEX)
        );
    cv::rectangle(
        image,
        right_larg_goal_rect_top_left,
        right_larg_goal_rect_buttom_right,
        cv::Scalar(255, 255, 255),
        LINE_WIDTH);


    cv::Point left_larg_goal_rect_top_left(
        MAIN_RECT_MARGIN * BASE_INDEX,
        (((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            LARG_GOAL_RECT_HEIGHT * BASE_INDEX))/2
        );
    cv::Point left_larg_goal_rect_buttom_right(
        MAIN_RECT_MARGIN * BASE_INDEX + LARG_GOAL_RECT_WIDTH * BASE_INDEX,
        ((((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            LARG_GOAL_RECT_HEIGHT * BASE_INDEX))/2) + (LARG_GOAL_RECT_HEIGHT * BASE_INDEX)
        );
    cv::rectangle(image,
    left_larg_goal_rect_top_left,
    left_larg_goal_rect_buttom_right,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);
}

void PlayGround::drawSmallGoalRect(){
    /*
    Draw the goal area rectangles
    */
    cv::Point right_small_goal_rect_top_left(
        (MAIN_RECT_MARGIN * BASE_INDEX + MAIN_RECT_WIDTH * BASE_INDEX) - (
            SMALL_GOAL_RECT_WIDTH * BASE_INDEX),
        (((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            SMALL_GOAL_RECT_HEIGHT * BASE_INDEX))/2
        );
    cv::Point right_small_goal_rect_buttom_right(
        MAIN_RECT_MARGIN * BASE_INDEX + MAIN_RECT_WIDTH * BASE_INDEX,
        ((((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            SMALL_GOAL_RECT_HEIGHT * BASE_INDEX))/2) + (SMALL_GOAL_RECT_HEIGHT * BASE_INDEX)
        );
    cv::rectangle(image,
    right_small_goal_rect_top_left,
    right_small_goal_rect_buttom_right,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);


    cv::Point left_small_goal_rect_top_left(
        MAIN_RECT_MARGIN * BASE_INDEX,
        (((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            SMALL_GOAL_RECT_HEIGHT * BASE_INDEX))/2
        );
    cv::Point left_small_goal_rect_buttom_right(
        MAIN_RECT_MARGIN * BASE_INDEX + SMALL_GOAL_RECT_WIDTH * BASE_INDEX,
        ((((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            SMALL_GOAL_RECT_HEIGHT * BASE_INDEX))/2) + (SMALL_GOAL_RECT_HEIGHT * BASE_INDEX)
        );
    cv::rectangle(image,
    left_small_goal_rect_top_left,
    left_small_goal_rect_buttom_right,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);
}

void PlayGround::drawGoals(){
    /*
    Draw goals rectangle
    */
    cv::Point right_goal_top_left(
        (MAIN_RECT_WIDTH * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX),
        (((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            GOAL_HEIGHT * BASE_INDEX))/2
        );
    cv::Point right_goal_buttom_right(
        ((MAIN_RECT_WIDTH * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX)) + (
            GOAL_WIDTH * BASE_INDEX),
        ((((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            GOAL_HEIGHT * BASE_INDEX))/2) + (GOAL_HEIGHT * BASE_INDEX)
        );
    cv::rectangle(image,
    right_goal_top_left,
    right_goal_buttom_right,
    cv::Scalar(255, 255, 0),
    LINE_WIDTH);


    cv::Point left_goal_top_left(
        (MAIN_RECT_MARGIN * BASE_INDEX) - (GOAL_WIDTH * BASE_INDEX),
        (((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            GOAL_HEIGHT * BASE_INDEX))/2
        );
    cv::Point left_goal_buttom_right(
        MAIN_RECT_MARGIN * BASE_INDEX,
        ((((MAIN_RECT_MARGIN * BASE_INDEX)*2 + (MAIN_RECT_HEIGHT * BASE_INDEX)) - (
            GOAL_HEIGHT * BASE_INDEX))/2) + (GOAL_HEIGHT * BASE_INDEX)
        );
    cv::rectangle(image,
    left_goal_top_left,
    left_goal_buttom_right,
    cv::Scalar(0, 255, 255),
    LINE_WIDTH);
}

void PlayGround::drawPoints(){
    /*
    Draw three points in the field (Left and right penalty point, middle point)
    */
    cv::Point right_horizontal_penalty_goal_ending_coordinate(
        ((MAIN_RECT_WIDTH * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX)) - (
            PENALTY_MARK_DISTANCE * BASE_INDEX + PENALTY_MARK_SIZE * BASE_INDEX),
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_HEIGHT * BASE_INDEX)/2
        );
    cv::Point right_horizontal_penalty_goal_starting_coordinate(
        ((MAIN_RECT_WIDTH * BASE_INDEX) + (MAIN_RECT_MARGIN * BASE_INDEX)) - (
            PENALTY_MARK_DISTANCE * BASE_INDEX - PENALTY_MARK_SIZE * BASE_INDEX),
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_HEIGHT * BASE_INDEX)/2
        );
    cv::line(image,
    right_horizontal_penalty_goal_starting_coordinate,
    right_horizontal_penalty_goal_ending_coordinate,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);


    cv::Point right_vertical_penalty_goal_ending_coordinate(
        ((MAIN_RECT_WIDTH * BASE_INDEX) + (
            MAIN_RECT_MARGIN * BASE_INDEX)) - PENALTY_MARK_DISTANCE * BASE_INDEX,
        (MAIN_RECT_MARGIN * BASE_INDEX + (
            MAIN_RECT_HEIGHT * BASE_INDEX)/2) - PENALTY_MARK_SIZE * BASE_INDEX
        );
    cv::Point right_vertical_penalty_goal_starting_coordinate(
        ((MAIN_RECT_WIDTH * BASE_INDEX) + (
            MAIN_RECT_MARGIN * BASE_INDEX)) - PENALTY_MARK_DISTANCE * BASE_INDEX,
        (MAIN_RECT_MARGIN * BASE_INDEX + (
            MAIN_RECT_HEIGHT * BASE_INDEX)/2) + PENALTY_MARK_SIZE * BASE_INDEX
        );
    cv::line(image,
    right_vertical_penalty_goal_starting_coordinate,
    right_vertical_penalty_goal_ending_coordinate,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);


    cv::Point left_horizontal_penalty_goal_ending_coordinate(
        (MAIN_RECT_MARGIN * BASE_INDEX) + (
            PENALTY_MARK_DISTANCE * BASE_INDEX + PENALTY_MARK_SIZE * BASE_INDEX),
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_HEIGHT * BASE_INDEX)/2
        );
    cv::Point left_horizontal_penalty_goal_starting_coordinate(
        (MAIN_RECT_MARGIN * BASE_INDEX) + (
            PENALTY_MARK_DISTANCE * BASE_INDEX - PENALTY_MARK_SIZE * BASE_INDEX),
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_HEIGHT * BASE_INDEX)/2
        );
    cv::line(image,
    left_horizontal_penalty_goal_starting_coordinate,
    left_horizontal_penalty_goal_ending_coordinate,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);


    cv::Point left_vertical_penalty_goal_ending_coordinate(
        MAIN_RECT_MARGIN * BASE_INDEX + PENALTY_MARK_DISTANCE * BASE_INDEX,
        (MAIN_RECT_MARGIN * BASE_INDEX + (
            MAIN_RECT_HEIGHT * BASE_INDEX)/2) - PENALTY_MARK_SIZE * BASE_INDEX
        );
    cv::Point left_vertical_penalty_goal_starting_coordinate(
        MAIN_RECT_MARGIN * BASE_INDEX + PENALTY_MARK_DISTANCE * BASE_INDEX,
        (MAIN_RECT_MARGIN * BASE_INDEX + (
            MAIN_RECT_HEIGHT * BASE_INDEX)/2) + PENALTY_MARK_SIZE * BASE_INDEX
        );
    cv::line(image,
    left_vertical_penalty_goal_starting_coordinate,
    left_vertical_penalty_goal_ending_coordinate,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);


    cv::Point middle_horizontal_penalty_goal_ending_coordinate(
        (MAIN_RECT_MARGIN * BASE_INDEX) + (
            (MAIN_RECT_WIDTH * BASE_INDEX)/2) + PENALTY_MARK_SIZE * BASE_INDEX,
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_HEIGHT * BASE_INDEX)/2
        );
    cv::Point middle_horizontal_penalty_goal_starting_coordinate(
        (MAIN_RECT_MARGIN * BASE_INDEX) + (
            MAIN_RECT_WIDTH * BASE_INDEX)/2 - PENALTY_MARK_SIZE * BASE_INDEX,
        MAIN_RECT_MARGIN * BASE_INDEX + (MAIN_RECT_HEIGHT * BASE_INDEX)/2
        );
    cv::line(image,
    middle_horizontal_penalty_goal_ending_coordinate,
    middle_horizontal_penalty_goal_starting_coordinate,
    cv::Scalar(255, 255, 255),
    LINE_WIDTH);
}

void PlayGround::drawTheWholeField(){
    /*
    Encapsulate all necessary methods for drawing the field
    */
    PlayGround::drawGoals();
    PlayGround::drawMainRect();
    PlayGround::drawMiddleCircle();
    PlayGround::drawBigGoalRect();
    PlayGround::drawSmallGoalRect();
    PlayGround::drawPoints();
}

void PlayGround::showImage() {
    /*
    Display the final image and ready to get any number for closing it
    */
    cv::imshow("Soccer Field", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
