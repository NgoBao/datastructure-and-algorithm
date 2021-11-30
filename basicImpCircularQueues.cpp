#include <iostream>

int const queueMaxlength = 10;

class CircularQueue {
    private: 
        int queue[queueMaxlength];
        int rear;
        int front;
        int currentLength;
    
    public:
        CircularQueue() {
            front = -1;
            rear = -1;
            currentLength = 0;
        }

        void enqueue(int data);
        void dequeue();
        bool isEmpty();
        bool isFull();
        int lengthOf();
        void traver();
};

bool CircularQueue::isEmpty() {
    return currentLength == 0;
}

bool CircularQueue::isFull() {
    return currentLength == queueMaxlength;
}

void CircularQueue::enqueue(int data) {
    if (this -> isFull()) return;
    
    if (front == -1 && rear == -1) {
        front++;
        rear++;
        queue[rear] = data;
        currentLength++;
        std::cout << front << ":" << rear;
        return;
    }

    if (front != 0 && rear == queueMaxlength - 1) {
        rear = -1;
    }

    rear++;
    std::cout << front << ":" << rear;
    queue[rear] = data;
    currentLength++;
}

void CircularQueue::dequeue() {
    if (this -> isEmpty()) return;

    if (front == queueMaxlength - 1) {
        front = 0;
    } else if (front > rear && front != 0) {
        front = -1;
        rear = -1;
        currentLength = 0;
    }
    front++;
    currentLength--;
}

int CircularQueue::lengthOf() {
    return currentLength;
}

void CircularQueue::traver() {
    if (this -> isEmpty()) return;
    
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            std::cout << queue[i] << " ";
        }
        return;
    }

    for (int i = front; i < queueMaxlength; i++) {
        std::cout << queue[i] << " ";
    }

    for (int i = 0; i <= rear; i++) {
        std::cout << queue[i] << " ";
    }
}

int main() {
    CircularQueue queueOne;

    queueOne.dequeue();
    queueOne.enqueue(1);
    queueOne.enqueue(2);
    queueOne.enqueue(1);
    queueOne.enqueue(2);
    queueOne.enqueue(1);
    queueOne.enqueue(2);
    std::cout << queueOne.lengthOf() << std::endl;
    queueOne.dequeue();
    queueOne.dequeue();
    std::cout << queueOne.lengthOf() << std::endl;
    queueOne.enqueue(1);
    queueOne.enqueue(2);
    queueOne.enqueue(1);
    queueOne.enqueue(2);
    queueOne.enqueue(1);
    queueOne.enqueue(2); 
    queueOne.enqueue(1);
    queueOne.enqueue(3);
    std::cout << "--------------"  << std::endl;  
    queueOne.traver();

    return 0;
}