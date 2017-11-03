//
//  main.cpp
//  OpenCV Webcam Capture
//
//  Created by Даниил Волошин on 311//17.
//  Copyright © 2017 Даниил Волошин. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main() {
    
    
    VideoCapture cap(0); //reading-from-camera object ("0" for the Logitec camera and "1" for the MacBook camera)
    VideoWriter writer; //writing-to-a-file object
    
    string filename = "/Users/Kuravasic/Downloads/WebCap1.m4v";
    int fcc = CV_FOURCC('m', 'p', '4', 'v'); // here we choose the codec (www.fourcc.org/codecs.php)
    double fps = 20;
    //Size frameSize(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    Size frameSize2(640, 480);
    
    
    
    writer = VideoWriter(filename, fcc, fps, frameSize2);
    
    if (!writer.isOpened()) {
        cout << "crap((0((00" << endl;
        return -1;
    }
    
    while (true) {
        
        Mat Webcam;
        cap.read(Webcam);
        
        if (!Webcam.empty()) {
            imshow("Webcam", Webcam);
        }
        
        writer.write(Webcam);
        
        switch(waitKey(1)){     //wait for 10 ms for the "esc" key to be pressed
            case 27:            //27 because ASCII value for 'esc' is 27
                return 0;
        }
        
        waitKey(33);
    }
    
    
    
    
    
    
    
    //return 0;
}
