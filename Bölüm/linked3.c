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

void ekle(Node *r,int x)
{
	while(r->next!=NULL)
		r=r->next;
	r->next=(Node*)malloc(sizeof(Node));
	r->next->x=x;
//	r->next->next=NULL;
	
}
int main()
{
	Node *root;
	Node *gezer;
	root=(Node*)malloc(sizeof(Node));
	root->x=10;
	root->next=NULL;
	
	for(int i=0;i<5;i++) {
		ekle(root,i*10);
	}
	bastir(root);


}

