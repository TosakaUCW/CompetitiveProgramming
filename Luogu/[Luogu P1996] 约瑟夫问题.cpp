#include <stdio.h>

#define Rep(i,x,y) for(register int i=x;i<=y;i++)

int n,m;

namespace List {
	struct Node {
		int data;
		Node *next;
	} *head,*p,*q;
	void build(int n) {
		Rep(i,1,n) {
			if(i==1) {
				head=new Node;
				head->data=i;
				p=head;
			} else {
				p=new Node;
				p->data=i;
				q->next=p;
			}
			q=p;
		}
		q->next=head;
		p=q;
	}
	void print(int n) {
		Rep(i,1,n) {
			printf("%d:%d\n",i,p->data);
			p=p->next;
		}
	}
	inline void del() {
		p->next=p->next->next;
	}
};

void Joseph() {
	Rep(k,1,n) {
		Rep(i,1,m-1)List::p=List::p->next;
		printf("%d ",List::p->next->data);
		List::del();
	}
}

int main() {
	scanf("%d%d",&n,&m);
	if(n==0 and m==0)return 0;
	List::build(n);
#ifdef debug
	List::print(n);
#endif
	Joseph();
	return 0;
}
