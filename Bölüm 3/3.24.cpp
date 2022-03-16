#include<stdio.h>

// en büyük sayý bul
int main()
{
	int sayac=1, sayi=0, enBuyuk=0;
	
	while(sayac<=10) {
	   printf("%d. sayiyi girin(cikis için -1):\n",sayac);
	   scanf("%d",&sayi);
	   
	       
	   if(sayi>enBuyuk)
	      enBuyuk=sayi;
	   ++sayac;
	   
	    if(sayi==-1){
	   	printf("Programdan cikildi\n");
	   	printf("En Buyuk Sayi:%d",enBuyuk);
	   	return 0;
	   }
	}	
    printf("En Buyuk Sayi:%d",enBuyuk);
    
    
	return 0;
}
