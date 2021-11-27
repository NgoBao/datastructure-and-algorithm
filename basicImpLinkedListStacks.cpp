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

        void push(int data) {
            Node * newNode = (Node *) malloc(sizeof(Node));
            newNode -> data = data;
            newNode -> next = top;
            top = newNode;
            length++;
        };

        void pop() {
            if (top == NULL) return;

            Node * currentTop = top;
            top = currentTop -> next;
            free(currentTop);
            length--;
        };

        int peek() {
            if (top != NULL ) return top -> data;
            return -1;
        };

        bool isEmpty() {
            return top;
        };

        void clear() {
            Node * nextTraver = NULL;
            Node * currentTraver = top;
            while (currentTraver != NULL) {
                nextTraver = currentTraver -> next;
                free(currentTraver);
                currentTraver = nextTraver;
            };
            top = NULL;
        };

        int lengthOf() {
            return length;
        }; 

        void display() {
            Node * ptrTraver = top;
            while (ptrTraver != NULL) {
                std::cout << ptrTraver -> data << " ";
                ptrTraver = ptrTraver -> next;
            }
        };
};


int main() {
    LinkedStack stackOne;
    stackOne.pop();
    stackOne.push(4);
    stackOne.push(2);
    stackOne.push(9);
    stackOne.push(10);
    stackOne.push(4);
    stackOne.push(2);
    stackOne.push(9);
    stackOne.push(10);
    stackOne.display();
    stackOne.pop();
    std::cout << "the peek is: " << stackOne.peek() << std::endl; 
    std::cout << "the length is: " << stackOne.lengthOf() << std::endl;
    std::cout << "isEmpty: " << stackOne.isEmpty() << std::endl;
    stackOne.clear();
    return 0;
}