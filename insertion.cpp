#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //Parameterized Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout <<endl;
}
void insertAthead(Node* &head,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        temp = head;
    }
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}
void insertAttail(Node* &tail,int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        temp = tail;
    }
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
}
void insertatposition(Node* head,int data,int position){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == position-1){
            Node* u = new Node(29);
            u -> next = temp -> next;
            temp -> next = u;
        }
        temp = temp -> next;
    }
}
int getlength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}
int main()
{
    //Statically
    Node n1(10);
    Node* head = &n1;
    Node n2(20);
    n1.next = &n2;
    //Dynamically
    Node* n3 = new Node(21);
    n2.next = n3;
    Node* n4 = new Node(23);
    n3 -> next = n4;
    n4 -> next = NULL;
    Node* tail = n4;
    print(head);
    cout<<getlength(head)<<endl;
    insertAthead(head,7);
    print(head);
    cout<<getlength(head)<<endl;
    insertAttail(tail,25);
    print(head);
    cout<<getlength(head)<<endl;
    insertatposition(head,29,3);
    print(head);
    cout<<getlength(head)<<endl;
    return 0; 
}
//OUTPUT
10->20->21->23->
4
7->10->20->21->23->
5
7->10->20->21->23->25->
6
7->10->29->20->21->23->25->
7