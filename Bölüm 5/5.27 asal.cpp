#include <stdio.h>
#include <string.h>
#include <math.h>

/*
asal3 en hýzlý algoritma gibi görünüyor.
*/
int asal1(int sayi);   //0.5684 saniye
int asal2(int sayi);   //0.3271 saniye
int asal3(int sayi);   //0.2560 saniye

int main()
{

/*	int sayi;
	printf("Bir sayi girin:\n");
	scanf("%d",&sayi);
	printf("Sonuc:%d\n",asal(sayi));
	*/
	
	//1-1000 arasý asal sayýlarý yazdýr.
	for(int i=0,j=0;i<10000;i++){
		if(asal1(i))    printf("%3d  ",i);
	}

}

//sayý asalsa 1 deðilse 0 dönderir.
//yöntem 1
int asal1(int sayi){
	
	int j=0;
	for(int i=1;i<=sayi;i++){
		if(sayi%i==0){			//girilen sayýnýn bölenlerini say
			j++;
	   }		
	   if(sayi==1) j=2;     //girilen sayý 1 ise asal olarak iþaretle.
	   
	}
	if(j==2) return 1;		//sadece 1 ve kendisi böleniyse, yani toplam 2 böleni varsa asal sayýdýr.
	return 0;
	
}

/*
Yöntem 2
*/
int asal2(int sayi){
	
	int j=0;
	for(int i=2;i<=sayi/2;i++){
		if(sayi%i==0){		      //sayý/2 çarpanlarýn üst sýnýrý. bütün sayýlar 1 e bölünebildiði için i deðerini 2 den baþlatýyoruz. Döngü sayýnýn yarýsýna kadar herhangi bir bölen buluyorsa daha fazla ilerlemeye ihtiyaç duymuyor ve sayý asal deðil sonucuna varýyoruz.
			j++;
			break;
	   }		
	}
	if(j==0) return 1;	
	return 0;
	
}
int asal3(int sayi){
	
	int j=0;
	for(int i=2;i<=sqrt(sayi);i++){
		if(sayi%i==0){		     
			j++;
			break;
	   }		
	}
	if(j==0) return 1;	
	return 0;
}



