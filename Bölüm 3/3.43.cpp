/*
3.43  printf("%d",++(x+y)) neden hata verir ve nas�l d�zeltilir.
�n art�rma operat�r�(++x) sadece de�i�kenlerle �al���r. �fadelerle �al��maz. Yani (x+y) hesaplay�p bunu bir art�rmaz. 

*/


#include<stdio.h>

int main(){
	
	int x=7,y=3;
	
	printf("%d",++x+y);
	
	return 0;
	
}
