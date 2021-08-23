#include<stdio.h>
#include<time.h>
#include"header.h"

    int pv_voltage;
    int pv_current;
    int pv_power;
    int load_demand =0; //amount of power required to charge all EV at a perticulartime
    int port[5];
    int select;
    int PROFITGRID = 0;

int power_calculation(int pv_voltage, int pv_current)
{
        pv_power = pv_voltage * pv_current;
        printf("Power Produced by PV is %d Wh.\n\n",pv_power);
        return pv_power;
}

void wait(int wait)
{
	int now=time(NULL);
	int later=now+wait;
	while(now<=later)
	{
		now=time(NULL);
	}
}

int user_input()
{   // TO take Pv Parameter as input
      printf("\t\t\t\t\t**** Owner Screen ****\n\n");

    printf("Dear User, Please provide PV Data.....\n\n");
    printf("Your maximum PV Power Capacity is 120kWh.\n\n");
    printf("Your PV voltage must be between 0-1200 volt.\n\n");
    printf("Your PV current must be between 0 and 100 ampere.\n\n");

    printf("\n\nEnter PV Volatge :");
    scanf("%d",&pv_voltage);                   // to take pv voltage

    printf("\n\nEnter PV Current :");
    scanf("%d",&pv_current);                   // to take pv current

    int power_calculation(int,int);              // function prortotype

    power_calculation(pv_voltage,pv_current);    // function calling

}

int port_input()
{
// Take user input to check which charging porta are active
 printf("Please provide port data.\n ");
 printf("Please enter '1' if port is active.\n");
 printf("Please enter '0' if port is not active.\n");
 

 // function to check which port are active
 for(int i=0; i<5; i++)
 {
    printf("Please enter port %d data :\n",i+1);
    scanf("%d",&port[i]);
 }
 