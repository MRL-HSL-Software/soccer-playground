#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

    double Field_length = 9;
    double Field_width = 6;
    double Goal_depth = 0.6;
    double Goal_width = 2.6;
    double Goal_height = 1.2;
    double Goal_area_length = 1;
    double Goal_area_width = 3;
    double Penalty_mark_distance = 1.5;
    double Centre_circle_diameter = 1.5;
    double Border_strip_width = 1;
    double Penalty_area_length = 2;
    double Penalty_area_width = 5;
    double x = (Field_width - Penalty_area_width ) /2;
    
    double pix = 100;

    // cout<<Border_strip_width + x + Penalty_area_width;

    cv::Mat football_playground = cv::Mat((Field_width + 2 * Border_strip_width) * pix, (Field_length + 2 * Border_strip_width) * pix, CV_8UC3, cv::Scalar(0,0,0));

    cv::rectangle(football_playground, 
    Point(Border_strip_width * pix, Border_strip_width * pix), 
    Point((Field_length + Border_strip_width) * pix , Field_width * pix), 
    Scalar(255, 255, 255), 2);

    //Left side

    cv::rectangle (football_playground,
    Point(Border_strip_width * pix, (Border_strip_width + x) * pix ), //100 , 150
    Point((Border_strip_width + Penalty_area_length ) * pix, ( x + Penalty_area_width ) *pix),    //300 , 550
    Scalar(255, 255, 255),
    2);

    cv::rectangle (football_playground,
    Point(Border_strip_width * pix, 250 ), //100 , 200
    Point((Border_strip_width + Goal_area_length ) * pix, 550),    //200 , 500
    Scalar(255, 255, 255),
     2);


    
    // cv::rectangle (football_playground, 
    // Point(Border_strip_width * pix , (100 + x)  * pix), 
    // Point(300, 550), 
    // Scalar(255, 255, 255), 2);

    // cv::rectangle (football_playground, Point(Border_strip_width * pix, Border_strip_width + (Field_width - Penalty_area_width)/2), Point(Border_strip_width + Penalty_area_length, Border_strip_width + (Field_width - Penalty_area_width)/2 + Penalty_area_width), Scalar(255, 255, 255), 2);

    cv::imshow("football_playground", football_playground);
    cv::waitKey(0);

}