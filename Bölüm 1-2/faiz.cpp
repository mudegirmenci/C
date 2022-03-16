#include<stdio.h>

int main()
{
	float anapara=0,faiz=0,oran=0;
	int gunler=0;
	
	printf("Anapara giriniz (exit -1)):\n");
	scanf("%f",&anapara);
	printf("Faiz orani giriniz (exit -1)):\n");
	scanf("%f",&oran);
	printf("Gun bilgisi giriniz (exit -1)):\n");
	scanf("%f",&gunler);
	
	if(anapara<=0 || oran<=0 || gunler<=0) {
		printf("Herhangi bir deðer girilmedi\n");
		return 0;
				
	}

	faiz=anapara*oran*gunler/365;

	
	printf("faiz oran %.2f",faiz);
}
