#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) pop();
}

template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node{value, nullptr};
    if (rearNode) {
        rearNode->next = newNode;
    } else {
        frontNode = newNode;
    }
    rearNode = newNode;
    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) return;
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    count--;
    if (!frontNode) rearNode = nullptr;
}

template <typename T>
T Queue<T>::front() const {
    if (!empty()) return frontNode->data;
    throw runtime_error("Queue is empty");
}

template <typename T>
bool Queue<T>::empty() const {
    return frontNode == nullptr;
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (size() <= 1) return;
    T val = front();
    pop();
    push(val);
}

template <typename T>
void Queue<T>::display() const {
    Node* current = frontNode;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

#endif
