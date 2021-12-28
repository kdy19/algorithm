#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_QUEUE_SIZE 5

typedef struct {
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType *q) {
	q->front=-1;
	q->rear=-1;
}

void queue_print(QueueType *q) {
	for(int i=0; i<MAX_QUEUE_SIZE; ++i) {
		if(i<=q->front||i>q->rear)
			cout << "0 ";
		else
			cout << q->data[i] << " ";
	}
	cout << '\n';
}

bool queue_full(QueueType *q) {
	if(q->rear==MAX_QUEUE_SIZE-1)
		return true;
	else
		return false;
}

bool queue_empty(QueueType *q) {
	if(q->front==q->rear)
		return true;
	else
		return false;
}

void enqueue(QueueType *q, int item) {
	if(queue_full(q)) {
		cout << "Queue Full\n";
		return;
	}
	q->data[++(q->rear)]=item;
}

int dequeue(QueueType *q) {
	if(queue_empty(q)) {
		cout << "Queue Empty\n";
		return -1;
	}
	int item=q->data[++(q->front)];
	return item;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int item=0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 1); queue_print(&q);	
	enqueue(&q, 2); queue_print(&q);	
	enqueue(&q, 3); queue_print(&q);	

	item=dequeue(&q); queue_print(&q);
	item=dequeue(&q); queue_print(&q);
	item=dequeue(&q); queue_print(&q);

	return 0;
}
