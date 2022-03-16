#include <stdio.h>
#include <ctype.h>
void buyukHarfeCevir(char *);

int main() {
	
	char string[]="karakterler ve 43.34$\n";
	printf("Buyuk harfe cevrilmeden onceki hali:%s",string);
	buyukHarfeCevir(string);
	printf("Buyuk harfe cevrilmeden sonraki hali:%s",string);
}
void buyukHarfeCevir(char *sPtr){
	while(*sPtr !='\0') {
		if(islower(*sPtr))
			*sPtr =toupper(*sPtr);
		++sPtr;
	}
}
