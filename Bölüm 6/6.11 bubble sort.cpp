#include <stdio.h>
/*
Bubble sort iyileþtirmeler:
1.
 Normalde her turda 9 karþýlaþtýrma yapmak yerine, her turda en büyük deðer dizinin son deðerine yerleþtiði için
 karþýlaþtýrma sayýsýný birer birer azaltýyoruz. Yani 1. turda 9, 2. turda 8, 3. turda 7... karþýlaþtýrma iþimizi görecektir. 
 Bu þekilde performans artýþý da saðlarýz. Bubble sort normal haliyle 10 boyutlu bir dizi için 64 döngü yaparken yaptýðýmýz bu düzeltme ile 
 döngü sayýsý 36 ya düþtü.
2.
 Dizideki sayýlarýn tümü veya büyük bir kýsmý zaten sýralanmýþ olabilir. O halde daha azý mümkünken neden dokuz kez dönecek bir döngü kullanýlsýn?
 Her tur sonunda doðru sýralamanýn yapýlýp yapýlmadýðý kontrol edilsin. Bunu baþarmak için dizi elemanlarý arasýnda bir yer deðiþtirme olmuþmu ona bakmalýyýz.
 Eðer bir yer deðiþikliði olmadýysa break ile döngüden çýkýp diðer tura geçebiliriz. Ýf ifadesi içinde bir kontrol deðiþkeni yapýyoruz. Eðer if ifadesine hiç girilmiyorsa
 demekki dizi sýralý. Bu durumda ilk for döngüsünde kontrolümüzü yapýp diziyi sonlandýrýyoruz.
 Bu iyileþtirme ile döngü sayýmýz 21 e düþüyor.
*/

#define INDIS 10
int main(){
	
	int a[INDIS]={2,6,8,4,10,12,89,68,45,37};
	int temp,dongu=1,kontrol=0;
	
	printf("Veriler orjinal sýrasýnda:\n");
	
	for(int i=0;i<INDIS-1;i++)
		printf("%4d ",a[i]);
	
	printf("\n\t");
		
	for(int tur=1;tur<INDIS-1;tur++,kontrol=0) {		 //tur sayýsý
	   for(int i=0;i<INDIS-(tur+1);i++){   			
			if(a[i]>a[i+1]){			         	
				temp=a[i];							
				a[i]=a[i+1];
				a[i+1]=temp;
				kontrol=1;
			}
			printf("Dongu Sayisi:%3d\t",dongu);
			dongu++;
     	}  
   if(kontrol==0) break;  //herhangi bir yer deðiþikliði yapýlmamýþsa, dizi sýralýdýr. Bu durumda döngüye devam etmeye gerek yok.
    
   }
	
	printf("\n");
	printf("Veriler artan sýrada:\n");
	
	for(int i=0;i<INDIS-1;i++)
		printf("%4d ",a[i]);
	
}
