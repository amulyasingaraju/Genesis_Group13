/**
 * @file init.c
 * @author Gangadhar Telagareddy (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include"header.h"

#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "EVStation.bin"
#define FILE_HEADER_SIZE  sizeof(sFileHeader)



typedef struct//to call the program
{
    char username[MAX_SIZE_USER_NAME];//username

    char password[MAX_SIZE_PASSWORD];//password

} sFileHeader;


void init()
{
    
    FILE *fp = NULL;

    int status = 0;

    const char defaultUsername[] ="abcdef\n"; //default username

    const char defaultPassword[] ="abcdef\n"; //default password

    sFileHeader fileHeaderInfo = {0};

    status = isFileExists(FILE_NAME);


    if(!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME,"wb");

        if(fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));

            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));

            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);

            fclose(fp);
        }

    }

}