#include <iostream>


struct Node {
    int data;
    Node * next;
};

class LinkedStack {
    private:
        Node * top;
        int length;

    public:
        LinkedStack() {
            top = NULL;
            length = 0;
        }

        void push(int data);
        void pop();
        int peek();
        void display();
        void clear();
        bool isEmpty();
        int lengthOf();
};

void LinkedStack::push(int data) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = top;
    top = newNode;
    length++;
};

void LinkedStack::pop() {
    if (top == NULL) return;

    Node * currentTop = top;
    top = top -> next;
    free(currentTop);
    length--;
}

int LinkedStack::peek() {
    return top -> data;
}

void LinkedStack::display() {
    Node * ptrTraver = top;
    while (ptrTraver != NULL) {
        std::cout << ptrTraver -> data << ' ';
        ptrTraver = ptrTraver -> next;
    }
}

void LinkedStack::clear() {
    if (top == NULL) return;

    Node * nextPtr = NULL;
    Node * currentPtr = top;

    while (currentPtr != NULL) {
        nextPtr = currentPtr -> next;
        free(currentPtr);
        currentPtr = nextPtr;
    }

    top = NULL;
};

bool LinkedStack::isEmpty() {
    return length;
};

int LinkedStack::lengthOf() {
    return length;
}

void createReverseNumber(LinkedStack stack) {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int currentValue;
        std::cin >> currentValue;
        stack.push(currentValue);
    }
}

int main() {

    LinkedStack listOne;



    createReverseNumber(listOne);
    listOne.display();
    return 0;
}