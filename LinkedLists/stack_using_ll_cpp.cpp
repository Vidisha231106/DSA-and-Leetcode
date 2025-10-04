#include <iostream>
using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
private:
    StackNode* top;
    int size;

public:
    // Constructor
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Destructor (to avoid memory leaks)
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int x) {
        StackNode* element = new StackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed" << endl;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        int topData = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void printStack() {
        StackNode* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Element popped: " << s.pop() << endl;
    cout << "Stack size: " << s.getSize() << endl;
    cout << "Stack empty or not? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Stack's top element: " << s.peek() << endl;

    cout << "Printing stack elements: ";
    s.printStack();

    return 0;
}
