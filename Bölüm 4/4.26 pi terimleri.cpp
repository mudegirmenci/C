#include<stdio.h>

int main(void)
{
	int terim,sayac=1;
	double pi=0,kontrol=1;
	
	
	
	printf("Kac terime kadar pi gormek istersiniz? ");
	scanf("%d",&terim);
	
	while(--terim>=0){
		if(sayac%2==0)
			pi=pi-(4/kontrol);
		else
		 	pi=pi+(4/kontrol);
		printf("Sayac:%d  Pi:%lf\n",sayac,pi);
		sayac++;
		kontrol+=2;
		
	}
//	printf("Pi:%lf\n",pi);
}
