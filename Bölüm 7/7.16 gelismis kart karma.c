#include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 void kar( int [ ][ 13 ] );
 void dagit( const int [ ][ 13 ], const char *[ ], const char *[ ] );

 int main( )
 {
  const char *takim[4] ={"Kupa", "Karo", "Sinek", "Maca" };
  const char *taraf[13]={"As", "Ýki", "Uc", "Dort","Bes", "Alti", "Yedi",
	  		"Sekiz", "Dokuz", "On", "Vale", "Kiz", "Papaz" };

     int deste[4][13] ;

    //kartlara sayılar ata
     for(int i=0,kart=1;i<4;i++)
       for(int j=0;j<13;j++) {
           deste[i][j]=kart++;
         //printf("wDeste[i][j]:%d\n",wDeste[i][j]) ;
        }

    srand ( time( 0 ) );
    kar( deste );
    dagit( deste, taraf, takim );

    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++) {
            if(j%13==0) printf("\n\n");
        printf("%4d ",deste[i][j]);
        }
    printf("\n\n");

 return 0;
 }
 void kar( int wDeste[ ][ 13 ] )
 {
    int satir, sutun, kart;

 	 for(int i=0,temp=0;i<4;i++)
        for(int j=0;j<13;j++) {
           satir=i+rand()%(4-i);
           sutun=j+rand()%(13-j);
           temp=wDeste[i][j];
           wDeste[i][j]=wDeste[satir][sutun];
           wDeste[satir][sutun]=temp;
         //  printf("wDeste[i][j]:%d  Temp:%d, satir:%d sutun:%d\n",wDeste[i][j],temp,satir,sutun);
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
              if(kart==14||kart==27||kart==40)				//her oyuncunun baþýna gelince boþluk býrak
                  printf("\n\n");
               printf( "%5s - %-8s%c\n",wTakim[ satir ], wTaraf[ sutun ] );
                if(kart%13==0)
                   printf("\n_________________");
            }
 }
