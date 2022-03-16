#include <stdio.h>
void referansaGoreKup(int *);

int main() {
	int sayi=5;
	
	printf("Sayi degeri:%d\n",sayi);
	referansaGoreKup(&sayi);
	printf("Sayi yeni degeri:%d\n",sayi);
	
	return 0;
}
void referansaGoreKup(int *nPtr){
	*nPtr =*nPtr**nPtr**nPtr;
}
