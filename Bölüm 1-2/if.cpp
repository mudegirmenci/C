#include<stdio.h>

int main()
{
	int a,b;
	
	printf("Ýki tamsayý girin: \n");
	scanf("%d%d",&a,&b);
	
	if(a==b)
	   printf("Bu sayýlar eþit");
	if(a>b)
	   printf("%d en büyük",a);
	if(b>a)
	   printf("%d en büyük",b);
	   
	   return 0;   
	
}
