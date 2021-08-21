// time required to charge one scooter per unit is 2 minutes
//time required to charge one car per unit is 3 minutes
#include <stdio.h>
int TimeEstimate()
{
    char car, scooter, EV;
    int unit;
    printf("Enter which EV you have to charge:\n 1. car \n 2. scooter  \n");
    scanf("%s",&EV);
    printf("Enter how many units required: \n");
    scanf("%d", &unit);
    if(EV == car)
    {
    printf("Estimated time = %d min  ", unit*3);
    }

    else 
    {
        printf("Estimated time = %d min", unit*2);
    }
}

int main()
{
    TimeEstimate();
    return 0;
}
    



