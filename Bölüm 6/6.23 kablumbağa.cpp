
/*

Mekanik bir kamlumba�an�n bir odada y�r�d���n� d���n�n. Kablumba�a yukar� ve a�a�� pozisyonda olmak �zere bir kalem tutmaktad�r.
Kalem yukar� pozisyonda ise, kablumba�a y�r�rken y�r�d��� yolu �izmektedir.Kalem a�a�� pozisyonda ise kaplumba�a hi�bir �ey �izmeden y�r�r.

Kamlumba�aya verilecek emirler:

1		Kalem yukar�
2		Kalem a�a��
3   	Sa�a D�n
4		Sola d�n
5,10	ileri 10 ad�m at( ya da 10 dan b�y�k bir say�.
6		50 ye 50 lik diziyi yazd�r
9		verinin sonu


Kablumba�an�n ortalarda bir yerde oldu�unu kabul ederseniz a�a��daki program 12 ye 12 lik bir kare �izer.

2
5,12
3
5,12
3
5,12
3
5,12
1
6
9

Pseudo code:

1. 50x50 lik bir karede kablumba�a hareket ettirece�iz. Karemiz tamamen 0 dolu.Kablumba�an��n elinde bir kalem var.
   E�er kablumba�a yukar� pozisyonda ise(yani 1) yol �izmektedir (* kullanal�m) di�er pozisyonlarda bo�luk b�rakal�m.
   kablumba�a oyun ba��nda 0,0 pozisyonunda bulunuyor.

2. pozisyon[2] isimli iki elemanl� bir dizimiz kablumba�an�n konumunu ve y�n�n� saklayacak. E�er sa�a 12 ad�m gittiyse pozisyon[]={3,0,11}, daha sonra a�a�� 10 ad�m gittiyse
   pozisyon[]={2,11,11} olmal�. Sa�,sol s�tunlar aras� hareketi, yukar� a�a�� sat�rlar aras�ndaki hareketi g�sterir.

3. emirler dizisi kablumba�an�n y�nleri ve hareketlerini tutar. Buradaki hareketlere g�re tahtada kablumba�a gidecek. 

4. Program emirleri okuyarak ba�layacak. �lk emir nedir? Kalem a�a��(2) o halde kalem a�a�� pozisyona gelecek. �kinci emir nedir? 5,10 ileri 10 ad�m at. Yani 
   a�s�� 10 ad�m git. Bu da mecvut konumdaki s�tunun 10 h�cresini 1 yap demek.


*/
#include <stdio.h>
#define SATIR 50
#define SUTUN 50
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
void diziYazdir(const int [][SUTUN]);
int turnRight( int d ) ;
int turnLeft(int x);

int main()
{
	int zemin[SATIR][SUTUN]={0}, emirler[]={2,5,12,3,5,12,3,5,12,3,5,12,1,6,9 };
	int konum[]={0,0};  //kablumba�an�n g�ncel konum bilgisini saklayacak de�i�ken. 
	int direction=0;  	 //kablumba�a y�n�: 1 yukar�, 2 a�a�� ,3 sa�  4 sol.
	int step=0,yon=0;  //yon 0 yukar� 1 a�a��
	int penDown=0;   //
	
		
	for(int i=0;i<16;i++){
	
//	printf("emirler i %d\n",emirler[i]);
	
		//if(emirler[i]==1 || emirler[i]==2 || emirler[i]==3 || emirler[i]==4)  direction=emirler[i];
		
		//if(emirler[i]==1) direction=1;
	
		//if(emirler[i]==2) direction=2;
	
		if(emirler[i]>0 || emirler[i]<5) direction=turnRight(emirler[i]);
		
		if(emirler[i]==4) direction=turnLeft(emirler[i]);
		
		if(emirler[i]==5 && emirler[i]!=0 ){      				//5 hareket komutu. E�er emir 5 ise sonraki komut ka� ad�m ataca��n� g�sterecek. Burada konum ayarlanacak.
			step=emirler[i+1];
		
		
		
			
			for(int i=1;i<=step;i++){
				if(direction==1 && konum[0]>=0) {						//e�er konum yukar� ise sat�r eksilerek gitmeli. S�tun da konum yerine gitmeli. Yani 15. sat�r ve s�tundan yukar� 12 ad�m at
					zemin[konum[0]-1][konum[1]]=i;
					--konum[0];								//yeni konumu ayarla
				} 
				if(direction==2 && konum[0]<=50) {							//e�er konum a�a�� ise sat�r artarak gitmeli.
					zemin[konum[0]+1][konum[1]]=i;
			        ++konum[0];								  //yeni konumu ayarla
				}
				if(direction==3 && konum[1]<=50) {							//e�er konum sa� ise s�tun artarak gitmeli.
					zemin[konum[0]][konum[0]+i]=i;	 
					 ++konum[1];		 					 //yeni konumu ayarla   (s�tun de�i�sin)
					 
				}
				if(direction==4 && konum[1]>=0) {							//e�er konum sol ise s�tun azalarak gitmeli.
					zemin[konum[0]][konum[1]-i]=i;	    
		 			--konum[1];		  //yeni konumu ayarla   (s�tun de�i�sin)
		 		
				}
				printf("x:%d  y:%d  direction:%d\n",konum[0],konum[1],direction);
			}
			
			
		}
	
		if(emirler[i]==6)	diziYazdir(zemin);			//emir 6 ise dizi yazd�r.
		
		if(emirler[i]==9) break;						//emir 9 ise program� sonland�r.
		

	}
	
	


}

void diziYazdir(const int zemin[][SUTUN]){

	for(int i=0;i<50;i++) {
		printf("%\n");
	   for(int j=0;j<50;j++){
	   	  printf("%2d",zemin[i][j]);
	   }
 }
}


int turnRight( int d ) 
{ 
  if(d==4)  return 1;
  if(d==3)  return 2;
  if(d==2)  return 4;
  if(d==1)  return 3;
  
}

int turnLeft(int d)
{

  if(d==4)  return 2;
  if(d==3)  return 1;
  if(d==2)  return 3;
  if(d==1)  return 4;
}


