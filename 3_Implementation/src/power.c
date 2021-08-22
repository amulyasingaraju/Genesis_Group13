#include<stdio.h>
#include<stdlib.h>

int power(int, int);
int main()
{
	int PV_Voltage,PV_current;
	printf("Enter voltage(in volts):");
	scanf("%d",&PV_Voltage);
	printf("Enter current(in amps):");
	scanf("%d",&PV_current);
	printf("Power : %d W",power(PV_Voltage,PV_current));
}
int power(int a, int b)
{
	return a*b;
}
