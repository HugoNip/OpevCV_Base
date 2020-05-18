#include <iostream>
#include <string>
#include <sstream>

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

int main() {
    // Read images
    cv::Mat color = cv::imread("../lena.jpg");
    cv::Mat gray = cv::imread("../lena.jpg", cv::IMREAD_GRAYSCALE);

    if(!color.data) // check for incalid input
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // write images
    cv::imwrite("lenaGray.jpg", gray);
    // Get same pixel with opencv function
    int myRow = color.cols - 1;
    int myCol = color.rows - 1;

    cv::Vec3b pixel = color.at<cv::Vec3b>(myRow, myCol);
    std::cout << "Pixel value (B, G, R): (" << (int)pixel[0] << ", " <<
                                               (int)pixel[1] << ", " <<
                                               (int)pixel[2] << std::endl;

    // show images
    cv::imshow("lena BGR", color);
    cv::imshow("lena Gray", gray);

    // wait for any key press
    cv::waitKey(0);

    return 0;
}
