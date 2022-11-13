#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next; 

    //constructor
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //destructor to release memory in case of deletion
    ~node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory free for data with value: "<<value<<endl;
    }
};

void insertAtHead(node* &head, int d){
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(node* &tail, int d){
    node* temp = new node(d);
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(node* &tail, node* &head, int position, int d){

    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    else{
        node* temp = head;
        int cnt = 1;

        while(cnt<position-1){
            temp = temp->next;
            cnt++;
        }

        //inserting at last node
        if(temp->next==NULL){
            insertAtTail(tail, d);
            return;
        }
        node* nodeToInsert = new node(d);
        nodeToInsert->next = temp->next;

        temp->next = nodeToInsert;
    }
    

    
}

void deleteNode(int position, node* &head){
    //deleting 1st node
    if(position == 1){
        node* temp = head;
        head = head->next;
        temp-> next= NULL;
        delete temp;
    }
    else{
        //deleting other nodes
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(node* &head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
    
}
int main()
{

    node* node1 = new node(10);
    node* head = node1;
    node*tail = node1;
    // print(head);
    // insertAtHead(head, 14);
    // print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtPosition(tail , head , 3, 15);
    print(head);

    cout<<"============= after deleting ============================"<<endl;
    deleteNode(3, head);
    print(head);
    return 0;
}