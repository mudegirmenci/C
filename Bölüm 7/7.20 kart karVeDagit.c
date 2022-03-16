
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


 void karVeDagit(  int [ ][ 13 ], const char *[ ], const char *[ ] );

 int main( )
 {
  const char *takim[4] ={"Kupa", "Karo", "Sinek", "Maca" };
  const char *taraf[13]={"As", "Ýki", "Uc", "Dort","Bes", "Alti", "Yedi",
	  		"Sekiz", "Dokuz", "On", "Vale", "Kiz", "Papaz" };

     int deste[4][13] ;



    srand ( time( 0 ) );

    karVeDagit( deste, taraf, takim );

    //Karılmış 52 kartı yaz
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++) {
            if(j%13==0) printf("\n\n");
        printf("%4d ",deste[i][j]);
        }
    printf("\n\n");

 return 0;
 }

/* 52 kartı ayarlar ve kardığı sırayla dağıtır. */
void karVeDagit(  int wDeste[ ][ 13 ], const char *wTaraf [ ],const char *wTakim[ ] )
 {


    //52 kartı ayarla
     for(int i=0,kart=1;i<4;i++)
       for(int j=0;j<13;j++) {
           wDeste[i][j]=kart++;
        }

    int  satir, sutun,temp;
	   for (int i=0; i <4;i++ ) {
	      for ( int j=0,say=1; j < 13; j++,say++ ) {
                satir=i+rand()%(4-i);
                sutun=j+rand()%(13-j);
                temp=wDeste[i][j];
                wDeste[i][j]=wDeste[satir][sutun];
                wDeste[satir][sutun]=temp;

                printf( "Say:%4d %5s - %-8s%c\n",say,wTakim[ satir ], wTaraf[ sutun ] );
	      }
	      printf("\n_________________\n");
	   }
 }
