/*
3.44 float t�r�nden �� say� alan ve bir ��gen kenarlar� olabilir mi diye kontrol eden program.
Bir ��gende iki kenar�n toplan uzunlu�u, ���nc� kenardan az olamaz
Bir ��gen de iki kenar�n fark�n�n mutlak de�eri ���nc� kenardan b�y�k olmamal�.


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
