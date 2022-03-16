#include <stdio.h>


/*
Hanoi kuleleri taþýma.
    
1    ***
2   *****
3  *******
4 *********
  -----------      -----------      -----------   
	A					B				C

yukarýdaki hanoi kulesi þu þekilde taþýnýr:

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

gözlemler:
1-Disk sayýlarýndaki her 1 artýþ hamle sayýsýný iki katýnýn 1 fazlasý yapýyor(2n+1). Örneðin 3 Diskla 7 hamlede biten oyun 4 Diskla 15, 5 Diskla 31 minumum 
hamlede bitiyor.
2-Oyun baþlangýcý tek veya çift Disk olmasýna göre deðiþiyor. Tek Disklarda 1. Disk(en üst Disk) 3. kuleden baþlýyor çift Disklarda 2. kuleden baþlýyor.

4 lü
1. Disk 2-3-1  BCA
2. Disk 3-2-1  CBA
3. Disk 2-3    BC
4. Disk 3	   C	

(5 li)Tekli sayýlarda 
1. Disk 3-2-1 CBA þablonu ile 
2. Disk 2-3-1 BCA þablonu ile
3. Disk 3-2-1 CBA þablonu ile.
4. Disk 2-3   BC þablonu ile
5. Disk 3     C þablonu
 ile hareket etmekte 

(6 lý)Çift Disklarda 

1. Disk 2-3-1  BCA
2. Disk 3-2-1  CBA
3. Disk 2-3-1  BCA
4. Disk 3-2-1  CBA
5. Disk 2-3    BC
6. Disk 3      C

• Son iki Disk hareket þablonu her durumda ayný. 


Algoritma 

1. Eðer Disk tek ise 3-2-1 þablonu 

1. Disklar en küçük olan 1 olmak üzere numaralandýrýlacak.
2. Kule isimleri A,B,C þeklinde olacak.
3. Disk haraketleri 
	1. Disk A diskinden B diskine alýndý.
	1. Disk B diskinden C diskine alýndý.
 þeklinde mesajlar olacak.
4. 3 hamlede 2 disk problemi
   7 hamlede 3 disk problemi
   15 hamlede 4 disk problemi çözülmüþ olacak. daha yüksek diskler için ilk problemleri tekrar çözmeye gerek yok.
	
	

*/

void hanoi(int diskSayisi,char ilkKonum,char sonKonum,char tempCubuk);

int main()
{
	hanoi(16,'A','C','B');
}

void hanoi(int diskSayisi,char ilk,char son,char temp){
	if(diskSayisi==1) {
		printf("\nDisk 1 i %c den %c ye tasi.",ilk,son);  //disk sayisi 1 veya A da kalan tek disk ise bunu C ye taþý
		return;
	}
		hanoi(diskSayisi-1,ilk,temp,son);    //
		printf("\nDisk %d i %c den %c ye tasi.",diskSayisi,ilk,son);
		hanoi(diskSayisi-1,temp,son,ilk);
	
	
	
}


