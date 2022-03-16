#include <stdio.h>

/*
main fonksiyonu kendini recursive çaðýrabilir mi? 
*/
int main(){

	static int sayac=1;

	printf("%d\n",sayac);
	sayac++;
	
	main();	


}

