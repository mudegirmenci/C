#include<stdio.h>

/*

mario kulesi:

1. Kullan�c�dan 1-8 aras� bir de�er al,height de�i�kenine ata.
2. Girilen say� 1-8 aras� de�ilse kullan�c� uyar� ver ve program� bitir.
3. height de�i�keninin bir eksi�i kadar bo�luk yaz, son de�ere # koy.
4. height de�i�keninin iki eksi�i kadar bo�luk yaz, son iki de�ere # koy.
5. height de�i�keni 0 olana kadar bo�luk koy ve kalanlara # yap.
*/
int main()
{
	
   int height,kareSayisi=1,i=0,sayac=1;
   
   printf("1-8 arasi bir tamsayi girin: ");
   scanf("%d",&height);
   
   sayac=height;
   
   while(height>0){ 		//y�kseklik 0 dan b�y�k oldu�u s�rece tekrarla
   	   while(sayac>1){		//sayac 0 dan b�y�k oldu�u s�rece tekrarla
   	   	   printf(".");     //sayac kadar bo�luk yazd�r
   	   	   sayac--;  		//sayac� azalt
		}
		i=kareSayisi;		//  # �izimi i�in yard�mc� de�i�ken. Ka� kare �izilece�i bilgisini tutar. Program ilk �al��t���nda bu say� 1 dir.
		while(i>0){         //i pozitif oldu�u s�rece tekrarla
			printf("#");    
			i--;
		}
		printf("\n");	    //mevcut sat�r�n bo�luk ve # �izme i�lemi bitti. Yeni sat�ra ge�
		kareSayisi++;       //bir sonraki kare say�s� her sat�rda bir art�yor.
		height--;			//y�ksekli�imiz her sat�rda bir azal�r
		sayac=height;       //yeni sat�rda bo�luk say�m�z bir �ncekinden bir eksik oldu�u i�in sayac�m�zda yeni y�kseklikle ayn�.
	
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
   
   while(height>0){ 		//y�kseklik 0 dan b�y�k oldu�u s�rece tekrarla
   	   while(sayac>1){		//sayac 0 dan b�y�k oldu�u s�rece tekrarla
   	   	   printf(" ");     //sayac kadar bo�luk yazd�r
   	   	   sayac--;  		//sayac� azalt
		} 
		i=kareSayisi;		//  # �izimi i�in yard�mc� de�i�ken. Ka� kare �izilece�i bilgisini tutar. Program ilk �al��t���nda bu say� 1 dir.
		while(i>0){         //i pozitif oldu�u s�rece tekrarla
			printf("#");    
			i--;
		}
		printf("\n");	    //mevcut sat�r�n bo�luk ve # �izme i�lemi bitti. Yeni sat�ra ge�
		kareSayisi++;       //bir sonraki kare say�s� her sat�rda bir art�yor.
		height--;			//y�ksekli�imiz her sat�rda bir azal�r
		sayac=height;       //yeni sat�rda bo�luk say�m�z bir �ncekinden bir eksik oldu�u i�in sayac�m�zda yeni y�kseklikle ayn�.
	
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

