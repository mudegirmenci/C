#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void terscevir(char *);

int main( void )
{
    char girdi[200];
    char *token;
    int i;

    gets(girdi);

    for(i=0,token = strtok(girdi," \n");token;token=strtok(NULL," \n"),i++);
    printf("metin %d kelime iceriyor\n",i);
}

