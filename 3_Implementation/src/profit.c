#include"header.h"
int load_demand;
int evearning=0;   
int profit=0;
int earning1; // extra pv power to grid in islanded mode
int earning2;
int pay_to_grid; // net power taken from grid in grid mode
//printf("%d %d",earning1,pay_to_grid);
int scooter_port_inuse;

int earnedbyev(int load_demand){
    evearning=((load_demand*0.001)*5);
    return evearning;
}

int totalprofit(int earning1, int earning2){
    int a=earnedbyev(load_demand);
    profit=a+earning1+earning2;
    printf("Total profit earned %d",profit);
    return profit;
}





