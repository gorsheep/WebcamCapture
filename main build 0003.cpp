//
//  main.cpp
//  FragmentedVideosOCV
//
//  Created by Даниил Волошин on 1811//17.
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
    
    //cout << "FPS:" << endl;

    
    VideoCapture cap1(1); //reading-from-camera object ("0" for the Logitec camera and "1" for the MacBook camera) or vice versa
    VideoCapture cap2(0);
    /*
    cout << cap1.get(CV_CAP_PROP_FPS) << endl;
    cout << cap2.get(CV_CAP_PROP_FPS) << endl;
    
    int x;
    cin >> x;
    */
    
    for (int i=1; true; i++) {
        
        
        
        string number = to_string(i);
        
        string filename1 = "/Users/Kuravasic/Downloads/WebCam Capture/Videos 1/Video1-" + number + ".m4v";
        string filename2 = "/Users/Kuravasic/Downloads/WebCam Capture/Videos 2/Video2-" + number + ".m4v";
        
        int fcc = CV_FOURCC('m', 'p', '4', 'v'); // here we choose the codec (www.fourcc.org/codecs.php)
        
        double fps = 15;
        
        Size frameSize1(640, 480);
        Size frameSize2(1280, 720);
        
        
        VideoWriter writer1; //writing-to-a-file object
        VideoWriter writer2;
        
        writer1 = VideoWriter(filename1, fcc, fps, frameSize1);
        writer2 = VideoWriter(filename2, fcc, fps, frameSize2);
        
        
        
        for (int j=1; j<450; j++) {
            
            Mat frame1;
            Mat frame2;
            
            cap1.read(frame1);
            cap2.read(frame2);
            
            writer1.write(frame1);
            writer2.write(frame2);
            
            /*
            if (j % 10 == 0) {
                imwrite("/Users/Kuravasic/Downloads/WebCam Capture/Images 1/frame1-" + to_string(60*(i-1)+j/10) + ".jpg", frame1);
                imwrite("/Users/Kuravasic/Downloads/WebCam Capture/Images 2/frame2-" + to_string(60*(i-1)+j/10) + ".jpg", frame2);
            }
            */
            
        }
        
        /*
        writer1.release();
        writer2.release();
        */
    
        switch(waitKey(1)) {     //wait for 10 ms for the "esc" key to be pressed
            case 27:            //27 because ASCII value for 'esc' is 27
                return 0;
        }
        
        
        waitKey(33);
        
    }
    
    
    
    
    
    
}
