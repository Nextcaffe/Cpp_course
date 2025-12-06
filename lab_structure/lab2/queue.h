#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <stdexcept>
#include <cstdint>

template <typename Type>
class Queue {
private:
    Stack<Type> left;
    Stack<Type> right;
    std::int64_t capacity;

public:
    Queue() {
        capacity = 8;
        left = Stack<Type>(capacity);
        right = Stack<Type>(capacity);
    }
    Queue(std::int64_t _capacity) {
        if (_capacity < 1) {
        throw std::invalid_argument("Capacity < 1"); 
        }   
        capacity = _capacity;
        left = Stack<Type>(capacity);
        right = Stack<Type>(capacity);
    }

    ~Queue() = default;

    std::int64_t size() { 
        return left.sizeOfStack() + right.sizeOfStack();
    }

    bool isEmpty() {
        return left.isEmpty() and right.isEmpty();
    }

    void printQueue() { // красивенький вывод очереди, начало в конце, конец в начале
        if (isEmpty()) {
			return;
		}
        Stack<Type> tmpData(capacity);
        for (int i = 0; i < left.sizeOfStack(); ++i) {
            tmpData.push(left[left.sizeOfStack() - (i+1)]);
        }
        for (int i = left.sizeOfStack(); i < left.sizeOfStack() + right.sizeOfStack(); ++i) {
            tmpData.push(right[i - left.sizeOfStack()]);
        }
        tmpData.printStack();
    }

    void enqueue(Type x) {
        if (size() >= capacity) {
            throw std::overflow_error("Queue overflow");
        }
        left.push(x);
    }

    Type dequeue() {
        if (isEmpty()) {
            throw std::invalid_argument("Queue is Empty");
        }
        if (!right.isEmpty()) {
            return right.pop();
        }
        std::int64_t left_Stack_size = left.sizeOfStack();
        for (int i = 0; i < left_Stack_size; ++i) {
            right.push(left.pop());
        }
        return right.pop();
    }

};

#endif //QUEUE_H
