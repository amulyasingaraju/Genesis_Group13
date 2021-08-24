#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include"header.h"

int main()
{
    printf("\t\t\t\t\t********** Owner Screen **********\n\n");
    void welcomeMessage(void);    
    welcomeMessage();
    login();
    int grid_mode(int,int,int);
    return 0;
}