#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void terscevir(char *);

int main( void )
{
    char girdi[200];
    char *token;
    char *temp;


    gets(girdi);

    for(token = strtok(girdi," ");token;token=strtok(NULL," ")) {

	    temp = strdup(token);
        terscevir(temp);
        printf("\n");
   	}
}
void terscevir(char *token)
{

    if(token[0]=='\0') return 0;
    else {
        terscevir(&token[1]);
        putchar(token[0]);
    }

  /*
  birinci yöntem.
   char *girdi = token;
   int x=strlen(girdi);

   for(int i=x-1;i>=0;i--) {
   		putchar(girdi[i]);
   }
    printf("\n");
    */

}
