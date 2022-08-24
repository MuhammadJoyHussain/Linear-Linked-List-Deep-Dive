#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    // Constructor Creation
    Node(int val) {
    value = val;
    Next = NULL;
    }
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *n);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node* &head, int pos, int val);

void insertAtTail(Node *&head, int val) {
    Node * newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val) {
    // s1: newNode creation
    Node * newNode = new Node(val);
    // s2: Update of newNode->Next
    newNode->Next = head;
    // s3: Update of head
    head = newNode;
}

void display(Node * n) {
    // To Reverse Linked List
//    if (n == NULL)
//        return;

    while(n!=NULL){
        cout<< n->value;
        if(n->Next != NULL) cout<< " -> ";

        n=n->Next;
    }
    cout<<endl<<endl;
}

int countLength(Node *&head) {
    int count = 0;
    Node* temp = head;
    while(temp!=NULL) {
        count++;
        temp=temp->Next;
    }
    return count;
}

void insertionAtSpecificPosition(Node *&head, int pos, int val) {
    int i=0;
    Node* temp = head;

    while(i<pos-2) {
        temp=temp->Next; // 2 3
        i++; // 1 2
    }

    Node *newNode = new Node(val);
    newNode->Next=temp->Next;
    temp->Next = newNode;
}

int main() {
    Node* head = NULL;

    int value, position;
    // Choice 1: Insertion at Head
    // Choice 2: Insertion at tail
    cout<<
    "Choice 1: Insertion at Head" << endl <<
    "Choice 2: Insertion at Tail"<<endl <<
    "Choice 3: Insertion at Specific Position" << endl<<
    "choice 0: Exit"<<endl<<endl;

    int choice;
    cout<< "Next Choice : ";
    cin >> choice;

    while(choice != 0) {

        switch (choice) {
        case 1:
            cout << "Enter the Value : ";
            cin>>value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the Value : ";
            cin>>value;
            insertAtTail(head, value);
            break;
        case 3:
            cout<< "Enter the Desired Position : ";
            cin>> position;
            cout<< "Enter the Value : ";
            cin>>value;
            insertionAtSpecificPosition(head, position, value);
            break;
        default:
            break;
        }

        cout<< "Next Choice : ";
        cin>>choice;
    }

    cout<< " Linked List : ";
    display(head);
    cout<< "Length of the List : " << countLength(head)<<endl;

    return 0;
}
