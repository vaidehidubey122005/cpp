#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            return;
        }
        Node* currentNode = this->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        // If head node itself holds the key
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Find the node to be deleted
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }

        // If key was not present
        if (current == NULL) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = current->next;
        delete current;
    }

    void printList() {
        Node* currentNode = this->head;
        while (currentNode != NULL) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.printList();
    return 0;
}