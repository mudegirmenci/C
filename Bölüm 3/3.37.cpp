/*
3.37 
Bilgisayarýn çalýþma hýzýný ölç.

3.000.000 e kadar döngüde sayým yapýp,  1.000.000 ve katlarýný ekrana yazdýrsýn.
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
