#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDCOUNT 5		//daðýtýlacak el sayýsý
#define PLAYERCOUNT 1  //oyundaki oyuncu sayýsý

void kar( int [ ][ 13 ] );
void dagit( const int [ ][ 13 ], const char *[ ], const char *[ ],char *[][1] );

  
 int main( )
 {
  const char *suits[4] ={"Kupa", "Karo", "Sinek", "Maca" };
  const char *faces[13]={"As", "2", "3", "3","5", "6", "7", "8", "9", "10", "Vale", "Kiz", "Papaz" };
 
  char *playerHand[4][1]={NULL};   //oyuncuya daðýtýlan kartlar tutulacak.
  int deste[4][13] = { 0 };
 
  
 for(int i=0;i<5;i++)
    printf("%s\n",playerHand[4][i]);
    
    srand ( time( 0 ) );
    kar( deste );
    dagit( deste, faces, suits,playerHand );
    
 
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
 
void dagit( const int wDeste[ ][ 13 ], const char *wFaces [ ],const char *wSuits[ ],char *playerHand[][1] )
 {
   int kart, satir, sutun;
   char test[7];
     for ( kart = 1; kart <= 5; kart++ )
	   for( satir = 0; satir <= 3; satir++ )
	      for ( sutun = 0; sutun <= 12; sutun++ )
	     if ( wDeste[ satir ][ sutun] == kart )
	      {   
		    printf( "%5s - %-8s%c \n",wSuits[ satir ], wFaces[ sutun ]);
		     
			playerHand[satir][sutun]=&wSuits[ satir ];
		     //playerHand[satir][sutun]=wFaces[ sutun ];
		    if(kart%5==0){
		     	printf("\n_________________");
		     	
			}
		       
		}
 }
 
 
