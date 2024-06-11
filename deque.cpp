#include <iostream>
using namespace std;

// Define Node class
class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Define Deque class
class Deque {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Deque() {
        head = tail = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void add_head(int value) {
        Node* node = new Node(value);
        if (isEmpty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }

    void add_tail(int value) {
        Node* node = new Node(value);
        if (isEmpty()) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void remove_head() {
        if (isEmpty()) {
            return;
        } else {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            } else {
                head->prev = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void remove_tail() {
        if (isEmpty()) {
            return;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            if (tail == nullptr) {
                head = nullptr;
            } else {
                tail->next = nullptr;
            }
            delete temp;
            size--;
        }
    }

    int peek_head() {
        if (isEmpty()) {
            return -1; // Indicate that the deque is empty
        }
        return head->value;
    }

    int peek_tail() {
        if (isEmpty()) {
            return -1; // Indicate that the deque is empty
        }
        return tail->value;
    }
};

int main() {
    Deque deque;
    deque.add_head(5);
    // cout << deque.peek_head() << endl;
    deque.add_head(6);
    // cout << deque.peek_head() << endl;
    deque.add_head(7);
    // cout << deque.peek_head() << endl;
    deque.add_tail(8);
    // cout << deque.peek_tail() << endl;
    cout << deque.peek_head() << endl;
    deque.remove_head();
    cout << deque.peek_head() << endl;

    return 0;
}
