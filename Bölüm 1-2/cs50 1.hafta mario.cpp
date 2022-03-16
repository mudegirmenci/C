#include<stdio.h>

/*

mario kulesi:

1. Kullanýcýdan 1-8 arasý bir deðer al,height deðiþkenine ata.
2. Girilen sayý 1-8 arasý deðilse kullanýcý uyarý ver ve programý bitir.
3. height deðiþkeninin bir eksiði kadar boþluk yaz, son deðere # koy.
4. height deðiþkeninin iki eksiði kadar boþluk yaz, son iki deðere # koy.
5. height deðiþkeni 0 olana kadar boþluk koy ve kalanlara # yap.
*/
int main()
{
	
   int height,kareSayisi=1,i=0,sayac=1;
   
   printf("1-8 arasi bir tamsayi girin: ");
   scanf("%d",&height);
   
   sayac=height;
   
   while(height>0){ 		//yükseklik 0 dan büyük olduðu sürece tekrarla
   	   while(sayac>1){		//sayac 0 dan büyük olduðu sürece tekrarla
   	   	   printf(".");     //sayac kadar boþluk yazdýr
   	   	   sayac--;  		//sayacý azalt
		}
		i=kareSayisi;		//  # çizimi için yardýmcý deðiþken. Kaç kare çizileceði bilgisini tutar. Program ilk çalýþtýðýnda bu sayý 1 dir.
		while(i>0){         //i pozitif olduðu sürece tekrarla
			printf("#");    
			i--;
		}
		printf("\n");	    //mevcut satýrýn boþluk ve # çizme iþlemi bitti. Yeni satýra geç
		kareSayisi++;       //bir sonraki kare sayýsý her satýrda bir artýyor.
		height--;			//yüksekliðimiz her satýrda bir azalýr
		sayac=height;       //yeni satýrda boþluk sayýmýz bir öncekinden bir eksik olduðu için sayacýmýzda yeni yükseklikle ayný.
	
   }

   return 0;	
}


/*
// Abstraction and scope

#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)
{
    int height = get_positive_int("1-8 arasi bir tamsayi girin:\n");
   
    int kareSayisi=1,i=0,sayac=1;
   
   
   sayac=height;
   
   while(height>0){ 		//yükseklik 0 dan büyük olduðu sürece tekrarla
   	   while(sayac>1){		//sayac 0 dan büyük olduðu sürece tekrarla
   	   	   printf(" ");     //sayac kadar boþluk yazdýr
   	   	   sayac--;  		//sayacý azalt
		} 
		i=kareSayisi;		//  # çizimi için yardýmcý deðiþken. Kaç kare çizileceði bilgisini tutar. Program ilk çalýþtýðýnda bu sayý 1 dir.
		while(i>0){         //i pozitif olduðu sürece tekrarla
			printf("#");    
			i--;
		}
		printf("\n");	    //mevcut satýrýn boþluk ve # çizme iþlemi bitti. Yeni satýra geç
		kareSayisi++;       //bir sonraki kare sayýsý her satýrda bir artýyor.
		height--;			//yüksekliðimiz her satýrda bir azalýr
		sayac=height;       //yeni satýrda boþluk sayýmýz bir öncekinden bir eksik olduðu için sayacýmýzda yeni yükseklikle ayný.
	
   }
}

// Prompt user for positive integer
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n>8);
    return n;
}


/*

