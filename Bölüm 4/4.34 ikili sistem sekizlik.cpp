#include<stdio.h>


int main (){
	int i,j;
	
	printf("ONLUK\tIKILI\tSEKIZLI\tON ALTILI\t\n");
	for(i=1;i<=25;i++) {
		 printf("%d",i);
		 printf("\t");
		 
		for(j=i;j>0;j/=2)
		  printf("%d",j%2);
		printf("\t");
		for(j=i;j>0;j=j/8)
		  printf("%d",j%8);  
	    printf("\t");
		for(j=i;j>0;j=j/16){
			switch(j%16){
			   case 10:
			   printf("A");  	     
			   break;
			   case 11:
			   printf("B");  	     
			   break;
			     case 12:
			   printf("C");  	     
			   break; 
			      case 13:
			   printf("D");  	     
			   break;
			      case 14:
			   printf("E");  	     
			   break;
			      case 15:
			   printf("F");  	     
			   break;
			   
			   default:
			   	printf("%d",j%16);  
			   	break;
			}
			
		   //printf("%d",j%16);  
	    }
		
	
		
		 
		printf("\n");
		
	}
}
