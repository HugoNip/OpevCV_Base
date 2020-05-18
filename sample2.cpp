#include <iostream>
#include <string>
#include <sstream>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

// OpenCV command line parser functions
// Keys accepted by command line parser
const char* keys =
        {
        "{help h usage ? | | print this message}"
        "{@video | | Video file, if not defined try to use webcamera}"
        };

int main(int argc, const char** argv)
{
    cv::CommandLineParser parser(argc, argv, keys);
    // If requires help show
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }

    cv::String videoFile = parser.get<cv::String>(0);
    if (!parser.check())
    {
        parser.printErrors();
        return 0;
    }

    cv::VideoCapture cap; // open the default camera
    if (videoFile != "")
        cap.open(videoFile);
    else
        cap.open(0); // open the camera
    if (!cap.isOpened()) // check if we succeeded
        return -1;

    cv::namedWindow("Video", 1);
    for (;;)
    {
        cv::Mat frame;
        cap >> frame; // get a new frame from camera
        if (frame.empty())
            return 0;
        cv::imshow("Video", frame);
        if (cv::waitKey(30) >= 0) break;
    }

    // Release the camera or video cap
    cap.release();

    return 0;
}