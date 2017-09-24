# Project 04 Term 2 - PID Controller Project - Control steering of the vehicle.
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

## README
The purpose of this project was to "build a PID controller and tune the PID hyperparameters by applying the general processing flow as described in the lessons," and to "test your solution on the simulator!" The simulator provides cross-track error (CTE), speed, and steering angle data via local websocket. The PID (proportional/integral/differential) controller must respond with steering and throttle commands to drive the car reliably around the simulator track.

## RUNNING THE CODE

Once you have this repository on your machine, cd into the repository's root directory and run the following commands from the command line:
```
> mkdir build
> cd build
> cmake ..
> make
> ./pid
```
> **NOTE**
> If you get any `command not found` problems, you will have to install 
> the associated dependencies (for example, 
> [cmake](https://cmake.org/install/))

If everything worked you should see something like the following output:
```
CTE: 0.1691 Steering Value: 0.122826
 Speed: 42.142742["steer",{"steering_angle":0.1228256,"throttle":0.4}]
CTE: 0.1691 Steering Value: -0.0226594
 Speed: 42.142742["steer",{"steering_angle":-0.0226594,"throttle":0.4}]
CTE: 0.1222 Steering Value: 0.12667
 Speed: 42.147442["steer",{"steering_angle":0.1266702,"throttle":0.4}]
42["steer",{"steering_angle":0.2106444,"throttle":0.2}]
```
You have to run Term 2 simulator and you can see the results in the simulator.

### Parameters discussion
The P, or "proportional", component had the most directly observable effect on the car's behavior. It causes the car to steer proportional (and opposite) to the car's distance from the lane center (which is the CTE) - if the car is far to the right it steers hard to the left, if it's slightly to the left it steers slightly to the right.

The D, or "differential", component counteracts the P component's tendency to ring and overshoot the center line. A properly tuned D parameter will cause the car to approach the center line smoothly without ringing.

The I, or "integral", component counteracts a bias in the CTE which prevents the P-D controller from reaching the center line.

### Parameters Selection
The particle filter met the requirements, which were 0.2 meter in error for x and y translations, 0.004 rad in error for yaw, and 52 seconds of runtime for the particle filter. Please note that due to the random numbers generated in certain portions of my approach (for the Gaussian distributions), results may vary slightly. Error below is cumulative mean weighted error.

**I & D Parameter Removed**
Removed I & D parameters to observe the effect of P parameter only and found that car goes out of the track with in minutes.

**D Parameter Aded and Only I parameterr Removed**
Next step added D parameters to observe its efffect on the results and it helped in car reaching the center line. I parameter didn't have much effect on the output and it only helps in moving the car to to center line during sharp turns.


**Choose parameters** 
Hyperparameters were tuned manually.This was necessary because the narrow track left little room for error, and when attempting to automate parameter optimization (such as Twiddle) it was very common for the car to leave the track, thus invalidating the optimization.
I also controlled the car throttle and speed value using the steering angle. 
Increase in the steer value takes away car from center lane.
Thus, controlling speed and throttle value moves car towards center in sharp turns. 
Also, PID controller is able to reduce CTE and car moves towareds the center lane with controlled speed and throttle.
            



