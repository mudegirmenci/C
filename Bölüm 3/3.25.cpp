#include<stdio.h>

int main ()
{
	int n=1;
	
	printf("N\tN*10\tN*100\tN*100\n");
	
	while(n<=10){
		printf("%d\t%d\t%d\t%d\n",n,n*10,n*100,n*1000);
		n++;
	}
	return 0;
}
