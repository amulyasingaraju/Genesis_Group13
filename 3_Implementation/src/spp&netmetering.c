/**
 * @file spp&netmetering.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>


int sp_power;
int calcspp(int pv_power,int load_demand)
{
    if(pv_power > load_demand)  // island Mode check
    {
        sp_power = pv_power - load_demand; // caluculating Surplus Power
    }
    else
    {
        sp_power = 0;
    }

    return sp_power;
}

net_metering(int grid_power, int pv_power)
{
    if(pv_power > )
}