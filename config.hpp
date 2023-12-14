#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
using namespace cv;

extern double Field_length;
extern double Field_width;
extern double Goal_depth;
extern double Goal_width;
extern double Goal_height;
extern double Goal_area_length;
extern double Goal_area_width;
extern double Penalty_mark_distance;
extern double Centre_circle_diameter;
extern double Border_strip_width;
extern double Penalty_area_length;
extern double Penalty_area_width;

extern int scale;

extern double width;
extern double length;

extern double JtoA;
extern double EtoJ;
extern double CtoE;


#endif