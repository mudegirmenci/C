#include<stdio.h>

int main()
{
	int a,b;
	
	printf("�ki tamsayi girin: \n");
	scanf("%d%d",&a,&b);
	
	if(a==b*2)
	   printf("%d say�s� %d say�s�n�n iki kati\n",a,b);
	if(b==a*2)
	   printf("%d say�s� %d say�s�n�n iki kati\n",b,a);
	

	return 0;
}
