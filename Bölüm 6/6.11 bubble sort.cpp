#include <stdio.h>
/*
Bubble sort iyile�tirmeler:
1.
 Normalde her turda 9 kar��la�t�rma yapmak yerine, her turda en b�y�k de�er dizinin son de�erine yerle�ti�i i�in
 kar��la�t�rma say�s�n� birer birer azalt�yoruz. Yani 1. turda 9, 2. turda 8, 3. turda 7... kar��la�t�rma i�imizi g�recektir. 
 Bu �ekilde performans art��� da sa�lar�z. Bubble sort normal haliyle 10 boyutlu bir dizi i�in 64 d�ng� yaparken yapt���m�z bu d�zeltme ile 
 d�ng� say�s� 36 ya d��t�.
2.
 Dizideki say�lar�n t�m� veya b�y�k bir k�sm� zaten s�ralanm�� olabilir. O halde daha az� m�mk�nken neden dokuz kez d�necek bir d�ng� kullan�ls�n?
 Her tur sonunda do�ru s�ralaman�n yap�l�p yap�lmad��� kontrol edilsin. Bunu ba�armak i�in dizi elemanlar� aras�nda bir yer de�i�tirme olmu�mu ona bakmal�y�z.
 E�er bir yer de�i�ikli�i olmad�ysa break ile d�ng�den ��k�p di�er tura ge�ebiliriz. �f ifadesi i�inde bir kontrol de�i�keni yap�yoruz. E�er if ifadesine hi� girilmiyorsa
 demekki dizi s�ral�. Bu durumda ilk for d�ng�s�nde kontrol�m�z� yap�p diziyi sonland�r�yoruz.
 Bu iyile�tirme ile d�ng� say�m�z 21 e d���yor.
*/

#define INDIS 10
int main(){
	
	int a[INDIS]={2,6,8,4,10,12,89,68,45,37};
	int temp,dongu=1,kontrol=0;
	
	printf("Veriler orjinal s�ras�nda:\n");
	
	for(int i=0;i<INDIS-1;i++)
		printf("%4d ",a[i]);
	
	printf("\n\t");
		
	for(int tur=1;tur<INDIS-1;tur++,kontrol=0) {		 //tur say�s�
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
   if(kontrol==0) break;  //herhangi bir yer de�i�ikli�i yap�lmam��sa, dizi s�ral�d�r. Bu durumda d�ng�ye devam etmeye gerek yok.
    
   }
	
	printf("\n");
	printf("Veriler artan s�rada:\n");
	
	for(int i=0;i<INDIS-1;i++)
		printf("%4d ",a[i]);
	
}
