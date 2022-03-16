#include<stdio.h>

int main()
{
	int a,b;
	
	printf("İki tamsayi girin: \n");
	scanf("%d%d",&a,&b);
	
	if(a==b*2)
	   printf("%d sayısı %d sayısının iki kati\n",a,b);
	if(b==a*2)
	   printf("%d sayısı %d sayısının iki kati\n",b,a);
	

	return 0;
}
