#include <stdio.h>


/*
Hanoi kuleleri ta��ma.
    
1    ***
2   *****
3  *******
4 *********
  -----------      -----------      -----------   
	1					2				3

yukar�daki hanoi kulesi �u �ekilde ta��n�r:

	4 �ubuk        3 �ubuk			5 �ubuk
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

g�zlemler:
1-�ubuk say�lar�ndaki her 1 art�� hamle say�s�n� iki kat�n�n 1 fazlas� yap�yor(2n+1). �rne�in 3 �ubukla 7 hamlede biten oyun 4 �ubukla 15, 5 �ubukla 31 minumum 
hamlede bitiyor.
2-Oyun ba�lang�c� tek veya �ift �ubuk olmas�na g�re de�i�iyor. Tek �ubuklarda 1. �ubuk(en �st �ubuk) 3. kuleden ba�l�yor �ift �ubuklarda 2. kuleden ba�l�yor.

4 l�
1. �ubuk 2-3-1 
2. �ubuk 3-2-1
3. �ubuk 2-3
4. �ubuk 3

(5 li)Tekli say�larda 
1. �ubuk 3-2-1 �ablonu ile 
2. �ubuk 2-3-1 �ablonu ile
3. �ubuk 3-2-1 �ablonu ile.
4. �ubuk 2-3 �ablonu ile
5. �ubuk 3 �ablonu
 ile hareket etmekte 

(6 l�)�ift �ubuklarda 

1. �ubuk 2-3-1 
2. �ubuk 3-2-1
3. �ubuk 2-3-1
4. �ubuk 3-2-1
5. �ubuk 2-3
6. �ubuk 3 

� Son iki �ubuk hareket �ablonu her durumda ayn�. 


Algoritma 

1. E�er �ubuk tek ise 3-2-1 �ablonu 

*/

int main()
{
	
}

