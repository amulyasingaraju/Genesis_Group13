#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void wait(int wait)
{
	int now=time(NULL);
	int later=now+wait;
	while(now<=later)
	{
		now=time(NULL);
	}
}
int main()
{
	int arr[3],i,j,sum=0,sum1=0,arr1[2];
	float time,time1;
	float count,count1;
	int KWh = 3;//3KWh for scooter
	int KWh1=50;//50KWh for car
	int unit=5;// cost per KWh
	printf("Enter port status of scooter:");
	for (i=0;i<3;i++)
	{
    	scanf("%d",&arr[i]);
	}
	printf("Enter port status of car:");
	for (j=0;j<2;j++)
	{
    	scanf("%d",&arr1[j]);
	}
	for(i=0;i<3;i++)
	{
		if(arr[i]!=0)
		{
    		printf("\nThe scooter port %d is being used\n",i);
    		wait(1);
    		printf("total charge cost recorded : %d rupees\n",KWh*unit);
    		time = KWh*3;//time to charge each scooter per unit is 3 minutes
    		printf("total time : %.2f minutes\n\n",time);
			sum+=KWh*unit;
			count+=time;//storing time of each port used
		}
		else
		{
			printf("The scooter port %d is empty\n\n",i);
		}
	}
	printf("|*-----------------------------------------------*|\n\n");
	for(j=0;j<2;j++)
	{
		if(arr1[j]!=0)
		{
    		printf("The car port %d is being used\n",j);
    		wait(1);
    		printf("total charge cost recorded : %d rupees\n",KWh1*unit);
    		time1 = KWh1*6;//time to charge each car per unit is 0.6 minutes
    		printf("total time : %f minutes\n\n",time1/10);
			sum1+=KWh1*unit;
			count1+=(time1/10);
		}
		else
		{
			printf("The car port %d is empty\n\n",j);
		}
	}
	float total_time=count+count1;
	int total_sum=sum+sum1;
	printf("|*-----------------------------------------------*|\n");
	printf("The sum of all the scooters charge cost : %d rupees\n",sum);//sum charge of all scooters
	printf("The sum of all the cars charge cost :%d rupees\n",sum1);//sum charge of all cars
	printf("Total charge : %d rupees\n",total_sum);// total charge cost
	printf("Total time taken by vehicles to charge : %f minutes",total_time);
	return 0;
}
