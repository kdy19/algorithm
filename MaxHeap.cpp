#include <cstdio>

#define MAX_SIZE 1024

class HeapNode {
	int key;
public:
	HeapNode(int k = 0) : key(k) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { printf("%4d", key); }
};

class MaxHeap {
	HeapNode node[MAX_SIZE];
	int size;
public:
	MaxHeap() : size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_SIZE - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; };
	HeapNode& getLeft(int i) { return node[i * 2]; };
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key) {
		if (isFull()) return;
		int i = ++size;

		while (i != 1 && key > getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove() {
		if (isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;

		while (child <= size) {
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
				child++;

			if (last.getKey() >= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child; 
			child *= 2;
		}
		node[parent] = last;
		return item;
	}

	HeapNode find() { return node[1]; }

	void display() {
		for (int i = 1, level = 1; i <= size; ++i) {
			if (i == level) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n---------------");
	}

};

int main(int argc, char** argv) {
	MaxHeap heap;
	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(9);
	heap.insert(3);
	heap.insert(7);
	heap.display();

	heap.remove();
	heap.display();

	heap.remove();
	heap.display();

	return 0;
}
