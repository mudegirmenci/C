#include<stdio.h>

int main()
{
	int dersNotu,sayac=0,toplam=0;
	float ortalama;
	
	printf("%d. Ogrencinin notunu giriniz(exit -1)): \n",sayac+1);
	scanf("%d",&dersNotu);
	sayac++;
	while(dersNotu!=-1)
	{
		toplam+=dersNotu;
		sayac++;
		printf("%d. Ogrencinin notunu giriniz(exit -1)): \n",sayac);
    	scanf("%d",&dersNotu);
	}
	
	if(sayac!=0) {
	   ortalama=(float)toplam/sayac;  //int tipindeki toplam ve sayac de�i�kenleri, (float) operat�r� ile float tipine terfi ettirilir. Bu arada int tipinden kopyalar� da ayr�ca saklan�r.
	   printf("Ortalama %.2f dir.\n",ortalama);
	} else 
	   printf("Not degeri girilmedi");
       
	
	return 0;
}
