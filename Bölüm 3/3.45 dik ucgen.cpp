/*
3.45  girilen �� kenar�n bir dik ��gen olup olmad���n� bulan program.

1.  kullan�c�dan �� say� al 
2. say�lar� a,b,c de�i�kenlerine ata
3. En b�y�k say�y� bul ve hipotenus de�i�keninde sakla.
4. a*a+b*b=hipotenus*hipotenus olup olmad���n� kontrol et
5.    eger do�ruysa dik ��gen yaz
   de�ise dik ��gen de�il yaz

*/

#include<stdio.h>

int main()
{
	int a,b,c,hipotenus;
	
	printf("Birinci kenari girin:\n");
	scanf("%d",&a);
	printf("Ikinci kenari girin:\n");
	scanf("%d",&b);
	printf("Ucuncu kenari girin:\n");
	scanf("%d",&c);
	
	if(a>b &&a>c){				//en b�y�k a ise 
	   hipotenus=a;
	   printf("%s",c*c+b*b==hipotenus*hipotenus ? "Dik Ucgen" : "Dik ucgen degil");
	 }
	else if(c>b && c>a){			//en b�y�k c ise 
		hipotenus=c;
		printf("%s",a*a+b*b==hipotenus*hipotenus ? "Dik Ucgen" : "Dik ucgen degil");
	} else {					//en b�y�k b ise 
		hipotenus=b;
		printf("%s",a*a+c*c==hipotenus*hipotenus ? "Dik Ucgen" : "Dik ucgen degil");
	}
	  
	return 0;



}
