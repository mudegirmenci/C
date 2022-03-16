#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
iki zarýn 3600 defa atýlýþ sonucu
*/
int main()
{
	int dizi[3600]={0};
	
	srand(time(NULL));
	
	for(int i=1;i<3600;i++){
		dizi[i]=(1+rand()%6)+(1+rand()%6);
	    printf("%5d. Zarlar toplam:%2d\t",i,dizi[i]);
	
	}
}
