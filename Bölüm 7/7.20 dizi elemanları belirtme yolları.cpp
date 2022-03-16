#include <stdio.h>

int main() {
	
	int b[]={10,20,30,40};
	int *bPtr=b;
	
	
	printf("b dizisi asagidaki metotla yazilmistir:\n"
			"Dizi belirtecleri yontemi\n");
			
	for(int i=0;i<4;i++)
		printf("b[%d]=%d\n",i,b[i]);
		
	printf("Gosterici offset yontemi\n");
			
	for(int offset=0;offset<4;offset++)
		printf("*(b+%d)=%d\n",offset,*(b+offset));
	
	printf("Gosterici belirtec yontemi\n");
	for(int i=0;i<4;i++)
		printf("bPtr[%d]=%d\n",i,bPtr[i]);
				

	printf("Gosterici offset  yontemi\n");
	for(int offset=0;offset<4;offset++)
		printf("*(bPtr+%d)=%d\n",offset,*(bPtr+offset));
}
