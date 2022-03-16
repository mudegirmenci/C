#include<stdio.h>

int main()
{
	int a;
	
	printf("Bir tamsayi girin: \n");
	scanf("%d",&a);
	
	if(a%2==0)
	   printf("%d çift sayý\n",a);
	else 
	   printf("%d tek sayý\n",a);
	
	return 0;
}
