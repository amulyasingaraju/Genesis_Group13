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

void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int L=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("\nLogin");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    while(L<3)
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        int k=0;
        while(k<3)
        {
            if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
            {   
                int user_input(void);
                int port_input(void);
                printf("Login Successful!");
                user_input();
                port_input();
                return 0;
            }
            k++;
        }
        L++; 
    printf("\n\n\t\t\t\twrong username and password, please try again");
    }
    printf("\n\n\t\t\t\tYou have exceeded 3 chances! terminating program\n\n");
    exit(0);
}
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
