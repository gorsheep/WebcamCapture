# WebcamCapture

Used OpenCV Version: 3.3.0





How to compile:

1) Создать папку (например, "test3"), в неё кинуть два файла: файл с кодом программы (например, "test3.cpp") и файл "CMakeLists.txt"

2) В файле "CMakeLists.txt" должно быть написано примерно следующее:


cmake_minimum_required(VERSION 2.8)
project( test3 )
find_package( OpenCV REQUIRED )
add_executable(test3 test3.cpp )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
target_link_libraries( test3 ${OpenCV_LIBS} )


3) Запускаешь терминал, в нём переходишь в созданную в пункте 1 папку командой:

cd /home/hydro/Desktop/compiling/test3

4) Вводишь команду:

cmake .

5) Вводишь команду:

make

6) Чтобы запустить скомпилированную токмо шо программу (test3 - имя executable файла), вводишь команду:

./test3


