// NAME: Zoha Areej
// CMS ID: 455753
// DSA ASSIGNMENT 1
// Q1

#include <iostream>
using namespace std;

// Creating a Node class
class Node {
public:
    int value;
    Node* prev;
    Node* next;

    // Constructor for Node
    Node(int data) {
        value = data;
        prev = NULL;
        next = NULL;
    }
};

// Class for Doubly Linked List
class DoublyLL {
public:
    Node* head;
    Node* tail;

    // Constructor of DLL
    DoublyLL() {
        head = NULL;
        tail = NULL;
    }
    // Destructor of DLL
    ~DoublyLL() {
           Node* temp = head;
           while (temp != NULL) {
               Node* nextNode = temp->next;
               delete temp;
               temp = nextNode;
           }
           cout << "List destroyed and memory freed." << endl;
       }

    // Insert value at the start of the DLL
    void insertAtStart(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {  // If list is empty
            head  = new_node;
            tail =new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    // Insert value at the end of the DLL
    void insertAtEnd(int value) {
        Node* new_node = new Node(value);
        if (tail == NULL) {  // If list is empty
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    // Insert a new value after a specific node
    void insertAfterSpecificNode(int prevValue, int newValue) {
        Node* temp = head;
        while (temp != NULL && temp->value != prevValue) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node is not found." << endl;
            return;
        }

        Node* new_node = new Node(newValue);
        new_node->next = temp->next;
        new_node->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = new_node;
        } else {
            tail = new_node;
        }
        temp->next = new_node;
    }
    //Delete specific value
    void deleteSpecificValue(int value) {
        // Search for the node to delete
        Node* temp = head;
        while (temp != NULL && temp->value != value) {
            temp = temp->next;
        }
        if (temp == NULL) {  // If the node is not found
            cout << value << " not found in the list." << endl;
            return;
        }
        if (temp == head) {     // Deleting the head node
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
        }
        else if (temp == tail) {   // Deleting the tail node
            tail = tail->prev;
            tail->next = NULL;
        }
        else {         // Deleting a node in the middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << value << " is deleted from the DoublyLinkedList." << endl;
    }

    // Forward traversal of the DLL
    void forwardTraversal() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Reverse traversal of the DLL
    void reverseTraversal() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->value << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    
    // Search for a value in the DLL
    bool search(int val) {
        Node* temp = head;
        
        while (temp != NULL) {
            if (temp->value == val) {
                cout << temp->value << " exists." << endl;
                return true;
            }
            temp = temp->next;
        }
        
        cout << val << " does not exists." << endl;
        return false;
    }
    
    //reversing the DLL
    void reverseList() {
        Node* temp = NULL;
        Node* currPtr = head;

        while (currPtr != NULL) {
            temp = currPtr->prev;
            currPtr->prev = currPtr->next;
            currPtr->next = temp;
            currPtr = currPtr->prev;
        }

        if (temp != NULL) {
            head = temp->prev;
        }
    }

    // Display the DLL
    void displayList(){
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLL dll;

    cout << "Insertion at start:" << endl;
    dll.insertAtStart(3);
    dll.insertAtStart(5);
    dll.insertAtStart(7);
    dll.displayList();

    cout << "Insertion at end:" << endl;
    dll.insertAtEnd(9);
    dll.insertAtEnd(1);
    dll.displayList();

    cout << "Inserting 4 after 3:" << endl;
    dll.insertAfterSpecificNode(3, 4);
    dll.displayList();

    cout << "Forward Traversal: ";
    dll.forwardTraversal();

    cout << "Reverse Traversal: ";
    dll.reverseTraversal();
     
    cout<< "Searching Node: "<<endl;
    dll.search(9);
    cout<< "Searching Node: "<<endl;
    dll.search(2);
    
    cout<<"Reversed List: ";
    dll.reverseList();
    dll.displayList();
    
    cout<<"Delete specific value: ";
    dll.deleteSpecificValue(5);
    dll.displayList();

    return 0;
}
