#include <iostream>

struct Node {
    int data;
    Node * next;
    Node * prev;
};

class DoubledLinkedList {
    private:
        Node * start;
        int length;

    public:
        DoubledLinkedList() {
            start = NULL;
            length = 0;
        }

    void insert(int data, int position) {
        if (position == 0) {
            unshift(data);
            return;
        }

        if (position == length - 1) {
            apppend(data);
            return;
        }

        Node * newNode = (Node *) malloc(sizeof(Node));
        Node * ptrTraver = start;

        newNode -> data = data;

        for (int i = 0; i < position; i++) {
            ptrTraver = ptrTraver -> next;
        }

        newNode -> next = ptrTraver -> next;
        newNode -> prev = ptrTraver;
        ptrTraver -> next -> prev = newNode;
        ptrTraver -> next = newNode;
        length++;
    };
    
    void unshift(int data) {
        Node * newNode = (Node *) malloc(sizeof(Node));
        newNode -> data = data;
        newNode -> prev = NULL;
    
        (start == NULL) ? newNode -> next = NULL : newNode -> next = start;

        start = newNode;
        length++;
    };
    
    void display() {
        Node * ptrTraver = start;
        while (ptrTraver != NULL) {
            std::cout << ptrTraver -> data << " ";
            ptrTraver = ptrTraver -> next;
        }

    };
    
    int lengthOf() {
        return length;
    }; 
    
    void apppend(int data) {
        Node * newNode = (Node *) malloc(sizeof(Node));
        newNode -> data = data;
        newNode -> next = NULL;

        if (start == NULL) {
            newNode -> prev = NULL;
            start = newNode;
            length++;
            return;
        }

        Node * ptrTraver = start;
        while (ptrTraver -> next != NULL) {
            ptrTraver = ptrTraver -> next;
        }

        ptrTraver -> next = newNode;
        newNode -> prev = ptrTraver;
        length++;
    };

    void removeAt(int position) {
        if (position > length - 1) return;
        if (position == 0) {
            start = start -> next;
            start -> prev = NULL;
            return;
        }

        Node * ptrTraver = start; 
        for (int i = 1; i < position; i++) {
            ptrTraver = ptrTraver -> next;
        }

        ptrTraver -> next -> prev = NULL;
        ptrTraver -> next = ptrTraver -> next -> next;
        ptrTraver -> next -> prev = ptrTraver;
        free(ptrTraver);
        length--;
    };
    
    bool isEmpty() {
        return length;
    };
    
    int indexOf(int data) {
        int position = 0;
        Node * ptrTraver = start;
        while (ptrTraver -> data != data) {
            ptrTraver = ptrTraver -> next;
            position++;
        }

        if (ptrTraver == NULL) return -1;
        return position;
    };
};





int main() {
    return 0;
}