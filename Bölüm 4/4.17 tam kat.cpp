#include <stdio.h>

int tamKatiMi(int a,int b);

int main()
{
	int a,b;
	printf("Birinci say�y� girin:\n");
	scanf("%d",&a);
	printf("�kinci say�y� girin:\n");
	scanf("%d",&b);
	printf("tam kati mi?:%d",tamKatiMi(a,b));
}

int tamKatiMi(int a,int b){
	if(b/2==a ) return 1;
	return 0;
}

