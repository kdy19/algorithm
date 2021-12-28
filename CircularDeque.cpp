#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_DEQUE_SIZE 5

typedef struct {
	int front;
	int rear;
	int data[MAX_DEQUE_SIZE];
} DequeType;

void init_deque(DequeType *q) {
	q->front=0;
	q->rear=0;
}

bool deque_full(DequeType *q) {
	if((q->rear+1)%MAX_DEQUE_SIZE==q->front)
		return true;
	else
		return false;
}

bool deque_empty(DequeType *q) {
	if(q->front==q->rear)
		return true;
	else
		return false;
}

void deque_print(DequeType *q) {
	cout << "DEQUE(front=" << q->front << " rear=" << q->rear << ") = ";
	if(!deque_empty(q)) {
		int i=q->front;
		
		do {
			i=(i+1)%MAX_DEQUE_SIZE;
			cout << q->data[i] << " | ";
			if(i==q->rear)
				break;
		} while(i!=q->front);
	}
	cout << '\n';
}

void add_front(DequeType *q, int item) {
	if(deque_full(q)) 
		cout << "Deque Full\n";
	else {
		q->data[q->front]=item;
		q->front=(q->front-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
	}
}

int delete_front(DequeType *q) {
	if(deque_empty(q))
		cout << "Deque Empty\n";
	else {
		q->front=(q->front+1)%MAX_DEQUE_SIZE;
		return q->data[q->front];
	}
}

int get_front(DequeType *q) {
	if(deque_empty(q))
		cout << "Deque Empty\n";
	else
		return q->data[(q->front+1)%MAX_DEQUE_SIZE];
}

void add_rear(DequeType *q, int item) {
	if(deque_full(q))
		cout << "Deque Full\n";
	else {
		q->rear=(q->rear+1)%MAX_DEQUE_SIZE;
		q->data[q->rear]=item;	
	}
}

int delete_rear(DequeType *q) {
	int prev=q->rear;
	if(deque_full(q))
		cout << "Deque Full\n";
	else {
		q->rear=(q->rear-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
		return q->data[prev]; 
	}
}

int get_rear(DequeType *q) {
	if(deque_empty(q))
		cout << "Deque Empty\n";
	else
		return q->data[q->rear];
}

int main() {
	
	DequeType q;
	
	init_deque(&q);
	for(int i=0; i<3; ++i) {
		add_front(&q, i);
		deque_print(&q);
	}
	
	for(int i=0; i<3; ++i) {
		delete_rear(&q);
		deque_print(&q);
	}
	
	return 0;
}

