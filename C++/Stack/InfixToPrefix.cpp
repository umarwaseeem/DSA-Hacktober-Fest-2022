#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

char arr[20];
int top = -1;
void push(char operand){
        top++;
        arr[top] = operand;
}
bool isEmpty(){
    return top == -1;
}
char pop(){
    if(isEmpty())
        cout << "UNDERFLOW";
    else{
        char ch = arr[top];
        top--; return(ch);
    }
    return 0;
}
char peek(){
    return arr[top];
}
int checkPriority (char operation)
{
    if(operation == '+' || operation =='-')
        return 1;
    if(operation == '*' || operation =='/')
        return 2;
    if(operation == '^')
        return 3;
    return 0;
}
string toPost(string infix)
{
    int i=0;
    string postfix = "";
    while(infix[i]!='\0')
    {
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')
        {
            postfix += infix[i];
            i++;
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(arr[top]!='(')
                postfix += pop();
            pop();
            i++;
        }
        else
        {
            while (!isEmpty() && checkPriority(infix[i]) <= checkPriority(peek())){
                postfix += pop();
            }
            push(infix[i]);
            i++;
        }
    }
    while(!isEmpty()){
        postfix += pop();
    }
    return postfix;
}

int main()
{
    cout << "CONVERSION OF INFIX TO PREFIX " << endl;
    string infix;
    cout << "Please enter your infix expression: " << endl;
    cin >> infix;
    string postfix;
    postfix = toPost(infix);
    cout << "The prefix for " << infix << " is " << postfix << endl;
    return 0;
}
