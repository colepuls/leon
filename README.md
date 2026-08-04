# Leon — Quadruped 3-DOF Robot Dog

Embedded C++ | ESP32 | Robotics | Kinematics | Mechanical Design

Leon is a custom quadruped robot dog designed and built from the ground up using an ESP32, high-torque servo motors, 3D-printed components, carbon-fiber links, and custom control software.

The project is currently in active development. One complete three-degree-of-freedom leg is assembled and operational, with controller input, servo control, kinematic foot positioning, and programmable foot trajectories.

## Demo Video

[View the single-leg movement demo](assets/IMG_1720.mov)

## Overview

The main focus of Leon is developing the mechanical, electrical, and software systems required to control a complete quadruped robot.

Each leg uses three independently controlled servo motors:

* One hip servo for lateral leg movement
* Two servo motors controlling a five-bar linkage
* Three total degrees of freedom per leg

The five-bar linkage controls the foot position within a two-dimensional plane, while the hip servo moves the entire leg laterally.

The current prototype consists of one fully assembled and functional leg. The remaining three legs, central chassis, full electrical system, and coordinated walking gaits are still under development.

## Current Status

The following functionality is currently working:

* One complete three-degree-of-freedom leg
* ESP32-based control system
* PCA9685 PWM servo control
* Xbox controller input through Bluepad32
* Individual servo calibration and movement
* Kinematic foot-position control
* Direct coordinate-based foot commands
* Linear foot movement
* Triangle foot trajectories
* Cycloid foot trajectories
* Adjustable movement speed and resolution
* 3D-printed servo mounts and linkage components
* Carbon-fiber linkage tubes

Leon is not yet capable of standing or walking on four legs.

## Mechanical Design

Each leg consists of:

* One actuated hip joint
* Two actuated five-bar linkage joints
* Three high-torque digital servo motors
* 3D-printed structural components
* Carbon-fiber linkage tubes
* Heat-set inserts, bearings, and mechanical fasteners

The five-bar linkage allows both primary leg actuators to remain near the robot's body instead of placing additional weight farther down the leg.

This reduces leg inertia and provides controlled foot movement through a defined two-dimensional workspace.

## Leg Control

The leg is controlled using target foot coordinates.

```cpp
moveLegToPos(leg, x, y);
```

The control system converts the requested foot position into the corresponding servo angles required by the five-bar linkage.

The current movement system supports:

* Direct foot-position commands
* Controlled leg extension and retraction
* Linear movement between two coordinates
* Triangle foot paths
* Cycloid foot paths
* Manual controller-based movement
* Individual servo testing and calibration

## Foot Trajectories

### Triangle Trajectory

The triangle trajectory moves the foot through three primary phases:

1. Move backward along the ground
2. Lift the foot upward and move it forward
3. Lower the foot back to the ground

This trajectory provides a simple path for early gait and linkage testing.

### Cycloid Trajectory

The cycloid trajectory creates a smoother swing motion using trigonometric position equations.

```text
theta = 2πu

x = x_start + (L / 2π)(theta - sin(theta))

y = ground_y - (H / 2)(1 - cos(theta))
```

Where:

* `u` is the normalized progress through the step
* `L` is the step length
* `H` is the step height
* `ground_y` is the normal foot height

The cycloid path provides smoother acceleration and deceleration than a basic triangular trajectory.

## Controller Input

Leon currently uses an Xbox controller connected to the ESP32 over Bluetooth through Bluepad32.

The controller is used to test:

* Individual servo movement
* Leg extension and retraction
* Hip movement
* Stored foot positions
* Triangle trajectories
* Cycloid trajectories
* Servo calibration
* Emergency position resets

The controller mappings may change as development continues.

## Electronics

The current control and power system includes:

* ESP32 development board
* PCA9685 16-channel PWM servo driver
* High-torque digital servo motors
* Milwaukee M12 battery
* High-current servo voltage regulator
* Separate voltage regulation for control electronics
* Shared electrical ground between the ESP32 and servo system

The ESP32 processes controller input, calculates target leg positions, generates foot trajectories, and sends servo commands through the PCA9685.

The completed quadruped will use twelve servo motors, with three servos controlling each leg.

## Software

Leon is programmed in Embedded C++ using the Arduino framework and PlatformIO.

### Main Technologies

* Embedded C++
* ESP32
* Arduino framework
* PlatformIO
* Bluepad32
* Adafruit PCA9685 PWM Driver
* I2C
* PWM servo control
* Five-bar linkage kinematics
* Fusion 360
* KiCad

## Safety

High-torque servo motors can move suddenly and produce significant force.

During development:

* Keep hands clear of moving linkages
* Test new movements at reduced speeds
* Enforce servo and joint limits in software
* Support the robot above the ground during testing
* Disconnect power before making mechanical adjustments
* Verify battery and voltage-regulator connections before operation
* Use a shared ground between the control and servo power systems
* Stop movement immediately if a linkage binds or reaches an unsafe position

## Development Progress

```text
[✓] Design the first three-degree-of-freedom leg
[✓] Print and assemble the first leg
[✓] Install carbon-fiber linkage tubes
[✓] Control individual servo motors
[✓] Connect an Xbox controller
[✓] Implement coordinate-based foot positioning
[✓] Implement linear foot movement
[✓] Implement triangle foot trajectories
[✓] Implement cycloid foot trajectories
[ ] Complete the remaining three legs
[ ] Complete the central chassis
[ ] Integrate all twelve servo motors
[ ] Finalize the power-distribution system
[ ] Implement coordinated four-leg control
[ ] Achieve stable standing
[ ] Implement standing and crouching motions
[ ] Implement a walking gait
[ ] Implement a trotting gait
[ ] Add IMU-based body stabilization
[ ] Add autonomous movement
```

## Planned Features

Future development includes:

* Completing all four robotic legs
* Building and assembling the central chassis
* Integrating all twelve servo motors
* Coordinating multiple legs simultaneously
* Full-body standing and crouching
* Static walking gaits
* Trotting and dynamic gait development
* Body-position control
* IMU-based stabilization
* Improved servo calibration tools
* Custom power-distribution hardware
* Custom printed circuit boards
* Sensor integration
* Autonomous movement and obstacle detection

## Project Goals

The long-term goal is to create a fully functional quadruped robot capable of:

* Standing under its own weight
* Maintaining a stable body position
* Walking with coordinated leg movements
* Trotting using dynamic gait patterns
* Receiving wireless controller commands
* Adjusting foot placement through kinematic control
* Responding to IMU and sensor feedback
* Navigating its environment autonomously

## License

This project is currently under active development. Licensing information will be added in a future update.
