#include<stdio.h>

int main()
{
	float haftalikSatis=0,maas=200;
	
	printf("Haftalik satisinizi giriniz(exit -1)):\n");
	scanf("%f",&haftalikSatis);
	
	if(haftalikSatis<=0) {
		printf("Herhangi bir deðer girilmedi\n");
		return 0;
				
	}

			
	maas+=(haftalikSatis/100)*9;
	
	
	printf("Bu haftaki maas %.2f",maas);
}
