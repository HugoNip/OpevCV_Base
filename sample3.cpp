#include "opencv2/opencv.hpp"

int main (int, char** argv)
{
    // create our writer
    cv::FileStorage fs("test.yml", cv::FileStorage::WRITE);
    // save an int
    int fps = 5;
    fs << "fps" << fps;
    // Create some mat sample
    cv::Mat m1 = cv::Mat::eye(2, 3, CV_32F);
    cv::Mat m2 = cv::Mat::ones(3, 2, CV_32F);
    cv::Mat result = (m1 + 1).mul(m1 + 3);
    // write the result
    fs << "Result" << result;
    // release the file
    fs.release();

    cv::FileStorage fs2("test.yml", cv::FileStorage::READ);
    cv::Mat r;
    fs2["Result"] >> r;
    std::cout << r << std::endl;

    fs2.release();

    return 0;
}

