#include <iostream>

class Node {
private:
    char value;
    Node* next;

public:
    Node(char val) {
        value = val;
        next = nullptr;
    }

    void setNext(Node* nextNode) {
        next = nextNode;
    }

    Node* getNext() {
        return next;
    }

    char getValue() {
        return value;
    }
};

class Queue {
private:
    Node* first;
    Node* last;

public:
    Queue() {
        first = nullptr;
        last = nullptr;
    }

    bool isEmpty() {
        return first == nullptr;
    }

    void enqueue(char val) {
        Node* newNode = new Node(val);
        
        if (isEmpty()) {
            first = newNode;
            last = newNode;
        } else {
            last->setNext(newNode);
            last = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue kosong!\n";
            return;
        }
        
        Node* temp = first;
        first = first->getNext();
        
        if (first == nullptr) {
            last = nullptr;
        }
        
        delete temp;
    }

    char front() {
        if (isEmpty()) {
            std::cout << "Queue kosong!\n";
            return '\0';
        }
        return first->getValue();
    }
};

int main() {
    Queue q;

    q.enqueue('A');
    q.enqueue('M');
    q.enqueue('P');

    std::cout << "Elemen depan: " << q.front() << "\n";

    q.dequeue();
    std::cout << "Elemen depan setelah dequeue: " << q.front() << "\n";

    return 0;
}