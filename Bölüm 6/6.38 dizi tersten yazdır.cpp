#include <stdio.h>
#define BOYUT 100


void diziYazdirTers(const char dizi[],int boyut);

int main() {
	
	char  dizi[BOYUT]="Bu diziyi tersten okuyorsunuz.";
	
	printf("%s\n",dizi);
	
	
	
	diziYazdirTers(dizi,BOYUT);
	return 0;
}



/*  diziyi tersten recursive olarak yazdýr. */
void diziYazdirTers(const char dizi[],int boyut){
	if(boyut!=0) {
		printf("%c ",dizi[boyut-1]);
		return diziYazdirTers(dizi,boyut-1);
	}
}


