#include<stdio.h>

int main()
{
	int calisilanSaat=0;
	float saatUcreti=0,maas=0;
	
	printf("Calisma saatini girin:");
	scanf("%d",&calisilanSaat);
	printf("Calisanin saatlik ucretini girin:");
	scanf("%f",&saatUcreti);
	
	if(calisilanSaat<40)
        maas=calisilanSaat*saatUcreti;
     else 
    	maas=saatUcreti*calisilanSaat+(calisilanSaat-40)*saatUcreti/2;
	
	printf("Calisanin maasi:%f",maas);
	
	return 0;
}
