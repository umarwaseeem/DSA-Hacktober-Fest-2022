#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* getnewnode(int data){
node* newnode = new node();
newnode->data = data;
newnode->left =NULL;
newnode->right =NULL;
return newnode;
}
node* searchnode(node* root,int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        return root;
    }
    if(root->data<data){
        return searchnode(root->right,data);
    }
    return searchnode(root->left,data);
}

node* insert_node(node* root,int data){
    if(root == NULL){
        return getnewnode(data);
        
    }
    else if(root->data>data){
       root->left= insert_node(root->left,data);
    }
    else{
    root->right= insert_node(root->right,data);
    }
    return root;
}
node* getmax(node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right==NULL){
        return root;
    }
    return getmax(root->right);
}
node* getmin(node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left==NULL){
        return root;
    }
    return getmax(root->left);
}
int height(node* root){
    if(root == NULL){
        return 0;
    }
    return max(1+height(root->left),1+height(root->right));
}
void preorder(node* root){
if(root == NULL){
    return;
}
cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(node* root){
if(root == NULL){
    return;
}
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);

}
void postorder(node* root){
if(root == NULL){
    return;
}

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}
void levelOrder(node* root){
    queue<node*>q;
    if(root == NULL){
        return ;
    }
    q.push(root);
    while(!q.empty()){
        node* next = q.front();
        cout<<next->data<<" "; 
        if(next->left!=NULL){
            q.push(next->left);
        }
        if(next->right!=NULL){
            q.push(next->right);
        }
        q.pop();
    }
}
node* delete_node(node* root,int data){
    
     if(root==NULL){
         return NULL;
     }
     else if(data<root->data){
         root->left = delete_node(root->left,data);
     }
     else if(data>root->data){
         root->right = delete_node(root->right,data);
     }
     else{
         //leaf node
         if(root->left==NULL&&root->right==NULL){
             delete root;
             root = NULL;
             return root;
         }
         // one child
         else if(root->right==NULL){
            node* temp = root->left;
            
         }
         else if(root->left==NULL){

         }
     }

}

int main(){
node* root=NULL;
root=insert_node(root,10);
root=insert_node(root,20);
root=insert_node(root,30);
root=insert_node(root,1);
root=insert_node(root,9);
root=insert_node(root,5);
root=insert_node(root,40);
 inorder(root);
 cout<<endl;
// delete_node(root,20);
 inorder(root);
return 0;
}