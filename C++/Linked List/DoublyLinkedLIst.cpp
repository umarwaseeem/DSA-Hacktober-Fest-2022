#include <iostream>
using namespace std;

class Node
{
    public:
        
        int value;
        Node* next;
        Node* prev;
        
        Node()
        {
            value = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int value)
        {
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }

};

class DoubleList{

    Node* head;
    Node* tail;
    int length;

    public:

    DoubleList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    Node* getNode(Node* node) // returns null if node does not exist
    {
        Node* current = head;
        while (current != NULL && current!= node)
        {
            current = current->next;
        }
        return current;
    }

    void append(int data){
        if(head == NULL)
        {
            Node* newNode = new Node(data);


            head = newNode;
            tail = newNode;

            length++;
        }
        else
        {
            Node* newNode = new Node(data);

            tail->next = newNode;   // tail to new node link
            newNode->prev = tail;   // tail at back of new node
            
            tail = tail->next;      // move tail to new node

            length++;
        }
    }

    void prepend(int data) // -insert at head
    {
        if(head == NULL)
        {
            Node* newNode = new Node(data);

            head = newNode;
            tail = newNode;

            length++;
        }
        else if(head!=NULL)
        {
            Node* newNode = new Node(data);
            newNode->next = head; 

            head->prev = newNode; 
            head = head->prev;

            length++;
        }
    }

    void insertAfter(int index, int data)
    {
        if(index < length)
        {
            cout << "Index out of bounds, index = " << index << "does not exist " << endl;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            Node* newNode = new Node(data);
            newNode->next = current->next;
            newNode->prev = current;

            current->next = newNode;
            newNode->next->prev = newNode;
        }   
    }

    void deleteHead()
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;

        length--;
    }

    void deleteTail()
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;

        length--;
    }

    void deleteIndex(int index)
    {
        if(index >= 0 && index < length)
        {
            if(index == 0)
            deleteHead();

            else if(index == length -1)
            deleteTail();

            else
            {
                Node* current = head;
                for (int i = 0; i < index && current != NULL; i++)
                {
                    current = current->next;
                }
                Node* toDelete = current ;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete toDelete;

                length--;
            }

        }
        else
        {
            cout << "Index out of bounds" << endl;
        }
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isNotEmpty()
    {
        return length !=0;
    }

    void print()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node* current = head;
            cout << endl << endl;
            while (current!=NULL)
            {
                cout << current->value << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl << endl << endl;
        }
    }
};


int main()
{
    DoubleList l1;
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    l1.append(8);
    
    cout << "BEFORE";
    l1.print();
    
    l1.deleteIndex(4);
    
    cout << "AFTER" << endl;
    l1.print();

}