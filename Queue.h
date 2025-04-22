#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue();
    ~Queue();

    void push(const T& value);
    void pop();
    T front() const;
    bool empty() const;
    int size() const;
    void move_to_rear();
    void display() const;
};

// include the implementatio
#include "Queue.cpp"

#endif


