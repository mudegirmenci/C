#include<stdio.h>

int main()
{
	int a,b;
	
	printf("�ki tamsay� girin: \n");
	scanf("%d%d",&a,&b);
	
	if(a==b)
	   printf("Bu say�lar e�it");
	if(a>b)
	   printf("%d en b�y�k",a);
	if(b>a)
	   printf("%d en b�y�k",b);
	   
	   return 0;   
	
}
