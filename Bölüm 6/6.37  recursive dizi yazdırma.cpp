#include <stdio.h>
#define BOYUT 100

int lineerArama(const int[],int, int);
void diziYazdir(const int dizi[],int boyut);

int main() {
	
	int a[BOYUT],aramaDegeri,eleman;
	
	for(int i=0;i<=BOYUT;i++)		//veri oluþtur
		a[i]=2*i;
		
	printf("Arama degeri tamsayi girin:\n");
	scanf("%d",&aramaDegeri);
	eleman=lineerArama(a,aramaDegeri,BOYUT);
	
	if(eleman!=-1) printf("Bu deger eleman %d de bulundu:\n",eleman);
	else printf("Bu deger bulunamadi.\n");
	
	diziYazdir(a,BOYUT);
	return 0;
}

int lineerArama(const int dizi[],int anahtar, int boyut)  {
	int n;
	
	for (int n=0;n<boyut;n++){
		if(dizi[n]==anahtar) return n;	
	}
	   
	   
	return -1;
}

/*  diziyi tersten recursive olarak yazdýr. */
void diziYazdirTers(const int dizi[],int boyut){
	if(boyut!=0) {
		printf("%d ",dizi[boyut-1]);
		return diziYazdirTers(dizi,boyut-1);
	}
}


/*  diziyi tersten recursive olarak yazdýr. */
void diziYazdir(const int dizi[],int boyut){
	if(boyut!=0) {
		printf("%d ",dizi[0]);
		return diziYazdir(&dizi[1],boyut-1);		//dizinin 2. elemanýný baþlangýç adresi olarak gönderiyoruz. Böylece her döngüde dizi bir ilerliyor.
	}
}




