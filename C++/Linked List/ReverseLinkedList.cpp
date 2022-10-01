/* 
C++ program for reversing a given linked list with:
   Time Complexity: O(n)
   Space Complexity: O(1) 
*/

#include<bits/stdc++.h>
using namespace std;
 
struct node {
    int data;
    struct node *next;
};
 
// We construct a linked list and use this function to push elements to the list 
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}
 
// Function to reverse the list
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}
 
// Checking our program 
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
 
int main() {
    struct node *head = NULL;
    push(&head, 23);
    push(&head, 15);
    push(&head, 9);
    push(&head, 2);

    cout << "Original Linked List" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "Reversed Linked List"<<endl;
    printnodes(head);
    return 0;
}
