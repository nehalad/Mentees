                   .:                     :,                                          
,:::::::: ::`      :::                   :::                                          
,:::::::: ::`      :::                   :::                                          
.,,:::,,, ::`.:,   ... .. .:,     .:. ..`... ..`   ..   .:,    .. ::  .::,     .:,`   
   ,::    :::::::  ::, :::::::  `:::::::.,:: :::  ::: .::::::  ::::: ::::::  .::::::  
   ,::    :::::::: ::, :::::::: ::::::::.,:: :::  ::: :::,:::, ::::: ::::::, :::::::: 
   ,::    :::  ::: ::, :::  :::`::.  :::.,::  ::,`::`:::   ::: :::  `::,`   :::   ::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  :::::: ::::::::: ::`   :::::: ::::::::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  .::::: ::::::::: ::`    ::::::::::::::: 
   ,::    ::.  ::: ::, ::`  ::: ::: `:::.,::   ::::  :::`  ,,, ::`  .::  :::.::.  ,,, 
   ,::    ::.  ::: ::, ::`  ::: ::::::::.,::   ::::   :::::::` ::`   ::::::: :::::::. 
   ,::    ::.  ::: ::, ::`  :::  :::::::`,::    ::.    :::::`  ::`   ::::::   :::::.  
                                ::,  ,::                               ``             
                                ::::::::                                              
                                 ::::::                                               
                                  `,,`


https://www.thingiverse.com/thing:1718984
RobotArm by ftobler is licensed under the Creative Commons - Attribution - Non-Commercial license.
http://creativecommons.org/licenses/by-nc/3.0/

# Summary

This is a 3D Printable Robot Arm. It may need a bit more time to build one, than your normal weekend Project. But the build process is one thing, the application environment the other. And that is what it is all about. Learning, combining and developing custom applications.
<b>If you make a derivative, please only upload the parts you changed. Thanks.</b>

<h2>Hardware</h2>
The design goal for me was to build a Robot, which is stiff and strong, but still small and easy to handle. I used the common NEMA17 Step Motors, which provide enough power for fast movements and high precision. 
Almost every moveable joint has at least one ball bearing to reduce friction, overall stability and accuracy. The robot is designed to have a low center of mass.
The robot is powered over a Computer Power Supply (12V).

The gripper is easy to replace and is held horizontally in every position, which simplifies programming and also reduces the cost and complexity of additional axies.
Most parts have a industrial look like cast Iron parts.

<h2>Software</h2>
<b>Software is now on Github here: https://github.com/ftobler/robotArm/</b>

The control system uses an Arduino Mega with a RAMPS 1.4 Board and A4988 Drivers. I provide a solid and working programming base for the Arduino, which handles the Interpolation of the stepper motors, makes all geometric calculations and smooth accelerations. It can handle some sort of GCODE communication over Serial.

The software can be directly used without modifying or additional hardware like sensors can be added.
To get you started, I have a simple Interface for your Windows Computer, which has a sequencer and manual control options built in.

<b>You should already have some decent programming skills to modify and use the Software.</b> I am recommending this, because in my opinion programming is a key part of using a robot. Without it you can only scratch the surface of what's really possible.

<h2>Assembly</h2>
There are multiple versions of the big Gears. You may want to print them multiple times, if needed to reduce the gear slack of the rotational axis to a minimum. Depending on how high your Stepper Motor is, choose an appropriate leg height. Use Superglue to fix the bearings, if necessary. I have not cut any threads in the plastic. With PLA (maybe also others) you can 'melt' your thread through friction in, but you might want to drill the holes out a bit.

The Wiring of the Robot is not different from a 3D Printer that uses a RAMPS board. Use the official documentation: http://www.reprap.org/wiki/RAMPS_1.4

You can find details about the dimensions in 'doc2.pdf'

<h2>Video</h2>
I made a 3D animation, which gives you a good technical overview and a I show a simple application in another video.
Animation: https://youtu.be/-LztK9TKcZk
Actual Robot: https://youtu.be/HLlylJr_Vs4

# Print Settings

Printer: RF1000
Rafts: No
Supports: No
Resolution: 0.2mm
Infill: about 15%

Notes: 
Printed in clear PLA. 

Please look for a tight fit for the gears, there are multiple versions available.

# How I Designed This

<h2>Turntable</h2>
One of the most critical parts of my design is the turntable. It uses multiple steel bearings.
A large thrust bearing is used to reduce flex in the design. Because 3D Printed parts are softer than metal, You might need bigger contact areas. The fully extended robot arm on top of it multiplies every gear and bearing tolerance you have.

![Alt text](https://cdn.thingiverse.com/assets/3b/e0/e0/c6/17/DSC_0497.JPG)
the turntable is one of the most critical parts

![Alt text](https://cdn.thingiverse.com/assets/44/01/a3/b9/c8/DSC_0495.JPG)
View of the large Thrust Bearing. Since it consists of loose parts There is a bolt and two more bearings. (Thrust Bearing 25x42x11mm (51105))

![Alt text](https://cdn.thingiverse.com/assets/8e/ea/09/a9/44/base.png)
Base bearings detail view.

<h2>Drawings</h2>

![Alt text](https://cdn.thingiverse.com/assets/3c/2d/57/bb/ce/detail.png)
detail drawing of the Robot. RobotArm is shown in Endstop Position

![Alt text](https://cdn.thingiverse.com/assets/e0/01/21/fc/b2/typicalEnvironment.png)
Topology of an typical Robot Environment. The Robot normally is in the center of everything and every station/machine is aligned radially. This makes sense, because the robot rotates and can reach everything relatively easy.

![Alt text](https://cdn.thingiverse.com/assets/53/a9/dc/c8/3c/DSC_0503.JPG)
some of the small ball bearings I used. (Bearing 4x13x5mm (624zz) and Flanged Bearing 13x6x5mm (F686zz))

<h2>GCODE</h2>

A valid gcode command looks like <code>G1 X0 Y120 Z120</code>
There have to be spaces in between.
<ul>
<li><code>G0</code>=<code>G1</code>: Move <code>XYZ</code> in mm (cartesian), <code>F</code> in mm/s. Always uses Absolute coordinates. Unlike 3D Printers, there is no E-Axis. On every move there is an acceleration and deacceleration.</li>
<li><code>G4</code>: Dwell / Sleep <code>T</code> in milliseconds</li>
<li><code>M3</code>: Close Gripper / Aux Motor <code>T</code> in Steps. Cannot move simultaneously to <code>G</code></li>
<li><code>M5</code>: Open Gripper / Aux Motor <code>T</code> in Steps. Cannot move simultaneously to <code>G</code></li>
<li><code>M17</code>: Enable Stepper Motors, also Enables Fan</li>
<li><code>M18</code>: Disables Stepper Motors, also Disables Fan with delay</li>
<li><code>M106</code>: Enables Fan</li>
<li><code>M106</code>: Disables Fan</li>
</ul>

<h2>Desktop Software</h2>
I wrote a simple desktop application to control the robot. Clearly, this could be extended to a very big software project. So it provides only simple operations.

RobotArm_Software_v2.zip contains some bugfixes which includes some connection problems.

The software is written in Delphi

![Alt text](https://cdn.thingiverse.com/assets/94/5a/52/fd/3a/screenshot.png)
Softwareinterface

<h2>Nuts and Bolts</h2>
This is a <i>rough</i> count without warranty. I counted only the ones on the robot. So I recommend buying more than listed. Please add as much washers as needed, maybe buy different sizes. Washers and screws who are in contact to a bearing are only allowed to touch the inside rotary part.

- 16x M3x6
- 21x M3x8 (3x used as set screws)
- 4x M3x10 
- 2x M3 Washer (large for gripper)
- 4x M3 Nut 
  
- 6x M4x10
- 11x M4x16 
- 2x M4x25 
- 14x M4 Washer (small enough for Bearing) 
- 8x M4 Nut
 
- 12x M6 Washer (small enough for Bearing) 
- 3x M6 Nut
- 3x M6 Self Locking Nut
- 3x M6x45
- 1x M6x80mm  Threaded Rod