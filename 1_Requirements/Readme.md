# REQUIREMENTS

## INTRODUCTION
E-mobility is emerging as one of the fastest mode of trans-portation as it serves zero emission without the use of anyfossile fuel. The cleaner and greener mobility will also     
servein reducing the CO2 emission content in the atmosphereand help to reduce global warming. However, to make thee-mobility grow faster the production and management 
of electricity is of the main objective. The main demand of the electric vehicle is the charging methods and its infrastructure.
As a daily routine, most people will like to have their vehicle charged at the beginning of the day. The preferable location of the charging stations are most likely either near 
to their own residence or at their work places. Apart from it charging stations at the common public places will be popular. Also,the time of the charging of the vehicles is also 
an important criteria. Most of the people won’t like to stop for 2-3 hours for charging of the vehicles. Thus the methods of the charging stations will need to deploy in a 
organised manner such that people could charge at minimum possible time period.
In the intercity conditions, the demand of the charging will remain obviously very high most of the times. Thus to deliver optimum power to all the stations at high rate 
is a challenging task. In the outskirts of the city, the demand might not remainas high as compared to the intercity, but installation of the public charging interface at such 
locations must be deployed with utmost planning. The main responsiblity is to create Charging Structure Infrastructure.
An EV charging station, also called an EV charger or ELECTRIC VEHICLE SUPPLY EQUIPTMENT (EVSE), is a piece of equipment that supplies electric power for charging plug-in electric 
vehicles (including hybrids, neighbourhood electric vehicles, trucks, buses and others).
The EV charging station is written in C language with proper testing cases and make file.

## RESEARCH
The government has set the target of achieving 100% Electric vehicles by 2030. Manufacturing and putting the electric cars on road is the vision to make India pollution free along 
with saving billions of dollars in fuel cost and creating new job opportunities.And to meet this goal government have to create Charging Structure Infrastructure.
Automotive Mission Plan (AMP) has been finalised jointly by Government of India and Indian Automotive Industry. The vision of AMP 2026 is, By 2026, the Indian Automotive industry 
will be among the top three of the world in engineering, manufacture and export of vehicles and components, and will encompass safe, efficient and environment friendly conditions 
for affordable mobility of people and transportation of goods in India comparable with global standards growing in value to over 12% of India’s GDP and generating an additional 65 
million jobs.
![pic](https://github.com/amulyasingaraju/SDLC_13_GoGreen/blob/main/1_Requirements/1-s2.0-S1364032114001920-gr8.jpg)
Electric car uses alternate fuel electricity instead of petrol or diesel. There is a growing acceptance for hybrid and electric cars in the country and more and more manufacturers 
are entering this niche segment with an express objective of lowering the fuel import bill and running cost of vehicles. Conversion of vehicles to electric vehicles has a 
potential to save fossil fuels worth about $100 bn annually, which in turn would save the country precious foreign exchange, prevent the dependence on imported petroleum products 
and reduce the pollution in cities by 80-90%.

By the year 2030, the Indian Government wants India to be 100%, electric vehicle nation.

India spent Rs 4.7 Lakh Crores in 2016-17 in importing crude oil. Electric Vehicles will help lower the bill.

Every car sold in India from 2030 will be electric, under new government plans.

India aims to become a 100% electric vehicle nation by 2030. The National Electric Mobility Mission Plan (NEMMP) targets seven million electric and hybrid vehicles by 2020.

One of the most important considerations with this project was to ensure EV charging station diversity in location, organization and facility type. With a growing number of local 
and regional carbon-reduction policies, EV charging stations may be able to benefit from the value of carbon emissions offset by their stations.

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

