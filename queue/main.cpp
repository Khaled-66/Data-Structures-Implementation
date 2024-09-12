#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(){
        data=0;
        next=nullptr;
    }
};
class queue{
public:
    node* front;
    node* rear;
    queue(){
        front=nullptr;
        rear=nullptr;
    }

    bool isempty(){
        if(front==nullptr){
            return true;
        }
        else return false;
    }

    void enqueue(int item){
        node *newnode=new node;
        newnode->data=item;
        if(isempty()){
            front =rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
            newnode->next=nullptr;
        }
    }

    void display(){
        if(isempty()){
            cout<<"no items to display";
        }
        else{
            node*ptr=front;
            while(ptr!=nullptr){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
        }}

    void dequeue(){
        if(isempty())cout<<"the queue is empty"<<endl;
        else if(front==rear){
            delete front;
            front =rear=nullptr;
        }
        else {
            node *delptr = front;
            front = front->next;
            delete delptr;
        }
    }

    void peek(){
        cout<<front->next<<endl;
    }

    void get_rear(){
        cout<<rear->data<<endl;
    }

    void counter(){
        int count=0;
        node* temp=front;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        cout<<count<<endl;
    }

    bool isfound(int item){
        bool found=false;
        node *temp=front;
        while(temp!=nullptr){}
        if(temp->data==item){
            found=true;
            temp=temp->next;
        }
        return found;

    }

    void clear(){
        while(!isempty()){
            dequeue();
        }
    }

};

int main(){
queue q1;
q1.enqueue(23);
q1.enqueue(12);
q1.enqueue(45);
q1.enqueue(2);
q1.display();
}