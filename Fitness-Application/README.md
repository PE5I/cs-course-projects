# Fitness-Application
First class assignment on C++ in CPTS_122 from fall 2017. The application implements a basic commandline tracker for diet (calorie) and exercise (number of steps a day) plan.

## Screenshots

![image](https://user-images.githubusercontent.com/34149684/128963888-e02b2874-1679-480b-8594-9b1cc77be696.png)

## Build and Run

To build and run this application, run the following command

* `mkdir build; cmake -B build -S .; cmake --build build`
* `cd build`
* `./fitness_app`

## Notes
Must load the weekly diet plan and the weekly exercise before saving and terminate, otherwise, the previously saved data gets overwritten.
