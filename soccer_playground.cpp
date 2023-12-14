#include "soccer_playground.hpp"

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

int scale = 50;

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

}

cv::Mat soccer_playground::display()
{
    return football_playground;
}