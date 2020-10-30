#pragma once
#include <iostream>

const int max_length = 1e4;
// հերթի իրականացում առանց size
template<class T>
class queue {
    int front, rear;
    T a[max_length];

public:
    queue();
    queue(const queue<T>& a);
    ~queue();
    bool empty() const;
    void insert(T g);
    void Delete();
    T getFirst() const;
    void clearQueue();
    void print();
};

template<class T>
queue<T>::queue() {
    front = 1;
    rear = 1;
}

template<class T>
queue<T>::queue(const queue<T>& a) {
    front = 1;
    rear = 1;
    int i = a.front;
    while(i!=a.rear) {
        insert(a.a[i]);
        i = (i + 1) % max_length;
    }
}

template<class T>
queue<T>::~queue() {
    front = 1;
    rear = 1;
}

template<class T>
bool queue<T>::empty() const {
    if(rear == front)
        return true;
    return false;
}

template<class T>
void queue<T>::insert(T g) {
    if(rear == front - 1) {
        throw "Overflow!";
    }
    else {
        a[rear] = g;
        rear = (rear + 1) % max_length;
    }
}

template<class T>
void queue<T>::Delete() {
    if(empty()) {
        throw "Underflow!";
    }
    else {
        front = (front + 1) % max_length;
    }
}

template<class T>
T queue<T>::getFirst() const{
    return a[front];
}

template<class T>
void queue<T>::clearQueue() {
    front = 1;
    rear = 1;
}

template<class T>
void queue<T>::print() {
    int i=front;
    while(i<rear) {
        std::cout<<a[i]<<" ";
        i = (i + 1) % max_length;
    }
    std::cout<<std::endl;
}