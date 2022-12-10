#include <iostream>
#include <cstdlib>

struct Node {
	int data;
	struct Node* next;
};

// nodeCount
int nodeCount(struct Node* head) {
	struct Node* runNode = head;
	int count = 0;

	while (runNode != NULL) {
		runNode = runNode->next;
		count += 1;
	}

	return count;
}

// insertFirst
struct Node* insertFirst(struct Node* head, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = data;
	newNode->next = NULL;

	if (head != NULL) {
		newNode->next = head;
		return newNode;
	}

	head = newNode;
	return head;
}

// insertLast
struct Node* insertLast(struct Node* head, int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* runNode = head;

	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return head;
	}

	while (runNode->next != NULL) {
		runNode = runNode->next;
	}

	runNode->next = newNode;

	return head;
}

// insertIdx
struct Node* insertIdx(struct Node* head, int data, int idx) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	struct Node* runNode = head;

	newNode->data = data;
	newNode->next = NULL;

	int count = 0;
	while (runNode->next != NULL) {
		if (count + 1 == idx) {
			newNode->next = runNode->next; 
			runNode->next = newNode;
			return head;
		}
		runNode = runNode->next;
		count += 1;
	}	

	runNode->next = newNode;

	return head;
}

// deleteFirst
struct Node* deleteFirst(struct Node* head) {
	head = head->next;
	return head;
}

// deleteLast
struct Node* deleteLast(struct Node* head) {
	struct Node* runNode = head;
	int lastNodeIdx = nodeCount(head);

	if (lastNodeIdx == 0 or lastNodeIdx == 1) {
		head = NULL;
		return head;
	}

	int count = 0;
	while (true) {
		count += 1;
		if (count == lastNodeIdx - 1) {
			break;
		}
		runNode = runNode->next;
	}
	runNode->next = NULL;

	return head;
}

// deleteIdx
struct Node* deleteIdx(struct Node* head, int idx) {
	struct Node* runNode = head;
	struct Node* prevNode = head;

	int count = 0;
	while (runNode->next != NULL) {
		if (count == idx) {
			prevNode->next = runNode->next;
		}
		prevNode = runNode;
		runNode = runNode->next;
		count += 1;
	}
	return head;
}

// searchData
bool searchData(struct Node* head, int data) {
	struct Node* runNode = head;

	while (runNode != NULL) {
		if (runNode->data == data) {
			return true;
		}
		runNode = runNode->next;
	}
	return false;
}

// nodePrint
void nodePrint(struct Node* head) {
	struct Node* runNode = head;
	while (runNode->next != NULL) {
		std::cout << runNode->data << " -> ";
		runNode = runNode->next;
	}
	std::cout << runNode->data << '\n';
}

int main() {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node*));
	head = NULL;

	head = insertLast(head, 4);
	head = insertFirst(head, 1);	
	head = insertFirst(head, 2);	
	head = insertFirst(head, 3);	
	head = insertLast(head, 4);
	head = insertIdx(head, 44, 1);
	head = insertIdx(head, 55, 123);
	head = deleteFirst(head);
	nodePrint(head);
	std::cout << nodeCount(head) << '\n';
	std::cout << searchData(head, 4) << '\n';
	std::cout << searchData(head, 100) << '\n';
	head = deleteLast(head);
	nodePrint(head);
	head = deleteLast(head);
	nodePrint(head);
	head = deleteFirst(head);
	nodePrint(head);
	head = deleteIdx(head, 1);
	nodePrint(head);

	return 0;
}
