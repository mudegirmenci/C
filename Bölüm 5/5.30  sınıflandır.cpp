#include <stdio.h>
/*

sýnýflandýrma fonksiyonu.
Bir öðrencinin ortlama notu 90-100 arasý ise 4,80-89 arasý ise 3,70-79 arasý ise 2, 60-69 arasý ise 1, 0-60 arasý ise 0 döndürsün.
		

*/
int siniflandir(int);

int main()
{
	int sayi;
	printf("Öðrenci notu girin:\n");
	scanf("%d",&sayi);
	printf("%d\n",siniflandir(sayi));
}

int siniflandir(int sayi){
	 
	 if(sayi>=90 && sayi<=100) return 4;
	 if(sayi>=80 && sayi<=89) return 3;
	 if(sayi>=70 && sayi<=79) return 2;
	 if(sayi>=60 && sayi<=69) return 1;
	 if(sayi>=0 && sayi<=59) return 0;
}
