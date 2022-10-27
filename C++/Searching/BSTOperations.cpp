#include <iostream>
using namespace std;
struct BST
{
    int id;
    BST *left = NULL, *right = NULL;
};
BST *root = NULL;
void insertNode(BST *curr)
{
    if (root == NULL)
    {
        root = curr;
    }
    else
    {
        BST *p = root, *q = NULL;
        while (p != NULL)
        {
            q = p;
            if (p->id >curr->id)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (q->id >curr->id)
        {
            q->left = curr;
        }
        else
        {
            q->right = curr;
        }        
    }
}
void autoFillBST()
{
    int arr[] = {80, 60, 100, 110, 200, 210, 105, 50, 20, 40, 65, 75, 82, 84, 85};
    int size = 15;
    for (int i = 0; i < size; i++)
    {
        BST *curr = new BST; curr->id = arr[i];
        insertNode(curr);
    }
    cout<<"\nBinary Search Tree Constructed"<<endl;
}
void inorderTraversal(BST *p)
{
    if (p!=NULL)
    {
        inorderTraversal(p->left);
        cout<<"ID: "<<p->id<<endl;
        inorderTraversal(p->right);
    }
}
void postOrderTraversal(BST *p)
{
    if (p!=NULL)
    {
        inorderTraversal(p->left);
        inorderTraversal(p->right);
        cout<<"ID: "<<p->id<<endl;
    }   
}
void preOrderTraversal(BST *p)
{
    if (p!=NULL)
    {
        cout<<"ID: "<<p->id<<endl;
        inorderTraversal(p->left);
        inorderTraversal(p->right);
    }
}
BST* searchNode(int key)
{
    BST *p = root;
    while (p!=NULL)
    {
        if(p->id == key)
        {
            return p;
        }
        else if (p->id > key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return NULL;
}

BST* rightLeastNode(BST *p)
{
    while (p->left!=NULL)
    {
        cout<<"Finding right least value: "<<p->id<<endl;
        p = p->left;
    }
    cout<<"Finding right least value: "<<p->id<<endl;
    return p;
}
void deleteNode(BST *nodeToDelete)
{
    if (nodeToDelete->left !=NULL && nodeToDelete->right != NULL)
    {
        BST *rightLeast = rightLeastNode(nodeToDelete->right);
        nodeToDelete->id = rightLeast->id;
        cout<<"Found node to delete: "<<nodeToDelete->id<<endl;
        BST *p = nodeToDelete->right;
        while (p != rightLeast)
        {
            cout<<"Finding the node to delete: "<<p->id<<endl;
            p = p->left;
        }
        cout<<"Finding the node to delete: "<<p->id<<endl;
        if (p != NULL && p == rightLeast)
        {
            deleteNode(p);
        }
        cout<<" node after deletion: "<<p->id<<endl;
    }
    else if (nodeToDelete->left != NULL && nodeToDelete->right == NULL)
    {
        nodeToDelete->id = nodeToDelete->left->id;
        nodeToDelete->left = nodeToDelete->left->left;
    }
    else if (nodeToDelete->left == NULL && nodeToDelete->right != NULL)
    {
        nodeToDelete->id = nodeToDelete->right->id;
        nodeToDelete->right = nodeToDelete->right->right;
    }
    else
    {
        delete nodeToDelete; nodeToDelete = NULL;
    }
}
int countleaf = 0; //variable which will store num of leaf NODES
void countLeafNodes(BST *p)
{
    if (p!=NULL)
    {
        if(p->left== NULL&&p->right ==NULL)
        {
            countleaf++;
        }
    
        countLeafNodes(p->left);
        countLeafNodes(p->right);
    }
}
int count = 0; //variable which will store number of NODES
void countNumOfNodes(BST *p)
{
    if (p!=NULL)
    {
        count++;
        countNumOfNodes(p->left);
        countNumOfNodes(p->right);
    }
}
int max(int leftHeight, int rightHeight)
{
    if (leftHeight > rightHeight)
    {
        return leftHeight;
    }
    return rightHeight;
}
int findHeight(BST *p)
{
    if (p == NULL)
    {
        return -1;
    }
    int leftHeight = findHeight(p->left);
    int rightHeight = findHeight(p->right);
    
    return max(leftHeight, rightHeight) + 1;
}
void opt()
{
    cout<<"\n1- Insert a Node"<<endl
        <<"2- AutoFill BST"<<endl
        <<"3- Delete a Node"<<endl
        <<"4- Search a Node"<<endl
        <<"5- InOrder Traversal of Tree"<<endl
        <<"6- PreOrder Traversal of Tree"<<endl
        <<"7- PostOrder Traversal of Tree"<<endl
        <<"8- Count Nodes of Tree"<<endl
        <<"9- Count Nodes at Right of Tree"<<endl
        <<"10- Count Leaf Nodes of Tree"<<endl
        <<"11- Find Height of Tree"<<endl
        <<"0- Terminate the Program"<<endl;

    cout<<"Enter your Choice: ";
    int choice; cin>>choice;

    switch (choice)
    {
    case   1:
        cout<<"\nINSERT A NODE METHOD"<<endl;
        BST *curr; curr = new BST;
        cout<<"Enter a id: "; cin>>curr->id;
        insertNode(curr); opt(); break;
    
    case   2:
        cout<<"\nAUTOFILL BST METHOD"<<endl;
        autoFillBST(); opt(); break;

    case   3:
        cout<<"\nDELETE A NODE METHOD"<<endl;
        cout<<"Enter id of Node to Delete: "; int val; cin>>val;
        BST *nodeToDelete; nodeToDelete = searchNode(val);
        deleteNode(nodeToDelete); opt(); break;
    
    case   4:
        cout<<"\nSEARCH A NODE METHOD"<<endl;
        cout<<"Enter id to Search: "; int key; cin>>key;
        if (searchNode(key) != NULL)
        {
            cout<<"Id found: "<<searchNode(key)->id<<endl;
        }
        else
        {
            cout<<"Id not found"<<endl;
        }
        opt(); break;
    
    case   5:
        cout<<"\nINORDER TRAVERSAL OF TREE METHOD"<<endl;
        inorderTraversal(root); opt(); break;
    
    case   6:
        cout<<"\nPREORDER TRAVERSAL OF TREE METHOD"<<endl;
        preOrderTraversal(root); opt(); break;
    
    case   7:
        cout<<"\nPOSTORDER TRAVERSAL OF TREE METHOD"<<endl;
        postOrderTraversal(root); opt(); break;
    
    case   8:
        cout<<"\nCOUNT NODES OF TREE METHOD"<<endl;
        countNumOfNodes(root);
        cout<<"Number of Nodes in Tree is: "<<count<<endl; opt(); break;
    
    case   9:
        cout<<"\nCOUNT NODES at RIGHT OF TREE METHOD"<<endl;
        countNumOfNodes(root->right);
        cout<<"Number of Nodes at right of Tree is: "<<count<<endl; opt(); break;
    
    case   10:
        cout<<"\nCOUNT LEAF NODE OF TREE METHOD"<<endl;
        countLeafNodes(root);
        cout<<"Number of Leaf Nodes of Tree is: "<<countleaf<<endl; opt(); break;
    
    case   11:
        cout<<"\nFIND HEIGHT OF TREE METHOD"<<endl;
        cout<<"Height of Tree is: "<<findHeight(root)<<endl; opt(); break;
    
    case   0:
        cout<<"\nProcess Terminated Successfully"<<endl;
        break;
    
    default:
        cout<<"INVALID CHOICE TRY AGAIN!!"<<endl;
        opt(); break;
    }
}
int main()
{
    opt();
    return 0;
}