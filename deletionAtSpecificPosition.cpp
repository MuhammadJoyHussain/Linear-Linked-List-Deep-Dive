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

struct Test {
    int position[1000];
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *n);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node* &head, int pos, int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void searchByValueUnique(Node *&head, int searchByValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head, int position);


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

int searchByValueUnique(Node* &head, int key) {
    Node* temp = head;
    int count = 1;

    if(temp == NULL){
        return -1;
    }

    while(temp->value != key){
        if(temp->Next == NULL){
                return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key) {
    Node* temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k=1;
    int count = 1;
    int flag = 0;

    while(temp!=NULL){
        if(temp->value==key) {
//          cout << count << " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    cout<<endl;
    if (flag == 0) cout<< "The searched Value is not yet in the List" << endl;
    else {
        position[0] = k;
        cout << "The value is found at Position : ";
        for (int i=1; i<position[0]; i++) {
            cout<< position[i];
            if(i<position[0]-1) cout<< ",";
            }
            cout<< endl;
        }
}

Test searchByValueDuplicateReturn(Node *&head, int key) {
    Node* temp = head;
    Test T;
    int k=1;
    int count = 1;

    while(temp!=NULL){
        if(temp->value==key) {
//          cout << count << " ";
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }

    T.position[0]=k;
    return T;
}

void searchByValueUnique(Node *&head, int searchValue, int value) {
    //Step 1: Search the Position of the Search Value
    int position;
    position = searchByValueUnique(head, searchValue);

    //Step 2: Insert the value at the Position+1
    insertionAtSpecificPosition(head, position+1, value);
}

void deletionAtHead(Node* &head) {
    Node* temp = head;
    if(temp!=NULL) {
        head = temp->Next;
        delete temp;
    } else {
        cout<< "There is No Value in the Linked List" << endl;
    }
}

void deletionAtTail(Node* &head) {
    Node* temp = head;
    if(temp!=NULL && temp->Next != NULL) {
    while(temp->Next->Next != NULL) {
        temp=temp->Next;
    }
    Node *delNode = temp->Next;
    temp->Next=NULL;
    delete delNode;
    } else {
        //Head is Null
        if(temp == NULL)
            cout<< "There is No Value in the Linked List" << endl;

        // Head is Tail
         else
            deletionAtHead(head);
    }

}

void deletionAtSpecificPosition(Node* &head, int position) {
    Node* temp = head;

    if(position<=countLength(head)) {

        if(position == 1){
            deletionAtHead(head);
        } else if (position == countLength(head)){
            deletionAtTail(head);
        }

        int i=1;
        while(i<position-1) {
            temp=temp->Next;
            i++;
        }

        Node* delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
    } else {
        // Position is Our of Range
//        if(position>countLength(head)) {
            cout<< "Position Out of Bound"<<endl;
//        }
//        //LL is NULL
//        else
//            cout<< "There is No Value in the Linked List"<< endl;
//    }
}
}

int main() {
    Node* head = NULL;

    int value, position;
    // Choice 1: Insertion at Head
    // Choice 2: Insertion at tail
    // Choice 3: Insertion a Certain Position
    cout<<
    "Choice 1: Insertion at Head" << endl <<
    "Choice 2: Insertion at Tail"<<endl <<
    "Choice 3: Insertion at Specific Position" << endl<<
    "Choice 4: Search a Value (Unique List)" << endl<<
    "Choice 5: Search a Value (Duplication Enabled List)" << endl<<
    "Choice 6: Insertion after a Specific Value" << endl<<
    "Choice 7: Deletion at Head" << endl<<
    "Choice 8: Deletion at Tail" << endl<<
    "Choice 9: Deletion at a Specific Position" << endl<<
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
        case 4:
            cout<< "Enter the Value to Search : ";
            cin>>value;
            position = searchByValueUnique(head, value);
            if(position!=-1) {
                cout<<"The number is at Position : " <<position<<endl;
            } else {
                cout<<"The number is not yet in the List" <<endl;
            }
            break;
        case 5:
            cout<< "Enter the Value to Search : ";
            cin>>value;
//            searchByValueDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if(T.position[0] == 1) {
                cout<< "The searched Value is not yet in the List" << endl;
            } else {
                int size = T.position[0];
                cout << "The value is found at Position : ";
                for (int i=1; i<size; i++) {
                    cout<<T.position[i];
                    if(i<size-1) cout<< ", ";
                }
                cout<<endl;
            }
            break;
        case 6:
            cout<< "Enter the value to search : ";
            int searchValue;
            cin>>searchValue;
            cout<< "Enter the value to insert : ";
            cin>>value;
            searchByValueUnique(head, searchValue, value);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            if(head==NULL) {
                cout<< "There is No Value in the Linked List"<< endl;
                break;
            }
            cout<< "Enter the Desired Position : ";
            cin>> position;
            deletionAtSpecificPosition(head, position);
            cout<<endl;
            display(head);
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


