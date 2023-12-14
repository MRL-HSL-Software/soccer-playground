#include "soccer_playground.hpp"

double Field_length = FIELD_LENGTH;
double Field_width = FIELD_WIDTH;
double Goal_depth = GOAL_DEPTH;
double Goal_width = GOAL_WIDTH;
double Goal_height = GOAL_HEIGHT;
double Goal_area_length = GOAL_AREA_LENGTH;
double Goal_area_width = GOAL_AREA_WIDTH;
double Penalty_mark_distance = PENALTY_MARK_DISTANCE;
double Center_circle_diameter = CENTER_CIRCLE_DIAMETER;
double Border_strip_width = BORDER_STRIP_WIDTH;
double Penalty_area_length = PENALTY_AREA_LENGTH;
double Penalty_area_width = PENALTY_AREA_WIDTH;

int scale = SCALE;

double width  = Field_width + 2 * Border_strip_width;
double length = Field_length + 2 * Border_strip_width;

double JtoA = (Field_width - Penalty_area_width) /2;
double EtoJ = (Penalty_area_width - Goal_area_width) /2;
double CtoE = (Goal_area_width - Goal_width) /2;

void soccer_playground :: create()
{
    football_playground = Mat(width * scale, length * scale, CV_8UC3, Scalar(0,0,0));

    //main rectangle 
    Point top_Left(Border_strip_width * scale, Border_strip_width * scale);//
    Point bottom_Right((Border_strip_width + Field_length) * scale, (Border_strip_width + Field_width) * scale);//

    //left side
    Point Penalty_Left_top (Border_strip_width * scale, (Border_strip_width + JtoA) * scale);//
    Point Penalty_Left_bottom ((Penalty_area_length + Border_strip_width) * scale , (JtoA + Penalty_area_width + Border_strip_width) * scale);//

    Point Goal_Area_Left_top (Border_strip_width * scale, (Border_strip_width + JtoA + EtoJ )* scale);
    Point Goal_Area_Left_bottom ((Border_strip_width + Goal_area_length)* scale, (Border_strip_width + JtoA + EtoJ + Goal_area_width )* scale );

    Point Goal_Left_top ((Border_strip_width - Goal_depth)* scale, (Border_strip_width + JtoA + EtoJ + CtoE) * scale);//
    Point Goal_Left_bottom (Border_strip_width * scale , (Border_strip_width + JtoA + EtoJ + CtoE + Goal_width) * scale);//

    //right side
    Point Penalty_Right_top ((Border_strip_width + (Field_length - Penalty_area_length)) * scale, (Border_strip_width + JtoA) * scale);//
    Point Penalty_Right_bottom ((Border_strip_width + Field_length) * scale , (Border_strip_width + JtoA + Penalty_area_width) * scale);//

    Point Goal_Area_Right_top ((Border_strip_width + (Field_length - Goal_area_length)) * scale, (Border_strip_width + JtoA + EtoJ )* scale);//
    Point Goal_Area_Right_bottom ((Border_strip_width + Field_length)* scale, (Border_strip_width + JtoA + EtoJ + Goal_area_width )* scale );//

    Point Goal_Right_top ((Border_strip_width + Field_length)* scale, (Border_strip_width + JtoA + EtoJ + CtoE) * scale);
    Point Goal_Right_bottom ((Border_strip_width + Field_length + Goal_depth) * scale , (Border_strip_width + JtoA + EtoJ + CtoE + Goal_width) * scale);

    cv::rectangle( football_playground, Goal_Left_top, Goal_Left_bottom, cv::Scalar(0, 255, 255), 1); //Goal depth Left
    cv::rectangle( football_playground, Goal_Right_top, Goal_Right_bottom, cv::Scalar(255, 191, 0), 1); //Goal depth Right


    //drawing the ground
    cv::rectangle( football_playground, top_Left, bottom_Right, cv::Scalar(255, 255, 255), 1);

    //left
    cv::rectangle( football_playground, Penalty_Left_top, Penalty_Left_bottom, cv::Scalar(255, 255, 255), 1); //Penalty area
    cv::rectangle( football_playground, Goal_Area_Left_top, Goal_Area_Left_bottom, cv::Scalar(255, 255, 255), 1); //Goal area

    //right
    cv::rectangle( football_playground, Penalty_Right_top, Penalty_Right_bottom, cv::Scalar(255, 255, 255), 1); //Penalty area
    cv::rectangle( football_playground, Goal_Area_Right_top, Goal_Area_Right_bottom, cv::Scalar(255, 255, 255), 1); //Goal area

     //main circle
    cv::circle(football_playground, cv::Point((Border_strip_width + Field_length/2) * scale, ( Border_strip_width +  Field_width /2)* scale ),(Center_circle_diameter/2)  *scale ,cv::Scalar(255, 255, 255), 1);

     //small circles
    cv::circle(football_playground, cv::Point((Border_strip_width + Penalty_mark_distance) * scale, ( Border_strip_width +  Field_width /2)* scale ),0.05 *scale ,cv::Scalar(255, 255, 255), FILLED);

    cv::circle(football_playground, cv::Point((Border_strip_width + Field_length/2) * scale, ( Border_strip_width +  Field_width /2)* scale ),0.05  *scale ,cv::Scalar(255, 255, 255), FILLED);

    cv::circle(football_playground, 
    cv::Point((Border_strip_width + Field_length - Penalty_mark_distance) * scale, ( Border_strip_width +  Field_width /2)* scale ), 
    0.05 * scale ,
    cv::Scalar(255, 255, 255), 
    FILLED);

    cv::line (football_playground, 
    cv::Point((Border_strip_width + (Field_length /2))* scale , Border_strip_width * scale), 
    cv::Point((Border_strip_width + (Field_length /2))* scale , (Border_strip_width + Field_width)* scale), 
    cv::Scalar(255, 255, 255),
    1);
    }


cv::Mat soccer_playground::display()
{
    return football_playground;
}