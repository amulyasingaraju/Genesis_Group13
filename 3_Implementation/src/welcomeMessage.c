#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "EVStation.bin"
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
#include"header.h"

typedef struct//to call the program
{
    char username[MAX_SIZE_USER_NAME];//username
    char password[MAX_SIZE_PASSWORD];//password
} sFileHeader;

void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate space needed to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    printf("\n\t\t\t\t\t\t EV Charging Station");
    printMessageCenter(message); //Print message
}

void welcomeMessage()
{
    headMessage("\n \t\t\t\t\tSUSTAINABLE HYBRID EV CHARGING STATION");
    printf("\n\n\n\t\t\t DEAR USER, WELCOME TO EV CHARGING STATION");
    printf("\n\n\n\t\t\t Press ENTER key to continue.....");//Print message
    getchar();
}
