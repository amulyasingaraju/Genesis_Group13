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
  //int scooter_power;//= 3000; // power required to charge one scooter is 3kWh
 //int car_power;// = 50000; // power required to charge one car is 50kWh

printf("\t\t\t\t\t**** Customer Screen ****\n\n");

 for(int i=0; i<3; i++)
 {  // to calculate power required to charge scooter 
     if(port[i]==1)
     {   
         printf("Dear Customer currently you are using port %d.\n\n",i+1);
         int amount_s;
         printf("Please Enter Amount(in multiple of 5) :");
         scanf("%d",&amount_s);
         printf("\n\n");
         int delivered_power = (amount_s/5) * 1000; // to store energy in Wh  
         printf("Please select payment mode.\n\n1. UPI\n2. Card\n");
         scanf("%d",&select);
         switch(select)
         {
            case 1:
                printf("waiting\n\n");
                wait(2);
                printf("Payment Sucessfull.\n\n");
                break;
            case 2:
                printf("waiting\n\n");
                wait(2);
                printf("Payment Sucessfull.\n");
                break;
            default:
                printf("please select either 1 or 2\n");
         }
         printf("|||||---------Thank you.--------|||||\n\n");
         // time required to charge one scooter per unit is 2 minutes
         int wait_time = (amount_s/5) *2;
         printf("Estimated Waiting Time %d Minutes.\n\n",wait_time);
         printf("Charging Completed....\nThank You, we will be happy to serve you again.\n\n");

         load_demand+= delivered_power;
         PROFITGRID+= amount_s;
     }  
 }

 for(int i=3; i<5; i++)
 {  // to calculate pwoer required to charge car 
     if(port[i]==1)
     {
         printf("Dear Customer currently you are using port %d.\n\n",i+1);
         int amount_c;
         printf("Please Enter Amount(in multiple of 5) :");
         scanf("%d",&amount_c);
         printf("\n\n");
         int delivered_power = (amount_c/5) * 1000; // to store energy in Wh  
         printf("Please select payment mode.\n\n1. UPI\n2. Card\n");
        
         scanf("%d",&select);
         switch(select)
         {
            case 1:
                printf("waiting\n\n");
                wait(2);
                printf("Payment Sucessfull.\n\n");
                break;
            case 2:
                printf("waiting\n\n");
                wait(2);
                printf("Payment Sucessfull.\n");
                break;
            default:
                printf("please select either 1 or 2\n");
         }
         printf("|||||---------Thank you.--------|||||\n\n");

         // time required to charge one scooter per unit is 3 minutes
         int wait_time = (amount_c/5) *3;
         printf("Estimated Waiting Time %d Minutes.\n\n",wait_time);
         printf("Charging Completed....\n Thank You, we will be happy to serve you again.\n");

         load_demand+= delivered_power;
         PROFITGRID+= amount_c;  
     }  
 }
 printf("\t\t\t\t\t**** Owner Screen ****\n\n");
 printf("Current Load demand is %d Wh.\n\n",load_demand);
 
 power_compare(pv_power,load_demand,PROFITGRID);
 //return load_demand;
}

