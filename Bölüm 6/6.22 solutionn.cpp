/* Exercise 6.22 Solution */
#include <stdio.h>

int main()
{ 
   double sales[ 4 ][ 5 ] = { 0.0 }, value, totalSales;
   double productSales[ 5 ] = { 0.0 };
   int salesPerson, product, i, j;
   
   printf( "Enter the salesperson, product, and total sales.\n" );
   printf( "Enter -1 for the salesperon to end input.\n" );
   scanf( "%d", &salesPerson );
   
   while ( salesPerson != -1 )
   { 
      scanf( "%d%lf", &product, &value );
      sales[ salesPerson ][ product ] = value;
      scanf( "%d", &salesPerson );
   }
   
   printf( "\n%s\n%s\n%s\n%s\n%s\n", "The total sales for each salesperson",
          "are displayed at the end of each", "row, and the total sales for each",
          "product are displayed at the bottom ", "of each column.\n" );
   printf( " %8d%8d%8d%8d%8d\n", 1, 2, 3, 4, 5 );

   for ( i = 0; i <= 3; i++ )
   { 
      totalSales = 0.0;
      printf( "%d", i);
      
      for ( j = 0; j <= 4; j++ )
      { 
         totalSales += sales[ i][ j ];
         printf( "%8.2f", sales[ i ][ j ] );
         productSales[ j ] += sales[ i ][ j ];
      }
      
      printf( "%8.2f\n", totalSales );
   }
   
   printf( " " );

   for ( j = 0; j <= 4; j++ )
      printf( "%8.2f", productSales[ j ] );

   return 0;
}

