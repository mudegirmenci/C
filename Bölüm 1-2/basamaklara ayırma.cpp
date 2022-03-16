#include<stdio.h>

int main()
{
	int a;
	
	printf("Bes basamakli bir sayi girin:\n");
	scanf("%d",&a);
	
	printf("%d\n",a%10);        //10'lar basamaðý mod. 12345 sayýsý 10 a bölünürse 1'ler basamaðýndaki sayýyý dönderir.
	printf("%d\n",(a/10)%10);   //C de tam sayýlarý bölme iþlemi 0 verir. yani 12345/10 normalde 1234.5 olmalý fakat tamsayý olduðu için 1234 olarak yuvarlýyor.
	printf("%d\n",(a/100)%10);  //burada da 12345/100=123. 123 mod 10=3
	printf("%d\n",(a/1000)%10);
	printf("%d\n",(a/10000)%10);

	return 0;
}
