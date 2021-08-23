#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "EVStation.bin"
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
#include"header.h"

int main()
{
    printf("\t\t\t\t\t********** Owner Screen **********\n\n");
    
    welcomeMessage();
    init();
    login();
    int grid_mode(int,int,int);
    int earnedbyev(int);
    int totalprofit(int,int);
    return 0;
}