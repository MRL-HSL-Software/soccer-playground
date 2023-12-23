//-- Include MRL HSL Projects
# ifndef MRL_HSL
    # define MRL_HSL 1
    # pragma message \
        "This Project Must be Included in MRL Projects. You are Using It as Standalone Project"
    # pragma message \
        "Compiling without MRL Support."
# else
    # pragma message \
        "MRL Sub Project Configured and Initialized Successfully, Compiling with MRL Support"
# endif // MRL_HSL
//-- MRL HSL Soccer Playground Configs
# ifndef MRL_SOCCER_PLAYGROUND_CONFIGS
    /**
     * @file Configs.hpp
     * @author Mobina Abforoosh (mobinaabf@gmail.com)
     * @author Amir Yusefian (amiryn996@gmail.com)
     * @author Erfan Zarabadi (mohammadspace39@gmail.com)
     * @author Parsa Karbasi (ijackgonjishke@gmail.com)
     * @author Alireza Mortezaei (alirezamortezaei50@gmail.com)
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Soccer Filed Preview Configurations
     * @version 1.0
     * @date 2023-12-21
     */
    # define MRL_SOCCER_PLAYGROUND_CONFIGS
    //-- Define Project Version
    # define PROJECT_VERSION "1.0"
    //-- Define Playground Dimensions (Mobina Abforoosh)
    # define GOAL_DEPTH 0.6                 //-- Goal Depth in Meters
    # define GOAL_WIDTH 2.6                 //-- Goal Width in Meters
    # define GOAL_HEIGHT 1.2                //-- Goal Height in Meters (Not Used)
    # define FIELD_WIDTH 6.0                //-- Field Width in Meters
    # define FIELD_LENGTH 9.0               //-- Field Length in Meters
    # define GOAL_AREA_WIDTH 3.0            //-- Goal Area Width in Meters
    # define GOAL_AREA_LENGTH 1.0           //-- Goal Area Length in Meters
    # define BORDER_STRIP_WIDTH 1.0         //-- Border Strip Width in Meters
    # define PENALTY_AREA_WIDTH 5.0         //-- Penalty Area Width in Meters
    # define PENALTY_AREA_LENGTH 2.0        //-- Penalty Area Length in Meters
    # define PENALTY_MARK_DISTANCE 1.5      //-- Penalty Mark Distance in Meters
    # define CENTER_CIRCLE_DIAMETER 1.5     //-- Center Circle Diameter in Meters
    # define SCALE 170                      //-- Define Playground View Scale
    //-- Include OpenCV HighGUI
    # ifndef OPENCV_HIGHGUI_HPP
        # include <opencv4/opencv2/highgui.hpp>
    # endif // OPENCV_HIGHGUI_HPP
    //-- Include OpenCV Image Processing
    # ifndef OPENCV_IMGPROC_HPP
        # include <opencv4/opencv2/imgproc.hpp>
    # endif // OPENCV_IMGPROC_HPP
    //-- Include X11 Library
    # ifndef _X11_XLIB_H_
        # include <X11/Xlib.h>
    # endif // _X11_XLIB_H_
    //-- Include Necessary Libraries
    # include <vector>
    //-- Color of Playground Opponent Goal Area (Erfan Zarabadi)
    # define OPPONENT_GOAL_AREA_COLOR cv::Scalar(0, 255, 255)
    //-- Color of Playground Team Goal Area (Erfan Zarabadi)
    # define TEAM_GOAL_AREA_COLOR cv::Scalar(255, 255, 0)
    //-- Color of Playground Background (Erfan Zarabadi)
    # define BACKGROUND_COLOR cv::Scalar(12, 22, 0)
    //-- Color of Playground Lines (Erfan Zarabadi)
    # define LINE_COLOR cv::Scalar(200, 200, 200)
    //-- Window Name
    # define WINDOW_NAME "Soccer Playground"
    //-- Playground Line Thickness
    # define LINE_THICKNESS 2
    //-- Playground Line Type
    # define LINE_TYPE cv::LINE_AA
    //-- Playground Line Shift
    # define LINE_SHIFT 0
    //-- Playground Circle Radius
    # define CIRCLE_RADIUS 4
# endif // MRL_SOCCER_PLAYGROUND_CONFIGS
