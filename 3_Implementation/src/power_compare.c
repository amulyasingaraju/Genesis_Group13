#include<stdio.h>
#include"header.h"

int grid_power = 110000; // 110 kWh
int islanded_mode(int,int,int);
int grid_mode(int,int,int);

int power_compare(int pv_power,int load_demand,int PROFITGRID)
{
    if(pv_power >= load_demand)
    {
        islanded_mode(pv_power,load_demand,PROFITGRID);
    }
    else
    {
        grid_mode(pv_power,load_demand,PROFITGRID);
    }
}