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
char port_status(void)
{
	int arr[3],i,j,sum=0,sum1=0;
	float t,t1;
	float count=0,count1=0;
	int KWh = 3;//3KWh for scooter
	int KWh1=50;//50KWh for car
	int unit=5;// cost per KWh
	printf("SCOOTER\n");
	for (i=0;i<3;i++)
	{
		printf("Enter port %d status of scooter section:\n",i);
    		scanf("%d",&arr[i]);
	}
	printf("CAR\n");
	for (i=3;i<5;i++)
	{
		printf("Enter port %d status of car section:\n",i);
    		scanf("%d",&arr[i]);
	}
	for(i=0;i<3;i++)
	{
		if(arr[i]!=0)
		{
    		printf("\nThe scooter port %d is being used\n",i);
    		wait(1);
    		printf("total charge cost recorded : %d rupees\n",KWh*unit);
    		t = KWh*3;//time to charge each scooter per unit is 3 minutes
    		printf("total time : %.2f minutes\n\n",t);
		sum+=KWh*unit;
		count+=t;//storing time of each scooter port used
		}
		else
		{
			printf("The scooter port %d is empty\n\n",i);
		}
	}
	printf("|*-----------------------------------------------*|\n\n");
	for(i=3;i<5;i++)
	{
		if(arr[i]!=0)
		{
    			printf("The car port %d is being used\n",i);
    			wait(1);
    			printf("total charge cost recorded : %d rupees\n",KWh1*unit);
    			t1 = KWh1*6;//time to charge each car per unit is 0.6 minutes
    			printf("total time : %f minutes\n\n",t1/10);
			sum1+=KWh1*unit;
			count1+=(t1/10);// storing time of each car port used
		}
		else
		{
			printf("The car port %d is empty\n\n",j);
		}
	}

	int total_sum=sum+sum1;
	int ti=count+count1;
	printf("|*-----------------------------------------------*|\n");
	printf("The sum of all the scooters charge cost : %d rupees\n",sum);//sum charge of all scooters
	printf("The sum of all the cars charge cost :%d rupees\n",sum1);//sum charge of all cars
	printf("Total charge : %d rupees\n",total_sum);// total charge cost
	printf("Total time taken by vehicles to charge : %f minutes",count+count1);
	return 0;
}
int main()
{
	port_status();
}
