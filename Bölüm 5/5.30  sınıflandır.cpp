#include <stdio.h>
/*

s�n�fland�rma fonksiyonu.
Bir ��rencinin ortlama notu 90-100 aras� ise 4,80-89 aras� ise 3,70-79 aras� ise 2, 60-69 aras� ise 1, 0-60 aras� ise 0 d�nd�rs�n.
		

*/
int siniflandir(int);

int main()
{
	int sayi;
	printf("��renci notu girin:\n");
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
