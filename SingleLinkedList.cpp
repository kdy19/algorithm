#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct ListNode {
	int data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int val) {
	ListNode* p=(ListNode*)malloc(sizeof(ListNode));
	p->data=val;
	p->link=head;
	head=p;

	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, int val) {
	ListNode* p=(ListNode*)malloc(sizeof(ListNode));
	p->data=val;
	p->link=pre->link;
	pre->link=p;

	return head;
}

ListNode* del_first(ListNode* head) {
	ListNode* rm;
	if(head==NULL)
		return NULL;
	rm=head;
	head=rm->link;
	free(rm);

	return head;
}

ListNode* del(ListNode* head, ListNode* pre) {
	ListNode* rm;
	rm=head;
	pre->link=rm->link;
	free(rm);

	return head;
}

void print_node(ListNode *head) {
	for(ListNode* p=head; p!=NULL; p=p->link)
		cout << p->data << "->";
	cout << "NULL \n";
}

int main() {

	ListNode* head=NULL;
	for(int i=1; i<=5; ++i) {
		head=insert_first(head, i);
		print_node(head);
	}

	for(int i=1; i<=5; ++i) {
		head=del_first(head);
		print_node(head);
	}

	return 0;
}
