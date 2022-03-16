/*
3.44 float türünden üç sayý alan ve bir üçgen kenarlarý olabilir mi diye kontrol eden program.
Bir üçgende iki kenarýn toplan uzunluðu, üçüncü kenardan az olamaz
Bir üçgen de iki kenarýn farkýnýn mutlak deðeri üçüncü kenardan büyük olmamalý.


*/


#include<stdio.h>

int main(){
	
	float a,b,c,temp;
    
	printf("Uc sayi girin:\n")	;
	scanf("%f %f %f",&a,&b,&c);
	
    if(a<b) {
    	temp=a;
        a=b;
        b=temp;
	}
	
	if((a+b)>c || (a-b)>c)
	   printf("Ucgen olabilir");
	else
	   printf("Ucgen olamaz");

     
       
	return 0;
}
