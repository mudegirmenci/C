/*
4.16 desen çiz
A
*
**
***
****
*****
******
*******
********
*********
**********
B
**********
*********
********
*******
******
*****
****
***
**
*

C
 **********
  *********
   ********
    *******
     ******
      *****
       ****
        ***
         **
          *
D
         *
        **
       ***
      ****
     *****
    ******
   *******
  ********
 *********
**********

*/

#include<stdio.h>

int main(void){
   
   int i,j,bosluk=1;
   
   printf("A\n");
   for(i=1;i<=10;i++){
   	  for(j=1;j<=i;j++)
		 printf("*");
	 printf("\n");
   }
   
   printf("B\n");
   for(i=10;i>=0;i--){
   	  for(j=1;j<=i;j++)
		 printf("*");
	 printf("\n");
   }
  

   
   printf("C\n");
   for(i=1;i<=10;i++){
   	  for(j=0,bosluk=i;j<=10;j++,bosluk--){
		 if(bosluk>0)
		    printf(" ");
		  else
		    printf("*");
	}
	 printf("\n");
	 //bosluk=10-i;
   }
   
   printf("D\n");
   for(i=1,bosluk=9;i<=10;i++){
   	  for(j=1;j<=10;j++,bosluk--){
		 if(bosluk>0)
		    printf(" ");
		  else
		    printf("*");
	}
	bosluk=9-i;
	printf("\n");
	
   }
    
    
    
    

   
}
