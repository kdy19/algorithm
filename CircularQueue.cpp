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
	q->front=0;
	q->rear=0;
}

bool queue_full(QueueType *q) {
	if((q->rear+1)%MAX_QUEUE_SIZE==q->front)
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

void queue_print(QueueType *q) {
	cout << "QUEUE(front=" << q->front << " rear=" << q->rear << ") = ";
	if(!queue_empty(q)) {
		int i=q->front;
		
		do {
			i=(i+1)%MAX_QUEUE_SIZE;
			cout << q->data[i] << " | ";
			if(i==q->rear)
				break;
		} while(i!=q->front);
	}
	cout << '\n';
}

void enqueue(QueueType *q, int item) {
	if(queue_full(q))
		cout << "Queue Full\n";
	else {
		q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
		q->data[q->rear]=item;
	}
}

int dequeue(QueueType *q) {
	if(queue_empty(q))
		cout << "Queue Empty\n";
	else {
		q->front=(q->front+1)%MAX_QUEUE_SIZE;
	}
		return q->data[q->front];
}

int main() {
	
	QueueType q;
	
	init_queue(&q);
	
	enqueue(&q, 1); queue_print(&q);
	enqueue(&q, 2); queue_print(&q);
	enqueue(&q, 3); queue_print(&q);
	enqueue(&q, 4); queue_print(&q);
	enqueue(&q, 5); queue_print(&q);
	
	int item;
	item=dequeue(&q); queue_print(&q);
	item=dequeue(&q); queue_print(&q);
	item=dequeue(&q); queue_print(&q);
	item=dequeue(&q); queue_print(&q);
	item=dequeue(&q); queue_print(&q);
	
	enqueue(&q, 1); queue_print(&q);
	enqueue(&q, 2); queue_print(&q);
	
	item=dequeue(&q); queue_print(&q);
	
	return 0;
}

