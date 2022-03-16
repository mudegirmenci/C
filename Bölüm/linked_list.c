#include <stdio.h>
#include <stdlib.h>

struct n{
   int x;
   struct  n *next;
};
typedef struct  n Node;

void bastir(Node *r) {
	while(r!=NULL) {
		printf("%d ",r->x);
		r=r->next;
	}
}
int main()
{
	Node *root;
	Node *gezer;
	root=(Node*)malloc(sizeof(Node));
	root->x=10;
	root->next=(Node*) malloc(sizeof(Node));
	root->next->x=20;
	root->next->next =(Node*) malloc(sizeof(Node));
	root->next->next->x=30;
	gezer=root;
	int i=0;
	while(gezer->next!=NULL) {
		i++;	
		printf("%d. eleman %d\n",i,gezer->x);
		gezer=gezer->next;
	}	
	
	for(i=0;i<5;i++) {
		gezer->next=(Node*)malloc(sizeof(Node));
		gezer=gezer->next;
		gezer->x=i*10;
		gezer->next=NULL;
	}
	bastir(root);


}

