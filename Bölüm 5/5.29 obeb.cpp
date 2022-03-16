#include <stdio.h>
/*
OBEB bulma.
OBEB:iki tamsayýnýn ortak bölenlerinin en büyüðü ya da iki tam sayýnýn en büyük ortak böleni.

Sahte kod:
1. kullanýcýdan iki tamsayý iste
2. iki tamsayýyý obeb(a,b) fonksiyonuna geçir
3. obeb fonksiyonu iki sayýyý da küçük olan sayýya kadar her sayýya bölmeyi denesin. ortak bölen sayýyý obeb deðiþkenine ata
4. döngüdeki bir sonraki sayý ortak bölense obeb deðiþkenini o sayýyla deðiþtir.
*/

int obeb(int a,int b);
int obeb2(int a,int b);

int main()
{
	int a,b;
	printf("OBEB bulunacak iki tamsayý girin:\n");
	scanf("%d%d",&a,&b);
	
	// kullanýcý negatif sayý girerse, sayýnýn iþareti pozitif olarak deðiþir.
    a = ( a > 0) ? a : -a;
    b = ( b > 0) ? b : -b;
	printf("Girilen sayýlarýn OBEB'i:%d\n",obeb2(a,b));
}


/*
a küçük sayý olarak hazýrlýyoruz.
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
yöntem 2
*/
int obeb2(int a,int b)
 {
 	while(a!=b){
 		if(a>b) a-=b;
 		else b-=a;
	 }
	 return a;
 }
