
/*
3.39 Bir tam sayý alan ve bu sayýnýn basamaklarýnýn kaç tanesinin 7 olduðunu bulan program

sonuc:
Bir tamsayi girin:
1757171787
175717178
17571717
1757171
175717
17571
1757
175
17
1
0
Girdiginiz sayida 5 tane 7 var

*/


#include<stdio.h>

int main(){
	
	int sayi=0,i=0;
	
	printf("Bir tamsayi girin:\n");
	scanf("%d",&sayi);
	
	while(sayi>0){
		if(sayi%10==7)
		   ++i;
		sayi/=10;
	//	printf("%d\n",sayi);  //sayinin deðiþimini gösterir
	}
	printf("Girdiginiz sayida %d tane 7 var",i);
}
