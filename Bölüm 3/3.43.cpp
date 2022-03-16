/*
3.43  printf("%d",++(x+y)) neden hata verir ve nasýl düzeltilir.
ön artýrma operatörü(++x) sadece deðiþkenlerle çalýþýr. Ýfadelerle çalýþmaz. Yani (x+y) hesaplayýp bunu bir artýrmaz. 

*/


#include<stdio.h>

int main(){
	
	int x=7,y=3;
	
	printf("%d",++x+y);
	
	return 0;
	
}
