#include <iostream>
#include <iomanip>
using namespace std;
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next = NULL;
        Node* prev = NULL;
    };
    Node* first = NULL;
    Node* last = NULL;
    int count = 0;

public:
    bool isempty() {
        if (first == NULL) {
            return true;
        }
        else return false;
    }

    void insertfirst(int value) {
        Node* newnode = new Node;
        newnode->data = value;
        if (isempty()) {
            first = last = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else {
            newnode->next = first;
            newnode->prev = NULL;
            first->prev = newnode;
            first = newnode;
        }
        count++;
    }

    void insertend(int value) {

        if (isempty()) {
            insertfirst(value);
        }

            /*else if(count==1){
                Node* newnode=new Node;
                newnode->data=value;
                first->next=newnode;
                newnode->prev=first;
                newnode->next=NULL;
                last=newnode;

            }*/

        else {
            Node* newnode = new Node;
            newnode->data = value;
            newnode->next = NULL;
            newnode->prev = last;
            last->next = newnode;
            last = newnode;
        }
    }

    void counter() {
        int count = 0;
        if (first == NULL) {
            cout << 0 << endl;
        }
        else {
            Node* temp = first;
            while (temp != NULL) {
                count++;
                temp = temp->next;
            }

            cout << count << endl;
        }
    }

    void InsertAt(int position, int value) {
        if (position < 0 || position > count) {
            cout << "Invalid Position" << endl;
        }
        else {
            Node* newnode = new Node;
            newnode->data = value;
            if (position == 0) {
                insertfirst(value);
            }

            else if (position == count) {
                insertend(value);
            }
            else {
                Node* ptr = first;
                for (int i = 1; i < position; i++) {
                    ptr = ptr->next;
                }
                newnode->next = ptr->next;
                newnode->prev = ptr;

                ptr->next = newnode;
                ptr->next->prev = newnode;

            }
            count++;
        }

    }

    void RemFirst() {
        if (isempty()) {
            cout << "No Elements to Remove";
        }
        else if (count == 1) {
            first = NULL;
            last = NULL;
            delete first;
            count--;
        }
        else {
            Node* ptr = first;
            first = first->next;

            delete ptr;
            count--;
        }
    }
    void RemAt(int item) {
        if (isempty()) cout << "No Elements to Remove";

        if (first->data == item) {
            RemFirst();
        }

        else {
            Node* ptr = first->next;

            while (ptr != NULL && ptr->data != item) {
                ptr = ptr->next;
            }

            if (ptr == NULL) cout << "No Items With Given Value";

            else if (ptr->next == NULL) {
                RemLast();
            }
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;
                count--;
            }


        }
    }

    void RemLast() {
        if (isempty()) {
            cout << "No Elements to Remove";
        }

        else {
            Node* ptr = new Node;
            ptr = last;
            last = last->prev;
            last->next = NULL;
            delete ptr;
        }

    }





    void traverse() {
        if (isempty()) {
            cout << "No Elements In The List" << endl;
        }
        else {
            Node* temp = first;
            while (temp != NULL) {
                cout << temp->data << " ";

                temp = temp->next;
            }
        }}




    void all() {
        int Choice;
        cout << endl;
        cout << setw(94) << " ---------------------------------------------" << endl;
        cout << setw(95) << "|              What Do You Want?              |" << endl;
        cout << setw(94) << " ---------------------------------------------" << endl;
        cout << setw(65) << " _______________________________ " << " _______________________________ " << " _______________________________ " << endl;
        cout << setw(65) << "|         1-Insert First        |" << "|         4-Delete First        |" << "|        7-Count Elements       |" << endl;
        cout << setw(65) << "|-------------------------------|" << "|-------------------------------|" << "|-------------------------------|" << endl;
        cout << setw(65) << "|      2-Insert at Position     |" << "|    5-Delete Certain Element   |" << "|       8-Display Elements      |" << endl;
        cout << setw(65) << "|-------------------------------|" << "|-------------------------------|" << "|-------------------------------|" << endl;
        cout << setw(65) << "|         3-Insert Last         |" << "|         6-Delete Last         |" << "|  9-Check If the List is Empty |" << endl;
        cout << setw(65) << "|_______________________________|" << "|_______________________________|" << "|_______________________________|" << endl;
        cout << setw(98) << " _______________________________ " << endl;
        cout << setw(98) << " |             0-exit            |" << endl;
        cout << setw(98) << "|_______________________________|" << endl;





        cin >> Choice;
        switch (Choice) {
            case 0:
                exit(0);
                break;
            case 1:
                int v;
                cout << "Please Enter The Value You Want To Insert First:";
                cin >> v;
                insertfirst(v);
                break;
            case 2:
                int it;
                int value;
                cout << "Please Enter The Position You Want To Insert At:";
                cin >> it;
                cout << "Number Is:";
                cin >> value;
                InsertAt(it, value);
                break;

            case 3:
                int f;
                cout << "Please Enter The Value You Want To Insert Last:";
                cin >> f;
                insertend(f);
                break;

            case 4:
                RemFirst();
                break;

            case 5:
                int I;
                cout << "Please Enter The Item You Want to Remove:";
                cin >> I;
                RemAt(I);
                break;

            case 6:
                RemLast();
                break;

            case 7:
                cout << "Number of Elements in the List is: ";
                counter();
                break;

            case 8:
                cout << "Elements in the List Are: ";
                traverse();
                break;

            case 9:
                cout << isempty() << endl;
                break;

        }
    }
};


int main() {

    DoublyLinkedList ls;
    while (1) {
        ls.all();
    }
}
