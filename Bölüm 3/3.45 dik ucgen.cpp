/*
3.45  girilen üç kenarýn bir dik üçgen olup olmadýðýný bulan program.

1.  kullanýcýdan üç sayý al 
2. sayýlarý a,b,c deðiþkenlerine ata
3. En büyük sayýyý bul ve hipotenus deðiþkeninde sakla.
4. a*a+b*b=hipotenus*hipotenus olup olmadýðýný kontrol et
5.    eger doðruysa dik üçgen yaz
   deðise dik üçgen deðil yaz

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
	
	if(a>b &&a>c){				//en büyük a ise 
	   hipotenus=a;
	   printf("%s",c*c+b*b==hipotenus*hipotenus ? "Dik Ucgen" : "Dik ucgen degil");
	 }
	else if(c>b && c>a){			//en büyük c ise 
		hipotenus=c;
		printf("%s",a*a+b*b==hipotenus*hipotenus ? "Dik Ucgen" : "Dik ucgen degil");
	} else {					//en büyük b ise 
		hipotenus=b;
		printf("%s",a*a+c*c==hipotenus*hipotenus ? "Dik Ucgen" : "Dik ucgen degil");
	}
	  
	return 0;



}
