#include<stdio.h>

int main()
{
	int a;
	
	printf("Bir tamsayi girin: \n");
	scanf("%d",&a);
	
	if(a%2==0)
	   printf("%d �ift say�\n",a);
	else 
	   printf("%d tek say�\n",a);
	
	return 0;
}
