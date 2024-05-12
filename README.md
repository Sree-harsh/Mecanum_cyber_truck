# MechanoTesla - The Desi Cybertruck 

## Table of Contents
- [Introduction](#introduction)
- [Project Overview](#project-overview)
- [Design and Components](#design-and-components)
- [Remote Interface](#remote-interface)
- [Frontal Area Calculation](#frontal-area-calculation)
- [Working Principle](#working-principle)
- [Budget Details](#budget-details)
- [Project Contribution](#project-contribution)
- [Wheel Dynamics](#wheel-dynamics)
- [User Guide](#user-guide)
- [Working Video](#working-video)
- [References](#references)
- [Conclusion](#conclusion)

## Introduction
In an era of advancing technology and increasing environmental 
consciousness, the development of Electric Vehicles (EVs) has 
garnered significant attention. Our group embarked on a journey to 
contribute to this domain by designing and developing a mini EV 
prototype. This report encapsulates the key components, design 
features, working principle, and functionalities of our project.
## Project Overview
Our project focuses on the creation of a mini EV prototype, inspired by 
the innovative design of the  Tesla Cybertruck  . This prototype 
demonstrates the integration of modern technologies such as  3D 
printing  , microcontroller systems, and wireless communication. The 
design ethos of the Cybertruck permeates our prototype, combining 
rugged durability with futuristic appeal.

## Design and Components
<p align="center">
<img width="300" alt="1" src="https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/fb95d617-5f2a-4818-b572-e10b3baa2136">
</p>

- **Chassis and Body**:  To enhance maneuverability, our prototype is equipped with 
four mecanum wheels. These specialized wheels, with their unique roller 
arrangement, allow for omnidirectional movement, enabling the vehicle to move 
smoothly in any direction with minimal effort.

<p float="left">
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/1de701c8-329d-4f40-9bff-b5cb770ef579" height="210" width="210" />
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <img src="https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/5b519ad5-1c64-4a30-b8c6-d11fc44cc54c" height="210" width="210" />
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <img src="https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/e2407ff3-cf97-4388-b4dc-1b09531809e3" height="210" width="210" />
</p>

- **Motor System**:  Four motor are integrated into the chassis to drive the wheels, ensuring optimal 
performance and maneuverability reminiscent of the Cybertruck's robust 
drivetrain.

<p align="center">
<img width="300" alt="1" src="https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/5fe2aa96-43be-4ca5-89f3-d86421f83245">
</p>


- **Microcontroller Unit**: The ESP32 microcontroller serves as the brain of our prototype, housing the code necessary to drive the wheels. Drawing parallels to Tesla's innovative approach, we utilize HTML to program the motion of the wheels according to given commands.

- **Power System**: Powering our EV is a lithium-ion battery, securely housed within a custom battery holder integrated into the chassis. This setup ensures a reliable power source, echoing the efficiency and sustainability of Tesla's energy solutions. Operating voltage - 8 - 12 V.

## Remote Interface
We developed an intuitive web-based remote control interface accessible via a mobile device. This interface allows users to easily maneuver the robot in any direction using simple touch gestures.

<p align="center">
<img width="300" alt="1" src="https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/1149982b-db8a-4e10-8d71-43327cca1e00">
</p>



## Frontal Area Calculation

<p align="center">
<img width="500" alt="1" src="https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/2e95b4a6-dee6-4bde-97ac-473631cab3c1">
</p>

<p align="center"><strong>Frontal Area of Chassis Body - 39986.09 mm^2</strong></p>


## Working Principle
The mini EV prototype operates on the principle of electric propulsion. The ESP32 microcontroller communicates with the motor drivers, controlling the speed and direction of each wheel. When a connection is established through the switches or remote WiFi control, signals are sent to the microcontroller, triggering the desired actions. The lithium-ion battery provides the necessary electrical energy to power the motors, enabling the vehicle to move forward, backward, or turn as instructed.

## Budget Details
| Sl No. | Component   | Specification | Cost (in Rupees) |
| -------- | ---------- |---------|---------|
| 1 | Motor | BO Motor | 4 x 68 = 272 |
| 2 | Motor Driver | L298 Motor Driver | 2 x 140 = 280 |
| 3 | MicroController | Esp-32 | 1 x 460 = 460 |
| 4 | Battery | Li-ion Battery | 3 x 90 = 270 |
| 5 | Wheels | Mecanum wheels (with Couplers) | 349.5 x 4 = 1389 |
| 6 | 3D- Printed Chassis | \- | 1 x 250 = 250 | 
| 7 | Switch | \- | 1 x 10 = 10 | 
|8 | Battery Holder | \- | 1 x 40 = 40 |
| 9 | Bread Board | \- | 1 x 60 = 60 |
| 10     | Jumper Wire | \-            | 80               |
| 11     | Wooden Base | \-            | \-               |
| Total  |             |               | 3111             |  

## Project Contribution
-  [**Phanendra Sree Harsh Kowdodi :**](https://github.com/Sree-harsh)  Engineered the core circuitry of the 
 vehicle, assembled the chassis, wrote the code for interface between web 
 application based remote and tuned the wheel dynamics accordingly 
 establishing connections between the ESP32 microcontroller and motor 
 drivers  .
- [**Sai Ram Senapati :**](https://github.com/Sai1Ram)  Developed the web application code,  enabling remote 
control  and monitoring of the vehicle through a user-friendly  interface. 
- [**Arpit Mohanty:**]()  Developed the  code for the ESP32 microcontroller, 
implementing WiFi connectivity  . 
Developed the project report describing our mini-project prototype.
- **Kuladeep Punagani :**   Brought new space saving and efficient ideas to the 
team with respect to chassis assembly and  created the CAD design for 3D 
printing, translating conceptual ideas into a tangible chassis and body for 
the vehicle.
- [**C.S.T Ganesh :**](https://github.com/ganesh10092003)  Contributed in designing the software CAD model of the 
CyberTruck like Body, improving the overall aesthetics of the project and conducted the frontal area calculation.
  
## Wheel Dynamics
Mecanum wheels, also known as Ilon wheels, are a type of wheel designed 
for omnidirectional movement. They are equipped with a series of rollers 
set at 45-degree angles to the main rotational axis of the wheel. By varying 
the speed and direction of each wheel independently, a vehicle equipped 
with Mecanum wheels can move in any direction and rotate smoothly. This 
is achieved through the vector sum of the forces produced by the individual 
wheels. Mecanum wheels are often used in robotics and industrial 
applications to enable agile and precise maneuverability

\
![image](https://github.com/Sree-harsh/Mecanum_cyber_truck/assets/98598677/931f586c-afd4-4cfa-8fd5-f41623472f15)

## User Guide
**Enabling WiFi:** \
&emsp;● Power on the switch of the vehicle to enable its WiFi. \
&emsp;● The ESP32 will create a WiFi network named "MyWifiCar" with the password "12345678". \
**Connecting to WiFi:** \
&emsp;● On your mobile device, go to the WiFi settings. \
&emsp;● Look for the network named "MyWifiCar" and connect to it using the password "12345678".\
**Accessing the Control Interface:** \
&emsp;● Open a web browser on your mobile device. \
&emsp;● Enter the IP address "192.168.4.1" in the address bar and press enter. \
Now you can control the motion of the vehicle by using the interface \
For Example : For the forward motion of the car press the up arrow and for the side motion of the car press the left or right arrow.
## Working Video
[Demo Video 1](https://youtu.be/cotb4gBEJ-s)\
[Demo Video 2](https://youtu.be/eIGzKlvymAQ)

## References
Wheels and coupler buying [link](https://robu.in/product/80mm-a-mecanum-wheel-compatible-with-6-7mm-coupling-pack-of-4-yellow/)
and link to Reference [Video](https://youtu.be/l7Ty6SZdKPI?si=3cz-H5bShgYtAUTb) .

## Conclusion
In conclusion, our mini EV prototype represents a harmonious blend of 
innovative design, advanced technology, and sustainable principles. 
Inspired by the trailblazing spirit of Tesla, we have created a prototype 
that not only showcases the potential of electric vehicles but also pays 
homage to the iconic Cybertruck. As we continue to refine and expand 
our project, we remain committed to driving progress in the field of 
electric mobility.
