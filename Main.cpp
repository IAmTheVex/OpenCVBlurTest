#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

#define BLUR_RATIO 30

int main() {
    Mat image;
    Mat grayImage;
    Mat bluredImage;

    image = imread("res/tits_input.jpg", IMREAD_COLOR);
    if (!image.data) {
        cout << "Could not open the image file" << endl;
        return -1;
    }
    else {
        int height = image.rows;
        int width = image.cols;

        cvtColor(image, grayImage, COLOR_BGR2GRAY);

        blur(image, bluredImage, Size(BLUR_RATIO, BLUR_RATIO));

        namedWindow("Display window", WINDOW_AUTOSIZE);
        imshow("Display window", image);

        namedWindow("Gray Image", WINDOW_AUTOSIZE);
        imshow("Gray Image", grayImage);
        

        namedWindow("Blured Image", WINDOW_AUTOSIZE);
        imshow("Blured Image", bluredImage);

        waitKey(0);
        
        image.release();
        grayImage.release();
        return 0;
    }

	return 0;
}