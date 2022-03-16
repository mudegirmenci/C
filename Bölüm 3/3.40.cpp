
/*
3.40. aþaðýdaki þekli yazdýrýn.

* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
 
 
 8x8 satýr için 64 olan bir sayac deðiþken tanýmla. tek ve çift satýrlarý belirlemek için  step deðiþkeni oluþtur.
 
 while(sayac>0) sayac 0 dan büyük olduðu sürece
    Eðer sayac 8'in katýysa 
       bir alt satýra geç
       step deðiþkenini bir artýr
       
       eðer çiftli satýrdaysa bir girinti ver
    yýldýz yaz ve bir boþluk býrak
    sayac deðiþkenini bir azalt
    
    endWhile

*/

#include<stdio.h>

int main(){
	
	int sayac=64,step=0;
	
	while(sayac>0){
		if(sayac%8==0){			//satýr sonuysa (8 * yazdýysa)
			printf("\n");		//bir satýr alta geç
			++step; 			//step 1 artýr
		
			if(step%2==0)		//step çift ise bir boþluk girinti býrak
		      printf(" ");
		}
	printf("* ");              //yýldýz yazdýr
	--sayac;
	}
	

   return 0;	
}
