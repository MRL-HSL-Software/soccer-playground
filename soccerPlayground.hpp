#ifndef SOCCERPLAYGROUND_HPP
    #define SOCCERPLAYGROUND_HPP
    #include <opencv2/opencv.hpp>
    //intialize soccor-playground variables
    double feildLength = 9;
    double feildWidth = 6;
    double goalDepth = 0.6;
    double goalwidth = 2.6;
    double goalAreaLength = 1;
    double goalAreaWidth = 3;
    double penaltyMarkDistance = 1.5;
    double centreCircleDiameter = 1.5;
    double borderStripWidth = 1; 
    double penaltyAreaLength = 2;
    double penaltyAreaWidth = 5;

    //initialize contract pixel(how many pixels equals one meter?)
    int contractPixel = 100;

    //initialize window variables
    int windowWidth = (feildLength + borderStripWidth * 2) * contractPixel;
    int windowLength = (feildWidth + borderStripWidth * 2)  * contractPixel;

    struct MainRectangle {
        cv::Point topLeft;
        cv::Point bottomRight;
        cv::Scalar color;
        int thickness;

        // Constructor to initialize the members
        MainRectangle() : 
            topLeft(borderStripWidth * contractPixel, borderStripWidth * contractPixel),
            bottomRight((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + feildWidth) * contractPixel),
            color(255, 255, 255),  // White color
            thickness(1) {}
    };

    struct leftGoal {
        cv::Point topLeft;
        cv::Point bottomRight;
        cv::Scalar color;
        int thickness;

        // Constructor to initialize the members
        leftGoal() :
            topLeft((borderStripWidth - goalDepth) * contractPixel, (borderStripWidth + (feildWidth - goalwidth) / 2) * contractPixel),
            bottomRight(borderStripWidth * contractPixel, (borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth)  * contractPixel),
            color(255, 255, 0),
            thickness(1) {}
    };

    struct rightGoal {
        cv::Point topLeft;
        cv::Point bottomRight;
        cv::Scalar color;
        int thickness;

        // Constructor to initialize the members
        rightGoal() :
            topLeft((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + (feildWidth - goalwidth) / 2) * contractPixel),
            bottomRight((borderStripWidth + feildLength + goalDepth) * contractPixel, (borderStripWidth + ((feildWidth - goalwidth) / 2) + goalwidth)  * contractPixel),
            color(0, 255, 255),
            thickness(1) {}
    };

    struct leftPenaltyArea {
        cv::Point topLeft;
        cv::Point bottomRight;
        cv::Scalar color;
        int thickness;

        // Constructor to initialize the members
        leftPenaltyArea() :
            topLeft(borderStripWidth * contractPixel, (borderStripWidth + (feildWidth - penaltyAreaWidth) / 2) * contractPixel),
            bottomRight((borderStripWidth + penaltyAreaLength) * contractPixel, (borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth)  * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct rightPenaltyArea {
        cv::Point topLeft;
        cv::Point bottomRight;
        cv::Scalar color;
        int thickness;

        // Constructor to initialize the members
        rightPenaltyArea() :
            topLeft(((borderStripWidth + feildLength) - penaltyAreaLength) * contractPixel, (borderStripWidth + (feildWidth - penaltyAreaWidth) / 2) * contractPixel),
            bottomRight((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + ((feildWidth - penaltyAreaWidth) / 2) + penaltyAreaWidth)  * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct leftGoalArea {
        cv::Point topLeft;
        cv::Point bottomRight;
        cv::Scalar color;
        int thickness;

        // Constructor to initialize the members
        leftGoalArea() :
            topLeft(borderStripWidth * contractPixel, (borderStripWidth + (feildWidth - goalAreaWidth) / 2) * contractPixel),
            bottomRight((borderStripWidth + goalAreaLength) * contractPixel, (borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth)  * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct rightGoalArea {
        cv::Point topLeft;
        cv::Point bottomRight;
        cv::Scalar color;
        int thickness;

        // Constructor to initialize the members
        rightGoalArea() :
            topLeft(((borderStripWidth + feildLength) - goalAreaLength) * contractPixel, (borderStripWidth + (feildWidth - goalAreaWidth) / 2) * contractPixel),
            bottomRight((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + ((feildWidth - goalAreaWidth) / 2) + goalAreaWidth)  * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct midLine {
        cv::Point startPoint;
        cv::Point endPoint;
        cv::Scalar color;
        int thickness;

        midLine() :
            startPoint((borderStripWidth + (feildLength / 2)) * contractPixel, borderStripWidth * contractPixel),
            endPoint((borderStripWidth + (feildLength / 2)) * contractPixel, (borderStripWidth + feildWidth) * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct centerCircle {
        cv::Point center;
        int radius;
        cv::Scalar color;
        int thickness;

        centerCircle() :
            center((borderStripWidth + (feildLength / 2)) * contractPixel, (borderStripWidth + (feildWidth / 2)) * contractPixel),
            radius((centreCircleDiameter / 2) * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct insideCenterCircle {
        cv::Point center;
        int radius;
        cv::Scalar color;
        int thickness;

        insideCenterCircle() :
            center((borderStripWidth + (feildLength / 2)) * contractPixel, (borderStripWidth + (feildWidth / 2)) * contractPixel),
            radius(.08 * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct leftPenaltyMarkCircle {
        cv::Point center;
        int radius;
        cv::Scalar color;
        int thickness;

        leftPenaltyMarkCircle() :
            center((borderStripWidth + penaltyMarkDistance) * contractPixel, (borderStripWidth + (feildWidth / 2)) * contractPixel),
            radius(.08 * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

    struct rightPenaltyMarkCircle {
        cv::Point center;
        int radius;
        cv::Scalar color;
        int thickness;

        rightPenaltyMarkCircle() :
            center((borderStripWidth + (feildLength - penaltyMarkDistance)) * contractPixel, (borderStripWidth + (feildWidth / 2)) * contractPixel),
            radius(.08 * contractPixel),
            color(255, 255, 255),
            thickness(1) {}
    };

#endif //SOCCERPLAYGROUND_HPP