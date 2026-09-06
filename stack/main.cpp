#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack
{
private:
    Node* topNode;

public:
    Stack()
    {
        topNode = nullptr;
    }

    void push(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop()
    {
        if (topNode == nullptr)
        {
            cout << "Stack kosong!";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top()
    {
        if (topNode != nullptr)
        {
            return topNode->data;
        }
        return -1;
    }

    ~Stack()
    {
        while (topNode != nullptr)
        {
            pop();
        }
    }
};

int main()
{
    Stack stack;
    stack.push(505);
    stack.push(2112);
    stack.push(6926);
    cout << "Top Stack: " << stack.top() << endl;
    stack.pop();
    cout << "Top Stack after pop: " << stack.top() << endl;
    return 0;
}
