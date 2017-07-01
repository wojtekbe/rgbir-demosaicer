#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/cudaarithm.hpp>

int main (int argc, char* argv[])
{
    try
    {
        cv::Mat src_host = cv::imread("file.jpg", cv::IMREAD_GRAYSCALE);
        cv::cuda::GpuMat dst, src;
        src.upload(src_host);

        cv::cuda::threshold(src, dst, 128.0, 255.0, cv::THRESH_BINARY);

        cv::Mat result_host;
        dst.download(result_host);

        cv::imwrite("ofile.jpg", result_host);
    }
    catch(const cv::Exception& ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
