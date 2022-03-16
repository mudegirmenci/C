#include <stdio.h>
/*
Bütün satır ve sütunlar 0 olur.
*/

int main(){

   int satislar[3][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
   
   for(int satir=0;satir<=2;satir++){
      for(int sutun=0;sutun<=4;sutun++){
	  	   satislar[satir][sutun]=0;
	  	   printf("%d ",satislar[satir][sutun]);
	  
	  }
	  printf("\n");
}
}
