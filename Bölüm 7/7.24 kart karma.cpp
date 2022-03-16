#include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 void kar( int [ ][ 13 ] );
 void dagit( const int [ ][ 13 ], const char *[ ], const char *[ ] );
 
 int main( )
 {
  const char *takim[4] ={"Kupa", "Karo", "Sinek", "Maca" };
  const char *taraf[13]={"As", "İki", "Uc", "Dort","Bes", "Alti", "Yedi", 
	  		"Sekiz", "Dokuz", "On", "Vale", "Kiz", "Papaz" };
 
     int deste[4][13] = { 0 };
 
    srand ( time( 0 ) );
    kar( deste );
    dagit( deste, taraf, takim );
 
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
 
void dagit( const int wDeste[ ][ 13 ], const char *wTaraf [ ],const char *wTakim[ ] )
 {
   int kart, satir, sutun;
     for ( kart = 1; kart <= 52; kart++ )
	for ( satir = 0; satir <= 3; satir++ )
	   for ( sutun = 0; sutun <= 12; sutun++ )
	     if ( wDeste[ satir ][ sutun] == kart )
	      {
	      if(kart==14||kart==27||kart==40)				//her oyuncunun başına gelince boşluk bırak
		   printf("\n\n");
 	    printf( "%5s - %-8s%c\n",wTakim[ satir ], wTaraf[ sutun ] );
		    if(kart%13==0)
		       printf("\n_________________");
		}
 }
