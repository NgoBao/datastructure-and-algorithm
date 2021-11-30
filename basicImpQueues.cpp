#include <iostream>

const int queueMaxlength = 10;

class Queue {
    private:
        int queue[queueMaxlength];
        int front;
        int rear;

    public:
        Queue() {
            front = -1;
            rear = -1;
        }

        void enqueue(int data);
        void dequeue();
        bool isEmpty();
        int lengthOf();
        void traver();
};

void Queue::enqueue(int data) {
    if (front == -1) front = 0;
    if (rear + 1 >= queueMaxlength) return;
    rear++;
    queue[rear] = data;
}

void Queue::dequeue() {
    if (this->isEmpty()) return;

    for (int i = front; i <= rear; i++) {
        queue[i] = queue[i + 1];
    }
    front++;
}

bool Queue::isEmpty() {
    if (rear == -1 && front == -1) return true;
    return front > rear;
}

int Queue::lengthOf() {
    if (rear == -1 && front == -1) return 0;
    return rear - front + 1;
}

void Queue::traver() {
    if (rear == -1 && front == -1) return;

    for (int i = front; i <= rear; i++) {
        std::cout << queue[i] << " ";
    }
}

int main() {
    Queue queueOne;
    std::cout << queueOne.isEmpty() << std::endl;

    queueOne.dequeue();
    queueOne.enqueue(1);
    std::cout << queueOne.isEmpty() << std::endl;
    queueOne.enqueue(2);
    std::cout << queueOne.isEmpty() << std::endl;
    queueOne.dequeue();
    queueOne.dequeue();
    std::cout << queueOne.isEmpty() << std::endl;
    queueOne.enqueue(3);

    queueOne.traver();
    std::cout << queueOne.lengthOf() << std::endl;
    return 0;
}