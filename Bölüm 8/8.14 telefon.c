#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{

	char telefon[] ="(555) 555-5555";
	char *token,*temp;


    token = strtok(telefon," -()");

   // sscanf(token,"%s",temp);
    printf("%d\n",atoi(temp));

    while(token!=NULL) {
        token =strtok(NULL,"  -()");
      //  sscanf(token,"%s",temp);  //  token contentsi temp e kopyalamak için 1. yöntem
        printf("%ld\n",atol(token));
     }
}
