//
//  main.cpp
//  Two Webcams Golden Master
//
//  Created by Даниил Волошин on 511//17.
//  Copyright © 2017 Даниил Волошин. All rights reserved.
//

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main() {
    
    int i=8; //i is the loop counter
    int w=1; //w is the number-of-saved-images counter
    int q=8; //q defines how often the program skips frames (if q equals 8 then it's pretty much 1 image per second)
    string number = to_string(w);
    
    VideoCapture cap1(0); //reading-from-camera object ("0" for the Logitec camera and "1" for the MacBook camera)
    VideoCapture cap2(1);
    
    VideoWriter writer1; //writing-to-a-file object
    VideoWriter writer2;
    
    string filename1 = "/Users/Kuravasic/Downloads/WebCam Capture/WebCap1.m4v";
    string filename2 = "/Users/Kuravasic/Downloads/WebCam Capture/WebCap2.m4v";
    
    int fcc = CV_FOURCC('m', 'p', '4', 'v'); // here we choose the codec (www.fourcc.org/codecs.php)
    
    double fps = 10;
    
    Size frameSize1(640, 480);
    Size frameSize2(1280, 720);
    
    
    writer1 = VideoWriter(filename1, fcc, fps, frameSize1);
    writer2 = VideoWriter(filename2, fcc, fps, frameSize2);
    
    if (!writer1.isOpened()) {
        cout << "crap((0((00" << endl;
        return -1;
    }
    
    if (!writer2.isOpened()) {
        cout << "crap2((0((00" << endl;
        return -2;
    }
    
    while (true) {
        
        Mat frame1;
        Mat frame2;
        
        cap1.read(frame1);
        cap2.read(frame2);
        
        if (!frame1.empty()) {
            imshow("Webcam1", frame1);
            if (i % q == 0) {
                imwrite("/Users/Kuravasic/Downloads/WebCam Capture/Images 1/frame1-" + number + ".png", frame1);
            }
        }
        
        if (!frame2.empty()) {
            imshow("Webcam2", frame2);
            if (i % q == 0) {
                imwrite("/Users/Kuravasic/Downloads/WebCam Capture/Images 2/frame2-" + number + ".png", frame2);
                w++;
            }
        }
        
        writer1.write(frame1);
        writer2.write(frame2);
        
        i++;
        number = to_string(w);
        
        switch(waitKey(1)){     //wait for 10 ms for the "esc" key to be pressed
            case 27:            //27 because ASCII value for 'esc' is 27
                return 0;
        }
        
        waitKey(33);
    }
    
    
    
    
    
}
