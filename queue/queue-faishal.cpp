#include <iostream>

const int MAX = 10;

class Queue {
private:
    int depan;
    int belakang;
    int antrian[MAX];

public:
    Queue() {
        depan = 0;
        belakang = 0;
    }

    bool isEmpty() const {
        return depan == belakang;
    }

    bool isFull() const {
        return (belakang + 1) % MAX == depan;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Antrian penuh!\n";
            return;
        }
        antrian[belakang] = value;
        belakang = (belakang + 1) % MAX;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Antrian kosong\n";
            return -1;
        }
        int value = antrian[depan];
        depan = (depan + 1) % MAX;
        return value;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Antrian kosong\n";
            return; // Kurung kurawal ditutup di sini
        }

        int i = depan;
        while (i != belakang) {
            std::cout << antrian[i] << " ";
            i = (i + 1) % MAX;
        }
        std::cout << "\n";
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();

    q.dequeue();
    q.print();

    return 0;
}