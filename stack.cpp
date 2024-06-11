#include <iostream>
using namespace std;

// Define Node class
class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

// Define Stack class
class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(int value) {
        Node* newnode = new Node(value);
        if (head != nullptr) {
            newnode->next = head;
        }
        head = newnode;
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Indicate that the stack is empty
        }
        Node* poppednode = head;
        head = head->next;
        int poppedValue = poppednode->value;
        delete poppednode;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            return -1; // Indicate that the stack is empty
        }
        return head->value;
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        Node* iternode = head;
        while (iternode != nullptr) {
            cout << iternode->value;
            iternode = iternode->next;
            if (iternode != nullptr) {
                cout << " ---> ";
            }
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.display();
    stack.pop();
    cout << "\n";
    stack.display();
    
    return 0;
}
