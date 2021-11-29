#include <iostream>

const int queueMaxlength = 10;

class Queue {
    private:
        int queue[queueMaxlength];
        int length;

    public:
        Queue() {
            length = 0;
        }

        void enqueue(int data);
        void dequeue();
        int front();
        bool isEmpty();
        int lengthOf();
};

void Queue::enqueue(int data) {
    if (length >= queueMaxlength) return;
    
    queue[length] = data;
    length++;
}

void Queue::dequeue() {
    if (length == 0) return;

    for (int i = 0; i < length; i++) {
        queue[i] = queue[i + 1];
    }
    length--;
}

int Queue::front() {
    if (length == 0) return -1;
    return queue[0];
}

bool Queue::isEmpty() {
    return length;
}

int Queue::lengthOf() {
    return length;
}

int main() {
    Queue queueOne;
    queueOne.dequeue();
    queueOne.enqueue(1);
    queueOne.enqueue(2);
    queueOne.enqueue(3);
    std::cout << queueOne.front() << ": front" << std::endl;
    queueOne.dequeue();
    std::cout << queueOne.front() << ": front" << std::endl;


    return 0;
}