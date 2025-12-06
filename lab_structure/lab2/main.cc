#include <iostream>
#include "stack.h"
#include "queue.h"

int main()
{
    // /*
    Queue<int> q(4);
    q.enqueue(42);
    q.enqueue(54);
    q.enqueue(69);
    q.enqueue(70);
    // q.enqueue(8);
    std::cout << q.isEmpty() << std::endl;
    int n = q.size();
    for (int i = 0; i < n-2; i++) {
        std::cout << q.dequeue() << std::endl;
        q.printQueue();
    }
    q.enqueue(88);
    q.printQueue();
    q.enqueue(99);
    q.printQueue();
    q.enqueue(44);
    q.printQueue();
    // q.enqueue(62);
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    q.printQueue();
    // */
    /* 
    Stack<int> st(4, false);
    st.push(12);
    // std::cout << st.pop() << std::endl;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.printStack();
    std::cout << st.sizeOfStack() << std::endl;
    // st.push(7);
    std::cout << st.isEmpty() << std::endl;
    std::cout << st.top() << std::endl;

    std::int64_t n = st.sizeOfStack();
    for (int i = 0; i < n; i++) {
        std::cout << st.pop() << std::endl;
        st.printStack();
    }
    std::cout << st.isEmpty() << std::endl;
    std::cout << st.top() << std::endl;
    */
    
    // std::cout << q.dequeue() << std::endl;
    return 0;
}