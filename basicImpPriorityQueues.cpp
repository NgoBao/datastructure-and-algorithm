#include <iostream>

struct Element {
    int data;
    int priority;
    Element * next;
};

class PriorityQueue {
    private: 
        Element * start;
        int length;

    public: 
        PriorityQueue() {
            start = NULL;
            length = 0;
        }


        void enqueue(int data, int priority);
        void dequeue();
        int lengthOf();
        bool isEmpty();
        void traver();
};

bool PriorityQueue::isEmpty() {
    return length == 0;
}

int PriorityQueue::lengthOf() {
    return length;
}

void PriorityQueue::enqueue(int data, int priority) {
    Element * newElement = (Element *) malloc(sizeof(Element));
    newElement -> data = data;
    newElement -> priority = priority;

    if (start == NULL || start -> priority > priority) {
        newElement -> next = start;
        start = newElement;
        length++;
        return;
    }


    Element * ptrTraver = start;
    while (
        ptrTraver -> next != NULL && 
        ptrTraver -> next -> priority <= priority
    ) {
        ptrTraver = ptrTraver -> next;
    }

    newElement -> next = ptrTraver -> next;
    ptrTraver -> next = newElement;
    length++;
}

void PriorityQueue::dequeue() {
    if (this -> isEmpty()) return;

    Element * currentStart = start;
    start = start -> next;
    free(currentStart);
}

void PriorityQueue::traver() {
    if (this -> isEmpty()) return;
    Element * ptrTraver = start;
    while (ptrTraver != NULL) {
        std::cout << ptrTraver -> priority << "> " << ptrTraver -> data << std::endl;
        ptrTraver = ptrTraver -> next;
    }

}

int main() {
    PriorityQueue queueOne;
    queueOne.enqueue(12, 3);
    queueOne.enqueue(32, 3);
    queueOne.enqueue(14, 2);
    queueOne.enqueue(32, 1);
    queueOne.enqueue(76, 2);
    queueOne.enqueue(13, 3);
    queueOne.traver();
    return 0;
}