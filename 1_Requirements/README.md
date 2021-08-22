# REQUIREMENTS

## INTRODUCTION
An EV charging station, also called an EV charger or ELECTRIC VEHICLE SUPPLY EQUIPTMENT (EVSE), is a piece of equipment that supplies electric power for charging plug-in electric vehicles (including hybrids, neighbourhood electric vehicles, trucks, buses and others).
The EV charging station is written in C language with proper testing cases and make file.

## RESEARCH
One of the most important considerations with this project was to ensure EV charging station diversity in location, organization and facility type. With a growing number of local and regional carbon-reduction policies, EV charging stations may be able to benefit from the value of carbon emissions offset by their stations.

## FEATURES
  -	Helps in charging multiple EVs at a time.
  -	EV Charging Station with 5 modular charging ports – 3 Scooters and 2 Cars at a time.
  -	Each charging port provides power output as needed by the vehicle.
  -	System is adaptable to all seasons. 
  -	Charges EV considering the required safety protocols and monitors overcharging of EV as well. 

## OBJECTIVES
 - Clean Air Commitment.
 - Lower cost of driving
 - EVs pave the way to other forms of clean transportation.
 - Electric vehicles support environmental justice.
 - EV charging increases property value.

# SWOT Analysis
 A brief analysis on Strengths, Weaknesses, Opportunities and Threats.
![WhatsApp Image 2021-08-20 at 16 41 32](https://user-images.githubusercontent.com/62830313/130358052-a38e4141-d4a7-4979-a24e-8478bf6e098a.jpeg)

# 4 W's and 1 H
### WHO
Anyone who wants to charge their EVs(Electrical Vehicles).
### WHAT
Sustainable Hybrid EV Charging System.
### WHEN
Can be used in all seasons, in any weather condition.
### WHERE
Public spaces, Petrol Pumps, National and State Highways.
### HOW
Creating a profitable, sustainable energy solution for charging EVs.

## High Level Requirements
|      ID          |Description                          |Status                         |
|----------------|-------------------------------|-----------------------------|
|HR_01|Getting Input from PV       |`Implemented`            |
|HR_02|Check for power consumption of the EV – if more is required, grid can be used.            |`Implemented`|
|HR_03|Cost calculation for charging EV  |`Implemented`|
|HR_04|Profit calculation for plant owner|`Implemented`|
|HR_05|Net metering (feedback to grid)|`Implemented`|
|HR_06|Take power from both solar and grid|`Implemented`|

## Low Level Requirements

|      ID          |Description                          |Status                         |
|----------------|-------------------------------|-----------------------------|
|LR_01| 	Calculation of PV Power        |`Implemented`            |
|LR_02| 	Calculation of load demand            |`Implemented`|
|LR_03| 	Checking power condition (check for mode of operation – islanded/grid) |`Implemented`|
|LR_04| Grid - PV Power < Load ; Take power from grid & Net Metering and Islanded - PV Power >= Load ; Directly power the station & send surplus to grid |`Implemented`|
|LR_05| Calculation of EV Power Consumption   |`Implemented`|  
|LR_06| Calculation of power used in net metering  |`Implemented`|
|LR_07|For charging port 3 scooters, 2 cars ( 3x3 + 2x50 = 109)kWh Max power when all ports are being used. Check whether power is within constraints for each vehicle (for vehicle safety) 	Scooter – 3kWh, Car – 50kWh  |`Implemented`|
|LR_08| 	What is maximum amount of power being produced by PV and how many vehicles can be charged in a day? (Assuming PV Max Power = 120kWh)  |`Implemented`|


