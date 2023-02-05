#include <iostream>
#include <opencv2/opencv.hpp>
#include "colors.hpp"
#include "draw_custom_line.hpp"

#include "vector_creation_routines.hpp"

int main(int argc, char *argv[])
{
    cv::Mat blankFrame = cv::Mat::zeros(cv::Size(1000, 600), CV_8UC3);
    cv::Point p1(100,100), p2(400,100), p3(400,500), p4(100,500);
    
    cv::line(blankFrame, p1, p2, colors::red, 1, cv::LineTypes::LINE_4, cv::LineStyles::SOLID);
    cv::line(blankFrame, p2, p3, colors::green, 1, cv::LineTypes::LINE_8, cv::LineStyles::DOTTED);
    cv::line(blankFrame, p3, p4, colors::blue, 2, cv::LineTypes::LINE_AA, cv::LineStyles::DASHED);
    cv::line(blankFrame, p4, p1, colors::yellow, 3, cv::LineTypes::LINE_AA, cv::LineStyles::DASHDOT);

    cv::dashdot_marker_line(blankFrame, p1, p3, colors::brown, 1, cv::LineTypes::LINE_8, 20, cv::MarkerTypes::MARKER_DIAMOND, 10);
    cv::dashdot_marker_line(blankFrame, p2, p4, colors::white, 2, cv::LineTypes::LINE_AA, 30, cv::MarkerTypes::MARKER_TRIANGLE_DOWN, 15);

    cv::imshow("orig", blankFrame);
    
    cv::waitKey();
    cv::destroyAllWindows();

    double start = 10, stop = 0, step = -3;
    auto vec = cplt::arange(start, stop, step);
    for(auto const &el : vec)
        std::cout << el << " ";
    std::cout << std::endl;
}

