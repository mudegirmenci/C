#include <stdio.h>
#include <string.h>
#include <math.h>

/*
asal3 en h�zl� algoritma gibi g�r�n�yor.
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
	
	//1-1000 aras� asal say�lar� yazd�r.
	for(int i=0,j=0;i<10000;i++){
		if(asal1(i))    printf("%3d  ",i);
	}

}

//say� asalsa 1 de�ilse 0 d�nderir.
//y�ntem 1
int asal1(int sayi){
	
	int j=0;
	for(int i=1;i<=sayi;i++){
		if(sayi%i==0){			//girilen say�n�n b�lenlerini say
			j++;
	   }		
	   if(sayi==1) j=2;     //girilen say� 1 ise asal olarak i�aretle.
	   
	}
	if(j==2) return 1;		//sadece 1 ve kendisi b�leniyse, yani toplam 2 b�leni varsa asal say�d�r.
	return 0;
	
}

/*
Y�ntem 2
*/
int asal2(int sayi){
	
	int j=0;
	for(int i=2;i<=sayi/2;i++){
		if(sayi%i==0){		      //say�/2 �arpanlar�n �st s�n�r�. b�t�n say�lar 1 e b�l�nebildi�i i�in i de�erini 2 den ba�lat�yoruz. D�ng� say�n�n yar�s�na kadar herhangi bir b�len buluyorsa daha fazla ilerlemeye ihtiya� duymuyor ve say� asal de�il sonucuna var�yoruz.
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



