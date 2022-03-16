#include <stdio.h>

int obeb(int a,int b);
int main(){
	
	printf("%d",obeb(45,54));

}

int obeb(int a,int b){
	if(b==0) return a;
	printf("a:%d b:%d\n",a,b);
	return obeb(b,a%b);
}
