#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstdlib>
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename Type>
class DynamicArray {
private:
	Type* data;
	std::int64_t size = 0; //я решил переопределить size как количество элементов а не индекс последнего, чтобы в дальнейшем меньше путаться
	std::int64_t capacity;

	bool isEmpty() {
		return size == 0;
	}

	bool notInArray (std::int64_t idx) {
		if (isEmpty() || idx < 0 || idx >= size) {
			return true;
		}
		return false;
	}

	void copyArray(std::int64_t newCapacity) {
		Type* tempArray = new Type[newCapacity];
		for (int i = 0; i < std::min(capacity, newCapacity); ++i) {
			tempArray[i] = data[i];
		}
		delete[] data;
		data = tempArray;
		capacity = newCapacity;

	}

public:

	DynamicArray() {
		capacity = 8;
		data = new Type[capacity];
	}

	DynamicArray(std::int64_t _capacity) {
		if (_capacity < 1) {
			throw std::invalid_argument("Capacity < 1");
		}
		capacity = _capacity;
		data = new Type[capacity];
	}

	DynamicArray(DynamicArray& other) {
		size = other.size;
		capacity = other.capacity;
		data = new Type[capacity];

		for (int i = 0; i < size; ++i) {
			this->data[i] = other.data[i];
		}
	}

	DynamicArray& operator =(const DynamicArray& other) { //оператор равно чтобы работал в стеке (иначе будет два указателя на одно место в памяти)
		if (this == &other)
			return *this;
		if (data) {
			delete[] data;
		}
		size = other.size;
		capacity = other.capacity;
		data = new Type[capacity];

		for (int i = 0; i < size; ++i) {
			this->data[i] = other.data[i];
		}
		return *this;
	}

	~DynamicArray()  {
		if (data) {
			delete[] data;
		}
	}

	std::int64_t sizeOfArray() {
		return size;
	}

	void push_back(Type val) {
		if (size >= capacity) {
			std::int64_t newCapacity = capacity * 2;
			Type* tempArray = new Type[newCapacity];
			for (int i = 0; i < capacity; ++i) {
				tempArray[i] = data[i];
			}
			delete[] data;
			data = tempArray;
			capacity = newCapacity;
		}
		data[size++] = val;
	}

	Type add(std::int64_t idx1, std::int64_t idx2) {
		if (idx1 >= size || idx2 >= size || idx1 < 0 || idx2 < 0) {
			throw std::invalid_argument("idx1 or idx2 out of range");
		}
		return data[idx1] + data[idx2];
	}

	Type max() {
		if (isEmpty()) {
			throw std::invalid_argument("Empty array");
		}
		float currentMax = -1e+38;
		for (int i = 0; i < size; ++i) {
			if (data[i] >= currentMax) {
			currentMax = data[i];
			}
		}
		return currentMax;
	}

	Type min() {
		if (isEmpty()) {
			throw std::invalid_argument("Empty array");
		}
		float currentMin = 1e+38;
		for (int i = 0; i < size; ++i) {
			if (data[i] <= currentMin) {
			currentMin = data[i];
			}
		}
		return currentMin;
	}

	void clear() {
		if (this->data) {
			delete[] this->data;
			this->data = nullptr;
		}
		size = 0;
		capacity = 8;
	}

	void reinitialize() {
		clear();
		data = new float[capacity]();
		}

	void printData() {
		if (isEmpty()) {
			return;
		}
		for (int i = 0; i < size; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	Type operator[](std::int64_t idx) {
		if (isEmpty() || idx < 0 || idx >= size) {
			throw std::invalid_argument("Out of range");
		}
		return data[idx];
		}

	Type operator()() {
		if (isEmpty()) {
			return 0;
		}
		float sum = 0;
		for (int i = 0; i < size; ++i) {
			sum += data[i];
		}
		return sum;
	}

	void increase_capacity(std::int64_t newCapacity) {
		if (newCapacity <= capacity || newCapacity <= 0) {
			throw std::invalid_argument("Wrong capacity");
		}
		copyArray(newCapacity);
	}

	void decrease_capacity(std::int64_t newCapacity) {
		if (newCapacity >= capacity || newCapacity <= 0) {
			throw std::invalid_argument("Wrong capacity");
		}
		copyArray(newCapacity);
		if (newCapacity <= size) {
			size = newCapacity;
		}
	}

	Type front() {
		if (isEmpty()) {
			throw std::invalid_argument("Empty Array");
		}
		return data[0];
	}

	Type back() {
		if (isEmpty()) {
			throw std::invalid_argument("Empty Array");
		}
		return data[size-1];
	}

	void remove(std::int64_t idx) {
		if (notInArray(idx)) {
			throw std::invalid_argument("Out of range");
		}
		for (int i = idx; i < size-1; ++i) {
			data[i] = data[i+1];
		}

		erase_after(size-2);

	}

	void erase_after(std::int64_t idx) { // при idx = -1 будем удалять все элементы начиная с нулевого
		if (idx != -1 && notInArray(idx)) {
			throw std::invalid_argument("Out of range");
		}
		size = idx+1;
		if (capacity > 8 && size <= capacity/2) {
			int64_t newCapacity = capacity/2;
			copyArray(newCapacity);
		}
	}

	void insert(std::int64_t idx, Type val) {
		if (notInArray(idx)) {
			throw std::invalid_argument("Out of range");
		}
		if (size >= capacity) {
			int64_t newCapacity = capacity*2;
			copyArray(newCapacity);
		}
		for (int i = size-1; i >= idx; --i) {
			data[i+1] = data[i];
		}
		data[idx] = val;
		size++;
	}

	void push_front(Type val) {
		insert(0, val);
	}

};

#endif // DYNAMICARRAY_H
