#include <stdio.h>


/*
Hanoi kuleleri ta��ma.
    
1    ***
2   *****
3  *******
4 *********
  -----------      -----------      -----------   
	A					B				C

yukar�daki hanoi kulesi �u �ekilde ta��n�r:

	4 Disk        3 Disk		2 Disk    1 Disk 
	---------------------------------------------
1-	1->2		1->3			1->2	 1->3
2-	2->3		2->2			2->3
3-	1->3		1->2			1->3

4-	3->2		3->3

5-	1->1		1->1
6-	2->2		2->3
7-  1->2		1->3

8-	4->3

9-	1->3
10-	2->1
11-	1->1

12-	3->3

13-	1->2
14-	2->3
15-	1->3

g�zlemler:
1-Disk say�lar�ndaki her 1 art�� hamle say�s�n� iki kat�n�n 1 fazlas� yap�yor(2n+1). �rne�in 3 Diskla 7 hamlede biten oyun 4 Diskla 15, 5 Diskla 31 minumum 
hamlede bitiyor.
2-Oyun ba�lang�c� tek veya �ift Disk olmas�na g�re de�i�iyor. Tek Disklarda 1. Disk(en �st Disk) 3. kuleden ba�l�yor �ift Disklarda 2. kuleden ba�l�yor.

4 l�
1. Disk 2-3-1  BCA
2. Disk 3-2-1  CBA
3. Disk 2-3    BC
4. Disk 3	   C	

(5 li)Tekli say�larda 
1. Disk 3-2-1 CBA �ablonu ile 
2. Disk 2-3-1 BCA �ablonu ile
3. Disk 3-2-1 CBA �ablonu ile.
4. Disk 2-3   BC �ablonu ile
5. Disk 3     C �ablonu
 ile hareket etmekte 

(6 l�)�ift Disklarda 

1. Disk 2-3-1  BCA
2. Disk 3-2-1  CBA
3. Disk 2-3-1  BCA
4. Disk 3-2-1  CBA
5. Disk 2-3    BC
6. Disk 3      C

� Son iki Disk hareket �ablonu her durumda ayn�. 


Algoritma 

1. E�er Disk tek ise 3-2-1 �ablonu 

1. Disklar en k���k olan 1 olmak �zere numaraland�r�lacak.
2. Kule isimleri A,B,C �eklinde olacak.
3. Disk haraketleri 
	1. Disk A diskinden B diskine al�nd�.
	1. Disk B diskinden C diskine al�nd�.
 �eklinde mesajlar olacak.
4. 3 hamlede 2 disk problemi
   7 hamlede 3 disk problemi
   15 hamlede 4 disk problemi ��z�lm�� olacak. daha y�ksek diskler i�in ilk problemleri tekrar ��zmeye gerek yok.
	
	

*/

void hanoi(int diskSayisi,char ilkKonum,char sonKonum,char tempCubuk);

int main()
{
	hanoi(16,'A','C','B');
}

void hanoi(int diskSayisi,char ilk,char son,char temp){
	if(diskSayisi==1) {
		printf("\nDisk 1 i %c den %c ye tasi.",ilk,son);  //disk sayisi 1 veya A da kalan tek disk ise bunu C ye ta��
		return;
	}
		hanoi(diskSayisi-1,ilk,temp,son);    //
		printf("\nDisk %d i %c den %c ye tasi.",diskSayisi,ilk,son);
		hanoi(diskSayisi-1,temp,son,ilk);
	
	
	
}


