#include<stdio.h>

//kenar uzunluðu verilen bir kareniyi * ile çizer
int main()
{
	int sayi;
    
	printf("Bes basamakli bir sayi girin:\n");
    scanf("%d",&sayi);
   /* 
    	printf("%d\n",sayi/10000) ; //on binler basamaðý?
        printf("%d\n",sayi%10) ;	 //birler basamaðý?
        printf("%d\n",(sayi/10)%10) ; //yüzler basamaðý
        printf("%d\n",(sayi/1000)%10) ; //binler basamaðý.Örneðin sayýmýz 12345 sayi/1000 bize 12 verir. 12%10 da 2 sayýsýný verir.
	*/
			        
 	if(sayi>=10000 && sayi<=99999) {	//sayý beþ basamaklý mý?
 		if(sayi/10000==sayi%10 && (sayi/10)%10 == (sayi/1000)%10) 
 			printf("Sayi polindrom ");
 		else
 		printf("Sayi polindrom degil ");
 	 } else
	 printf("girilen sayi 5 basamakli deðil");

	return 0;
}
