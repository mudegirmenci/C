/*
3.37 
Bilgisayar�n �al��ma h�z�n� �l�.

3.000.000 e kadar d�ng�de say�m yap�p,  1.000.000 ve katlar�n� ekrana yazd�rs�n.
*/

#include<stdio.h>

int main(){
	
	int i=0;
	
	while(i<=300000000){
		i++;
		if(i%100000000==0)
		   printf("%d\n",i);
	}
	return 0;
}
