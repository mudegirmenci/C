#include <stdio.h>
/*
OBEB bulma.
OBEB:iki tamsay�n�n ortak b�lenlerinin en b�y��� ya da iki tam say�n�n en b�y�k ortak b�leni.

Sahte kod:
1. kullan�c�dan iki tamsay� iste
2. iki tamsay�y� obeb(a,b) fonksiyonuna ge�ir
3. obeb fonksiyonu iki say�y� da k���k olan say�ya kadar her say�ya b�lmeyi denesin. ortak b�len say�y� obeb de�i�kenine ata
4. d�ng�deki bir sonraki say� ortak b�lense obeb de�i�kenini o say�yla de�i�tir.
*/

int obeb(int a,int b);
int obeb2(int a,int b);

int main()
{
	int a,b;
	printf("OBEB bulunacak iki tamsay� girin:\n");
	scanf("%d%d",&a,&b);
	
	// kullan�c� negatif say� girerse, say�n�n i�areti pozitif olarak de�i�ir.
    a = ( a > 0) ? a : -a;
    b = ( b > 0) ? b : -b;
	printf("Girilen say�lar�n OBEB'i:%d\n",obeb2(a,b));
}


/*
a k���k say� olarak haz�rl�yoruz.
*/
int obeb(int a,int b){
	int obeb,temp;
	if(a>b){
		temp=a;
		a=b;
		b=temp;
	}
	
	for(int i=1;i<=a;i++){
		if(a%i==0 && b%i==0) obeb=i;
		
	}
	return obeb;
	
}

/*
y�ntem 2
*/
int obeb2(int a,int b)
 {
 	while(a!=b){
 		if(a>b) a-=b;
 		else b-=a;
	 }
	 return a;
 }
