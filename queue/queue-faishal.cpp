#include <iostream>

// Struct pointer buat node
struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Variabel global 
Node* first = nullptr;
Node* last = nullptr;

bool isEmpty() {
    return first == nullptr;
}

void pushFront(char val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = first;
    newNode->prev = nullptr;

    if (isEmpty()) {
        first = newNode;
        last = newNode;
    } else {
        first->prev = newNode;
        first = newNode;
    }
}

void pushBack(char val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = last;

    if (isEmpty()) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

void popFront() {
    if (isEmpty()) {
        std::cout << "Deque kosong!\n";
        return;
    }
    Node* temp = first;
    first = first->next;

    if (first == nullptr) {
        last = nullptr;
    } else {
        first->prev = nullptr;
    }
    delete temp;
}

void popBack() {
    if (isEmpty()) {
        std::cout << "Deque kosong!\n";
        return;
    }
    Node* temp = last;
    last = last->prev;

    if (last == nullptr) {
        first = nullptr;
    } else {
        last->next = nullptr;
    }
    delete temp;
}

int main() {
    pushBack('B');
    pushBack('C');
    pushFront('A'); // Deque: A <-> B <-> C

    std::cout << "Depan: " << first->data << "\n";  // A
    std::cout << "Belakang: " << last->data << "\n"; // C

    popBack(); // Hapus 'C'
    std::cout << "Belakang setelah popBack: " << last->data << "\n"; // B

    popFront(); // Hapus 'A'
    std::cout << "Depan setelah popFront: " << first->data << "\n";   // B

    return 0;
}