#include <stdio.h>

int tamsayikuvveti(int taban,int us);

int main(){
	printf("taban dondur:%d\n",tamsayikuvveti(3,4));
}

int tamsayikuvveti(int taban,int us){
    int sonuc=taban;
	while(us>1) {
    	sonuc*=taban;
    	us--;
   }
	return sonuc;
	 	
}
