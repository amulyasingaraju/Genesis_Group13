#include<stdio.h>
#include"header.h"





int grid_mode(int pv_power, int load_demand, int PROFITGRID)
{
    
    int earning2 = 0; // earning in grid mode for pv power sending to grid
    int pay_to_grid = 0;

    printf("Currently Grid mode is operating.\n\n");
    printf("Power Used for charging EV is %d Wh.\n\n",load_demand);

   //remaning_grid_power = grid_power - load_demand;

   printf("Power delivered from PV to grid is %d Wh.\n\n",pv_power); // Net metering

   int power_Wh_to_kWh = pv_power * 0.001;   // net metering,total pv power to grid
   earning2 = power_Wh_to_kWh * 3;

   
   // As PV power < load demand
   pay_to_grid = (int)(load_demand * 0.001 * 3) - earning2 ; // EB Bill for power taking from grid - power given to grid
   printf("Net amount to pay to grid is Rs %d",pay_to_grid);
   printf("\n");
   printf("Today's total earning is Rs %d",PROFITGRID+pay_to_grid);
   printf("\n");
   return earning2;

}

