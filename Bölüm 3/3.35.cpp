#include<stdio.h>

//kenar uzunlu�u verilen bir kareniyi * ile �izer
int main()
{
	int sayi;
    
	printf("Bes basamakli bir sayi girin:\n");
    scanf("%d",&sayi);
   /* 
    	printf("%d\n",sayi/10000) ; //on binler basama��?
        printf("%d\n",sayi%10) ;	 //birler basama��?
        printf("%d\n",(sayi/10)%10) ; //y�zler basama��
        printf("%d\n",(sayi/1000)%10) ; //binler basama��.�rne�in say�m�z 12345 sayi/1000 bize 12 verir. 12%10 da 2 say�s�n� verir.
	*/
			        
 	if(sayi>=10000 && sayi<=99999) {	//say� be� basamakl� m�?
 		if(sayi/10000==sayi%10 && (sayi/10)%10 == (sayi/1000)%10) 
 			printf("Sayi polindrom ");
 		else
 		printf("Sayi polindrom degil ");
 	 } else
	 printf("girilen sayi 5 basamakli de�il");

	return 0;
}
