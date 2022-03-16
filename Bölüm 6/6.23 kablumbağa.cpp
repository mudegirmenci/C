
/*

Mekanik bir kamlumbaðanýn bir odada yürüdüðünü düþünün. Kablumbaða yukarý ve aþaðý pozisyonda olmak üzere bir kalem tutmaktadýr.
Kalem yukarý pozisyonda ise, kablumbaða yürürken yürüdüðü yolu çizmektedir.Kalem aþaðý pozisyonda ise kaplumbaða hiçbir þey çizmeden yürür.

Kamlumbaðaya verilecek emirler:

1		Kalem yukarý
2		Kalem aþaðý
3   	Saða Dön
4		Sola dön
5,10	ileri 10 adým at( ya da 10 dan büyük bir sayý.
6		50 ye 50 lik diziyi yazdýr
9		verinin sonu


Kablumbaðanýn ortalarda bir yerde olduðunu kabul ederseniz aþaðýdaki program 12 ye 12 lik bir kare çizer.

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

1. 50x50 lik bir karede kablumbaða hareket ettireceðiz. Karemiz tamamen 0 dolu.Kablumbaðanýýn elinde bir kalem var.
   Eðer kablumbaða yukarý pozisyonda ise(yani 1) yol çizmektedir (* kullanalým) diðer pozisyonlarda boþluk býrakalým.
   kablumbaða oyun baþýnda 0,0 pozisyonunda bulunuyor.

2. pozisyon[2] isimli iki elemanlý bir dizimiz kablumbaðanýn konumunu ve yönünü saklayacak. Eðer saða 12 adým gittiyse pozisyon[]={3,0,11}, daha sonra aþaðý 10 adým gittiyse
   pozisyon[]={2,11,11} olmalý. Sað,sol sütunlar arasý hareketi, yukarý aþaðý satýrlar arasýndaki hareketi gösterir.

3. emirler dizisi kablumbaðanýn yönleri ve hareketlerini tutar. Buradaki hareketlere göre tahtada kablumbaða gidecek. 

4. Program emirleri okuyarak baþlayacak. Ýlk emir nedir? Kalem aþaðý(2) o halde kalem aþaðý pozisyona gelecek. Ýkinci emir nedir? 5,10 ileri 10 adým at. Yani 
   aþsðý 10 adým git. Bu da mecvut konumdaki sütunun 10 hücresini 1 yap demek.


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
	int konum[]={0,0};  //kablumbaðanýn güncel konum bilgisini saklayacak deðiþken. 
	int direction=0;  	 //kablumbaða yönü: 1 yukarý, 2 aþaðý ,3 sað  4 sol.
	int step=0,yon=0;  //yon 0 yukarý 1 aþaðý
	int penDown=0;   //
	
		
	for(int i=0;i<16;i++){
	
//	printf("emirler i %d\n",emirler[i]);
	
		//if(emirler[i]==1 || emirler[i]==2 || emirler[i]==3 || emirler[i]==4)  direction=emirler[i];
		
		//if(emirler[i]==1) direction=1;
	
		//if(emirler[i]==2) direction=2;
	
		if(emirler[i]>0 || emirler[i]<5) direction=turnRight(emirler[i]);
		
		if(emirler[i]==4) direction=turnLeft(emirler[i]);
		
		if(emirler[i]==5 && emirler[i]!=0 ){      				//5 hareket komutu. Eðer emir 5 ise sonraki komut kaç adým atacaðýný gösterecek. Burada konum ayarlanacak.
			step=emirler[i+1];
		
		
		
			
			for(int i=1;i<=step;i++){
				if(direction==1 && konum[0]>=0) {						//eðer konum yukarý ise satýr eksilerek gitmeli. Sütun da konum yerine gitmeli. Yani 15. satýr ve sütundan yukarý 12 adým at
					zemin[konum[0]-1][konum[1]]=i;
					--konum[0];								//yeni konumu ayarla
				} 
				if(direction==2 && konum[0]<=50) {							//eðer konum aþaðý ise satýr artarak gitmeli.
					zemin[konum[0]+1][konum[1]]=i;
			        ++konum[0];								  //yeni konumu ayarla
				}
				if(direction==3 && konum[1]<=50) {							//eðer konum sað ise sütun artarak gitmeli.
					zemin[konum[0]][konum[0]+i]=i;	 
					 ++konum[1];		 					 //yeni konumu ayarla   (sütun deðiþsin)
					 
				}
				if(direction==4 && konum[1]>=0) {							//eðer konum sol ise sütun azalarak gitmeli.
					zemin[konum[0]][konum[1]-i]=i;	    
		 			--konum[1];		  //yeni konumu ayarla   (sütun deðiþsin)
		 		
				}
				printf("x:%d  y:%d  direction:%d\n",konum[0],konum[1],direction);
			}
			
			
		}
	
		if(emirler[i]==6)	diziYazdir(zemin);			//emir 6 ise dizi yazdýr.
		
		if(emirler[i]==9) break;						//emir 9 ise programý sonlandýr.
		

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


