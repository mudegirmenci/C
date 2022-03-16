#include <stdio.h>

int ciftmiTekmi(int a);

int main()
{
	int a;
	printf("Sayıyı girin:\n");
	scanf("%d",&a);
	if(ciftmiTekmi(a))
	 printf("Cift");
	else
	printf("Tek");
}

int ciftmiTekmi(int a){
	if(a%2==0 ) return 1;
	return 0;
}

