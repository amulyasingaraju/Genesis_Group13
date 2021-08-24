#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
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
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct owner_details
{
     char uname[10];
     char pword[10];
}owner;
char name[1][10]={"abcdef"};
char pass[1][10]={"abcdef"};

void login()
{
    int i=0;
    system("clear");
    while(i<3)
    {
        owner c1;
        printf("Username:");
        scanf("%s",c1.uname);
        printf("Password:");
        scanf("%s",c1.pword);
        int k=0;
        while(k<3)
        {
                 if((strcmp(c1.uname,name[k]))==0)
                 {

                            if(strcmp(c1.pword,pass[k])==0)
                             {
				             system("clear");
                                printf("LOGIN SUCCESSFULL");
                                int user_input(void);
                                int port_input(void);
                                user_input();
                                port_input();
                                return;
                             }

                 }

                 k++;
        }
        i++;
        system("clear");
	printf("Invalid Username or Password. Try Again!!\n\n");
    }
    system("clear");
    printf("LOGIN UNSUCCESSFULL AFTER THREE TRIES\n");
    printf("\nRE-RUN YOUR PROGRAM AND TRY AGAIN\n\n");
    exit(0);
}
