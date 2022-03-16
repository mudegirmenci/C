#include <stdio.h>

void fonksiyon1(int);
void fonksiyon2(int);
void fonksiyon3(int);

int main() {
	void (*f[3])(int)={fonksiyon1,fonksiyon2,fonksiyon3};
	int secim;
	
	printf("0-2 arasýnda bir deger giriniz:\n");
	scanf("%d",&secim);
	
	while(secim>=0 && secim<3) {
		(*f[secim])(secim);
		printf("0-2 arasýnda bir deger veya cikis icin 3 giriniz:\n");
		scanf("%d",&secim);
	}
	
	printf("programin calismasi bitti\n");
}

void fonksiyon1(int a){
	printf("%d girdiniz\n"
			"yani fonksiyon 1 cagrildi\n",a);
}
void fonksiyon2(int a){
	printf("%d girdiniz\n"
		    "yani fonksiyon 2 cagrildi\n",a);
}
void fonksiyon3(int a){
	printf("%d girdiniz\n"
		    "yani fonksiyon 3 cagrildi\n",a);
}
