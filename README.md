# Portable Power station

# Introduction:

In a world that grapples with an ever-expanding energy demand, certain regions face unique challenges that demand innovative solutions. Bangladesh, a nation marked by its resilience and rapid development, frequently contends with power crises that impact both urban centers and rural communities. The need for reliable and accessible electricity in this context cannot be overstated.

Our project, the 'Portable Power Station,' takes cognizance of the pressing power issues that prevail in Bangladesh. With its ability to efficiently convert DC voltage to DC and AC voltage as well, our proposed solution emerges as a beacon of hope amidst these challenges. It is tailored to be not just a portable power source but a lifeline for those enduring power shortages.

The 'Portable Power Station' offers the promise of consistent and dependable electricity, whether it's for essential medical equipment in remote clinics, sustaining daily livelihoods in rural areas, or ensuring uninterrupted education in urban centers. By harnessing the power of efficient conversion, we aim to play a pivotal role in mitigating the power crisis that has plagued Bangladesh, ultimately contributing to the nation's development and the well-being of its people.

# Feature:

The aim of our project was to provide power in rural areas where electricity was not readily available.

Our project provided electricity power in two forms which were mostly used:

1. 230V AC, and  
2. 5V DC (USB,) from a single battery or solar panel (any 12V source).

The AC current could be used to power most medium to small devices such as small light bulbs, laptops, small fans, TVs, etc. On the other hand, 5V DC could be used to charge up mobiles or other devices that use USB. It featured a feedback system that maintained steady 5V DC at the output.

Technical details: This project has two parts. The first part is an inverter that generates 230V AC from 12V DC. The second part is a BUCK converter which generates steady 5V DC from 12V DC.

Inverter: The AC current is alternating and always changing direction. So, by arranging two MOSFETs in such a way that one will turn on and supply current in one direction, and after a few moments it turns off and the other MOSFET turns on to supply DC current in the opposite direction - if we can do it 50 times a second, we get basically ac current. But it will be a square wave AC current.

![portable power station-7](https://github.com/user-attachments/assets/416e4c62-42cb-4556-bd29-4c59f0c176c6)


# Square Wave

In order to make it more usable, we can do the following ways:

- The first MOSFET turns on, second one turns off.  
- Then two of them turn off.  
- Then the second one turns on, first one turns off.  
- Then two of them turn off.

The MOSFETs will be controlled by a Mosfet Driver which in this case we will be using BJT as Mosfet Driver. The on/off pulses will be provided by an Arduino.

If we implement this way, we get a modified square wave.
![portable power station-8](https://github.com/user-attachments/assets/7a71d156-caa9-402b-a209-ce99bece9845)


Modified Square wave

After that, the current can be fed to a step-up transformer with appropriate coil ratio and power ratings to get 230V AC.

For the feedback part, the 230V AC can be rectified and the voltage may be stepped down with some voltage dividers and fed back to the Arduino to monitor and make necessary changes to maintain a constant 230V.

Buck converter: The source is 12V DC and the output is 5V DC. So, we need a buck converter.

Our design implements a buck converter that is different from the conventional buck converter. By practical experiment we found N-channel mosfets to be more efficient and reliable so A low side switching buck converter was used. The slight disadvantage of this approach is the floating ground of the load, respect to the original ground. However this does not cause any issue as the operation voltage is relatively low and small gadgets will be powered through this buck converter. Two wires from across the output were run back to the arduino as feedback. The difference between the potentials of those two points must be 5V, and thus the code was written to adjust the duty cycle in such a way that the output terminals have 5V between them.

# Methodology Flowchart :

![portable power station-4](https://github.com/user-attachments/assets/7cf4fd67-fea8-46ae-ad40-557aacfcd294)


# Circuit Diagram:

![portable power station-5](https://github.com/user-attachments/assets/71c9a367-994f-47a3-bf41-1e91cf5f5794)


# Implementation:


![portable power station-8](https://github.com/user-attachments/assets/730d9dfb-7d51-4823-9bd6-5e5fd643a6a3)


# Output Snaps of our project:

![portable power station-9](https://github.com/user-attachments/assets/63e3db19-4380-441c-96df-b7432c4417a3)
![portable power station-10](https://github.com/user-attachments/assets/f3329230-55d9-4725-ae2f-6990d25e8545)


# Output Analysis:

In our project's output analysis, we've successfully derived AC output from a DC 12V lithium-ion battery and maintained a constant DC voltage from the input. The significance of this lies in catering to diverse power needs - delivering versatile 230V AC for various devices and a steady 5V DC for USB-compatible devices, all from a singular 12V DC source, typically a battery or solar panel.

For the inverter part, we used a heavy transformer with center tapped coil and the coil ratio was around 1:20. The push pull configuration generated around  $210\mathrm{V}$  ac. However the output voltage dropped slightly when any load was connected. Also the output waveshape was a square wave. Both of the shortcomings can be overcome by using SPWM, but that is out of the scope of this project.

For the buck converter feedback part, Two terminals from the output 5V side were run through voltage dividers and to the arduino analog pins. As the project is battery powered, as the battery depletes, the input voltage level will also decrease. To combat this, we measured differential voltage across the terminal, not the voltage with respect to the ground which is floating, in this case. The reason for using a voltage divider is that the arduino cannot take more than 5V as input. So we used a 3:1 voltage divider.

Typical lead acid battery voltage can range from 14V to 11V. Our project is technically capable of taking inputs up to  $5^{*}3 = 15\mathrm{V}$ .

So the low side buck converter has a purpose of two fold. First is that it helps to measure the voltage across the load independent of the ground. Second, it keeps the output voltage stable.

Parts and cost estimations:  

<table><tr><td>Components</td><td>Quantity</td><td>Cost (BDT)</td></tr><tr><td>12V battery</td><td>1</td><td>1500</td></tr><tr><td>Wires</td><td></td><td>200</td></tr><tr><td>Inductor</td><td>2</td><td>50</td></tr><tr><td>Resistors</td><td></td><td>20</td></tr><tr><td>Arduino nano</td><td>1</td><td>600</td></tr><tr><td>N channel Mosfet</td><td>5</td><td>250</td></tr><tr><td>Diode</td><td>8</td><td>40</td></tr><tr><td>12V to 240V step-up transformer</td><td></td><td>1000</td></tr><tr><td>n-p-n transistor</td><td>5</td><td>250</td></tr><tr><td>Breadboard</td><td>1</td><td>100</td></tr><tr><td>Soldering iron and other soldering equipment</td><td></td><td>500</td></tr><tr><td>5W 220V light bulb</td><td></td><td>150</td></tr><tr><td>Small 5V light bulb</td><td>2</td><td>40</td></tr><tr><td>Total</td><td></td><td></td></tr></table>

# Discussion:

By doing this project, we were able to learn about the working principles of inverters and buck converters. We gathered practical knowledge about these circuits. However, working with 230V AC was dangerous, so proper precautions were necessary. Also, proper simulations in appropriate software were done to ensure the feasibility of the project. Arduino was used in this project to easily change the generated PWM signals for our desired outputs, which were powered by an external DC source. However, in real life, self-sustaining circuits might be used in place of Arduino, which doesn't require an external power source.
