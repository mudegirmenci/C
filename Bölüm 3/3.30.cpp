#include<stdio.h>

int main()
{
	int satir=10,sutun;
	
	while(satir>=1){
		sutun=1;
		
		while(sutun<=10) {
			printf("%s",satir % 2 ? "<" : ">");
			++sutun;
		}
		--satir;
		printf("\n");
	}
	return 0;
}
