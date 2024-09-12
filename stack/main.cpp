#include <iostream>
using namespace std;
class node {
public:
    int data;
    node *next;
    node() {
        data = 0;
        next = NULL;
    }
};
class stack {
    node* top;
    int count;
public:
    stack() {
        top = nullptr;
        count = 0;
    }

    bool isempty() {
        return top == nullptr;
    }

    void push(int item) {
        node* newnode = new node();
        newnode->data = item;
        if (isempty()) {
            newnode->next = nullptr;
        } else {
            newnode->next = top;
        }
        top = newnode;
        count++;
    }

    void pop(){
        if (isempty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        node* delptr = top;
        top = top->next;
        delete delptr;
        count--;
    }

    void peek() {
        if (!isempty()) {
            cout << top->data << endl;
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void counter() {
        cout << count << endl;
    }

    void search(int item) {
        node* temp = top;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == item) {
                cout << "Item was found" << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Item was not found" << endl;
        }
    }

    void isfull() {
        node* ptr = new node;
        if (ptr == nullptr) {
            cout << "Stack is full" << endl;
        }
        else {
            cout << "Not full" << endl;
            delete ptr;
        }
    }
};

int main() {
    stack s1;
   s1.push(12);
   s1.push(133);
   s1.push(122);
   s1.display();
   s1.counter();
}
