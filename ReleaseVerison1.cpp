//
//  ReleaseVerison1.cpp
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
    

    
    VideoCapture cap1(0); //reading-from-camera object
    VideoCapture cap2(1);
    
    
    for (int i=1; true; i++) {
        
        
        string number = to_string(i);
        
        string filename1 = "/media/hydro/PI/Videos1/Video1-" + number + ".m4v";
        string filename2 = "/media/hydro/PI/Videos2/Video2-" + number + ".m4v";
        
        int fcc = CV_FOURCC('m', 'p', '4', 'v'); // here we choose the codec (www.fourcc.org/codecs.php)
        
        double fps = 10;
        
        Size frameSize1(640, 480);
        Size frameSize2(640, 480);
        
        VideoWriter writer1; //writing-to-a-file object
        VideoWriter writer2;
        
		//constructors
        writer1 = VideoWriter(filename1, fcc, fps, frameSize1);
        writer2 = VideoWriter(filename2, fcc, fps, frameSize2);
        
        
        
        for (int j=1; j<600; j++) {
        
            Mat frame1;
            Mat frame2;
            
            cap1.read(frame1);
            cap2.read(frame2);
            
            writer1.write(frame1);
            writer2.write(frame2);
            
            if (j % 10 == 0) {
                imwrite("/media/hydro/PI/Images1/frame1-" + to_string(60*(i-1)+j/10) + ".jpg", frame1);
                imwrite("/media/hydro/PI/Images2/frame2-" + to_string(60*(i-1)+j/10) + ".jpg", frame2);
            }
        }
        

        
        //destructors
        writer1.release();
        writer2.release();
        
        
        switch(waitKey(1)) {     //wait for 10 ms for the "esc" key to be pressed
            case 27:            //27 because ASCII value for 'esc' is 27
                return 0;
        }
        
        
        waitKey(33);
        
    }
    
    
    
    
    
    
}
