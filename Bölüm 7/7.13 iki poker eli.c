#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDCOUNT 5		//daðýtýlacak el sayýsý
#define PLAYERCOUNT 1  //oyundaki oyuncu sayýsý

void kar( int [ ][ 13 ] );
void dagit( const int [ ][ 13 ], const char *[ ], const char *[ ],char *[][3] );
int isOnePair(char  *playerHand[][3],int cardcount );
int isTwoPair(char  *playerHand[][3],int cardcount );
int isThreeSuits(char  *playerHand[][3],int cardcount );
int isFourSuits(char  *playerHand[][3],int cardcount );

 int main( )
 {
  const char *suits[4] ={"Kupa", "Karo", "Sinek", "Maca" };
  const char *faces[13]={"As", "2", "3", "3","5", "6", "7", "8", "9", "10", "Vale", "Kiz", "Papaz" };

  char *playerHand[5][3]={NULL};   //sutun 0 oyunculari tutacak.sutun 1 oyuncu elindeki suits sutun 1 oyuncu elindeki faces.
  int deste[4][13] = { 0 };




    srand ( time( 0 ) );
    kar( deste );
    dagit( deste, faces, suits,playerHand );

    if(isOnePair(playerHand,CARDCOUNT)==1) printf("El bir cift iceriyor\n");
    if(isTwoPair(playerHand,CARDCOUNT)==1) printf("El iki cift iceriyor\n");
    if(isThreeSuits(playerHand,CARDCOUNT)==1) printf("El uc ayni kart iceriyor\n");
    if(isFourSuits(playerHand,CARDCOUNT)==1) printf("El dort ayni kart iceriyor\n");


 return 0;
 }
 void kar( int wDeste[ ][ 13 ] )
 {
    int satir, sutun, kart;
      for ( kart = 1; kart <= 52; kart++ )
	 {
  	   do {
 		  satir = rand( ) % 4;
   		  sutun = rand() % 13;
 		   } while( wDeste [ satir ][ sutun ] != 0 );
 	  wDeste[ satir ][ sutun] = kart;
 	}
 }

void dagit( const int wDeste[ ][ 13 ], const char *wFaces [ ],const char *wSuits[ ],char *playerHand[][3] )
 {
   int kart, satir, sutun,elKart=0,oyuncu=1;

     for ( kart = 1; kart <= 10; kart++ )
	   for( satir = 0; satir <= 3; satir++ )
	      for ( sutun = 0; sutun <= 12; sutun++ )
	     if ( wDeste[ satir ][ sutun] == kart )
	      {
		    printf( "%5s - %-8s\n",wSuits[ satir ], wFaces[ sutun ]);

            playerHand[elKart][0]=oyuncu;
			playerHand[elKart][1]=wSuits[ satir ];
            playerHand[elKart][2]=wFaces[ sutun ];
            elKart++;

		    if(kart%5==0){
		     	printf("\n_________________\n\n");
                oyuncu++;
			}

		}
		printf("oyuncu:%d\n",oyuncu);
 }

 /* Elin bir çift(per) içerip içermediðini kontrol et */
int isOnePair(char  *playerHand[][3],int cardcount )
{

    for(int i=0;i<cardcount;i++)
        for(int j=0;j<cardcount;j++){
            if(j!=i && playerHand[i][1]==playerHand[j][1])
                return 1;
        }
    return 0;
}


/* El iki çift(döper) içeriyor mu kontrol et */
int isTwoPair(char  *playerHand[][3],int cardcount )
{
    char *temp;
    for(int i=0,count=0;i<cardcount;i++){
        for(int j=0;j<cardcount;j++){
            if(j!=i && playerHand[i][1]==playerHand[j][1]) {
                count++;
                if(count>2     ) return 1;
            }
      }
    count=0;
    }
    return 0;
}

/* El aynı üç kart içeriyor mu */
int isThreeSuits(char  *playerHand[][3],int cardcount )
{
    for(int i=0,count=1;i<cardcount;i++){
        for(int j=0;j<cardcount;j++){
            if(j!=i && playerHand[i][0]==playerHand[j][0]) {
                count++;
                if(count>2) return 1;
            }
    }
      count=1  ;
    }
    return 0;
}

/* El aynı dört kart içeriyor mu */
int isFourSuits(char  *playerHand[][3],int cardcount )
{
    for(int i=0,count=1;i<cardcount;i++){
        for(int j=0;j<cardcount;j++){
            if(j!=i && playerHand[i][0]==playerHand[j][0]) {
                count++;
                if(count>3) return 1;
            }
    }
      count=1  ;
    }
    return 0;
}

