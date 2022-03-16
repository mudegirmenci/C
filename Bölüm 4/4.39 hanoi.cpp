#include <stdio.h>


/*
Hanoi kuleleri taþýma.
    
1    ***
2   *****
3  *******
4 *********
  -----------      -----------      -----------   
	1					2				3

yukarýdaki hanoi kulesi þu þekilde taþýnýr:

	4 Çubuk        3 çubuk			5 çubuk
	---------------------------------------------
1-	1->2		1->3			1->3
2-	2->3		2->2			2->2
3-	1->3		1->2			
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
1-Çubuk sayýlarýndaki her 1 artýþ hamle sayýsýný iki katýnýn 1 fazlasý yapýyor(2n+1). Örneðin 3 çubukla 7 hamlede biten oyun 4 çubukla 15, 5 çubukla 31 minumum 
hamlede bitiyor.
2-Oyun baþlangýcý tek veya çift çubuk olmasýna göre deðiþiyor. Tek çubuklarda 1. çubuk(en üst çubuk) 3. kuleden baþlýyor çift çubuklarda 2. kuleden baþlýyor.

4 lü
1. Çubuk 2-3-1 
2. Çubuk 3-2-1
3. Çubuk 2-3
4. Çubuk 3

(5 li)Tekli sayýlarda 
1. Çubuk 3-2-1 þablonu ile 
2. Çubuk 2-3-1 þablonu ile
3. Çubuk 3-2-1 þablonu ile.
4. Çubuk 2-3 þablonu ile
5. Çubuk 3 þablonu
 ile hareket etmekte 

(6 lý)Çift Çubuklarda 

1. Çubuk 2-3-1 
2. Çubuk 3-2-1
3. Çubuk 2-3-1
4. Çubuk 3-2-1
5. Çubuk 2-3
6. Çubuk 3 

• Son iki çubuk hareket þablonu her durumda ayný. 


Algoritma 

1. Eðer Çubuk tek ise 3-2-1 þablonu 

*/

int main()
{
	
}

