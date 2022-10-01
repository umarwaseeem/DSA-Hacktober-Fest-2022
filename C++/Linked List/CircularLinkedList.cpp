#include <iostream>
using namespace std;


class Node{

    public:

        int data;
        Node* next;


        Node()
        {
            next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    
};

class CircularList{

    Node* head;
    Node* tail;
    int length;

public:
    CircularList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
        }

        void insertAtTail(int data){
            if(head == NULL)
            {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                tail->next = head;

                length++;
            }
            else
            {
                Node* newNode = new Node(data);
                tail->next = newNode;
                tail = tail->next;
                tail->next = head;

                length++;
            }
        }

        void insertAtHead(int data)
        {
            if (head == NULL)
            {
                Node *newNode = new Node(data);
                head = newNode;
                tail = newNode;
                tail->next = head;

                length++;
            }
            else
            {
                Node *newNode = new Node(data);

                tail->next = newNode;
                newNode->next = head;
                head = newNode;

                length++;
            }
        }
        


        // !====> issues in this function 
        void insertAfter(int index, int data)
        {
            if(index > length || index < 0)
            {
                cout << "Index " << index << " is out of bounds " << endl;
            }
            else
            {
                int i = 0;
                Node* current = head;
                do
                {
                    current = current->next;
                    i++;
                }
                while (current != head && i <= index);
                
                Node* newNode = new Node(data);

                newNode->next = current->next;
                current->next = newNode;

                length++;
            }
        }

        void deleteHead()
        {

            if(head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }



            Node* toDelete = head;
            tail->next = head->next;
            head = head->next;
            delete toDelete;

            length--;
        }

        void deleteTail()
        {
            if (head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }

            Node* current = head;
            Node* toDelete = tail;
            while (current->next != tail)
            {
                current = current->next;
            }
            tail = current;
            tail->next = head;

            length--;
        }
        void print() 
        {
            if (head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }

            Node* current = head;

            do
            {
                cout << current->data << " -> " ;
                current = current->next;
            }
            while (current != head);
            cout << "NULL" << endl;
        }
};


int main() 
{ 
    CircularList l1;


    l1.insertAtTail(0);
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.print();
    l1.deleteTail();
    l1.print();

    return 0;
}