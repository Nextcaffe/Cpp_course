#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <cstdint>
#include <stdexcept>

template <typename Type>
class Stack {
private:
    DynamicArray<Type> data;
    std::int64_t capacity;

public:
    Stack() {
        capacity = 8;
        data = DynamicArray<Type>(capacity);
    }
    Stack(std::int64_t _capacity) {
        if (_capacity < 1) {
        throw std::invalid_argument("Capacity < 1"); 
        }   
        capacity = _capacity;
        data = DynamicArray<Type>(capacity);
    }

    ~Stack() = default;

    void printStack() {
        data.printData();
    }

    std::int64_t sizeOfStack() {
        return data.sizeOfArray();
    }

    bool isEmpty() {
        return sizeOfStack() == 0;
    }

    void push(Type x) {
        if (sizeOfStack() >= capacity) {
            throw std::overflow_error("Stack overflow");
        }
        data.push_back(x);
    }

    Type top() {
        if (isEmpty()) {
            throw std::invalid_argument("Stack is Empty");
        }
        return data.back();
    }

    Type pop() {
        if (isEmpty()) {
            throw std::invalid_argument("Stack is Empty");
        }
        Type tmp = top();
        data.remove(sizeOfStack()-1);
        return tmp;
    }

    Type operator[](std::int64_t idx) { //это убивает ВАЙБ стека, но я хочу принтить очередь
		if (isEmpty() || idx < 0 || idx >= sizeOfStack()) {
			throw std::invalid_argument("Out of range");
		}
		return data[idx];
		}

};


#endif //STACK_H
