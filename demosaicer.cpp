#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <stdio.h>
#include <unistd.h>

using namespace std;

#define IMG_W 1920
#define IMG_H 1080

cv::Mat load_raw(const char *fname, int size)
{
	uchar* raw_data;
	FILE *fp;

	raw_data = (uchar *)malloc(size);

	fp = (fname ? fopen(fname, "rb") : stdin);

	fread(raw_data, IMG_H, IMG_W*2, fp);

	fclose(fp);
	cv::Mat im(IMG_H, IMG_W, CV_16UC1, raw_data);

	return im;
}

int main (int argc, char* argv[])
{
	try
	{
		cv::Mat img_raw = load_raw(argv[1], IMG_W*IMG_H*2);
		cv::Mat src_host8;
		img_raw.convertTo(src_host8, CV_8UC1, 255.0/1023.0);

		cv::cuda::GpuMat dst, src;
		src.upload(src_host8);

		cv::cuda::demosaicing(src, dst, cv::cuda::COLOR_BayerRG2RGB_MHT);

		cv::Mat result_host;
		dst.download(result_host);

		cv::imwrite("ifile.png", src_host8);
		cv::imwrite("ofile.png", result_host);
	}

	catch(const cv::Exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}

	return 0;
}
