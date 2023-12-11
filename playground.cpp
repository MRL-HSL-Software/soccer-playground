#include "playground.hpp"

using namespace cv;

    double Field_length = 9.0;
    double Field_width = 6.0;
    double Goal_depth = 0.6;
    double Goal_width = 2.6;
    double Goal_height = 1.2;
    double Goal_area_length = 1.0;
    double Goal_area_width = 3.0;
    double Penalty_mark_distance = 1.5;
    double Centre_circle_diameter = 1.5;
    double Border_strip_width = 1.0;
    double Penalty_area_length = 2.0;
    double Penalty_area_width = 5.0;

    int scale = 100;

    double width  = Field_width + 2 * Border_strip_width;
    double length = Field_length + 2 * Border_strip_width;

    double JtoA = (Field_width - Penalty_area_width) /2;
    double FtoJ = (Penalty_area_width - Goal_area_width) /2;


void playground :: Create()
{
    // football_playground = cv::Mat(width * scale, length * scale, CV_8UC3, Scalar(0,0,0));
    football_playground = Mat(width * scale, length * scale, CV_8UC3, Scalar(0,0,0));


    //main rectangle 
    Point top_Left(Border_strip_width * scale, Border_strip_width * scale);
    Point bottom_Right((Border_strip_width + Field_length) * scale, (Border_strip_width + Field_width) * scale);

    //right side

    // Point Penalty_Right_top (Border_strip_width * scale, (Border_strip_width + JtoA) * scale);
    // Point Penalty_Right_bottom((Field_length + Border_strip_width) * scale , Field_width * scale);

    // Point Goal_Right_top(Border_strip_width * scale, (Border_strip_width +JtoA )* scale);
    // Point Goal_Right_bottom(Border_strip_width +Penalty_area_length, );

    //drawing the ground
    cv::rectangle( football_playground,top_Left, bottom_Right, cv::Scalar(255, 255, 255), 2);

}

cv::Mat playground::Access(){
    return football_playground;
}