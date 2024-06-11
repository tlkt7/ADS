#include <iostream>
using namespace std;

// Define Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Define Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int item) {
        Node* temp = new Node(item);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek_front() {
        if (isEmpty()) {
            return -1; // Indicate that the queue is empty
        }
        return front->data;
    }

    int peek_back() {
        if (isEmpty()) {
            return -1; // Indicate that the queue is empty
        }
        return rear->data;
    }
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout << queue.peek_back() << endl;

    return 0;
}
