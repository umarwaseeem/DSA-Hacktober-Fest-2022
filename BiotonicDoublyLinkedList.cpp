// C++ implementation to sort the biotonic doubly linked list
#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// Function to reverse a Doubly Linked List
void reverse(struct Node* head_ref)
{
	struct Node* temp = NULL;
	struct Node* current = *head_ref;

	// swap next and prev for all nodes
	// of doubly linked list
	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	// Before changing head, check for the cases
	// like empty list and list with only one node
	if (temp != NULL)
		head_ref = temp->prev;
}

// Function to merge two sorted doubly linked lists
struct Node* merge(struct Node* first, struct Node* second)
{
	// If first linked list is empty
	if (!first)
		return second;

	// If second linked list is empty
	if (!second)
		return first;

	// Pick the smaller value
	if (first->data < second->data) {
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	} else {
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

// function to sort a biotonic doubly linked list
struct Node* sort(struct Node* head)
{
	// if list is empty or if it contains a single
	// node only
	if (head == NULL || head->next == NULL)
		return head;

	struct Node* current = head->next;

	while (current != NULL) {

		// if true, then 'current' is the first node
		// which is smaller than its previous node
		if (current->data < current->prev->data)
			break;

		// move to the next node
		current = current->next;
	}

	// if true, then list is already sorted
	if (current == NULL)
		return head;

	// split into two lists, one starting with 'head'
	// and other starting with 'current'
	current->prev->next = NULL;
	current->prev = NULL;

	// reverse the list starting with 'current'
	reverse(¤t);

	// merge the two lists and return the
	// final merged doubly linked list
	return merge(head, current);
}

// Function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	// put in the data
	new_node->data = new_data;

	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Function to print nodes in a given doubly
// linked list
void printList(struct Node* head)
{
	// if list is empty
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	struct Node* head = NULL;

	// Create the doubly linked list:
	// 2<->5<->7<->12<->10<->6<->4<->1
	push(&head, 1);
	push(&head, 4);
	push(&head, 6);
	push(&head, 10);
	push(&head, 12);
	push(&head, 7);
	push(&head, 5);
	push(&head, 2);

	cout << "Original Doubly linked list:n";
	printList(head);

	// sort the biotonic DLL
	head = sort(head);

	cout << "\nDoubly linked list after sorting:n";
	printList(head);

	return 0;
}
