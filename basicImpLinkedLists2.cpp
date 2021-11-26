#include <iostream>

struct Node {
    int data;
    Node * next;
};

class CircularLinkedlist {
    private:
        Node * start;
        int length;

    public:
        CircularLinkedlist() {
            start = NULL;
            length = 0;
        };

        void insert(int data, int position) {
            if (position == 0) { 
                unshilf(data);
                return;
            };

            if (position == length) { 
                append(data);
                return;
            };

            Node * ptrTraver = start;
            Node * newNode = (Node *)malloc(sizeof(Node));
            newNode -> data = data;

            for (int i = 1; i < position; i++) {
                ptrTraver = ptrTraver -> next;
            }

            newNode -> next = ptrTraver -> next;
            ptrTraver -> next = newNode;
            length++;
        };
        
        void append(int data) {
            if (start == NULL) unshilf(data);

            Node * newNode = (Node *)malloc(sizeof(Node));
            Node * ptrTraver = start;

            newNode -> data = data;
            newNode -> next = start;

            while(ptrTraver -> next != start) {
                ptrTraver = ptrTraver -> next;
            }

            ptrTraver -> next = newNode;
            length++;
        };
        
        void shift() {
            Node * ptrTraver = start;
            while (ptrTraver -> next != start) {
                ptrTraver = ptrTraver -> next;
            }

            ptrTraver -> next = start -> next;
            start = start -> next;
        }

        void pop() {
            Node * ptrTraver = start;

            if (length == 1) {
                start = NULL;
                return;
            }

            while (ptrTraver -> next -> next != start) {
                ptrTraver = ptrTraver -> next;
            }

            ptrTraver -> next = start;
        }

        void removeAt(int position) {
            if (position == 0) {
                shift();
                return;
            }

            if (position == length - 1) {
                pop();
                return;
            }

            Node * ptrTraver = start;
            for (int i = 1; i < position; i++) {
                ptrTraver = ptrTraver -> next;
            }

            ptrTraver -> next = ptrTraver -> next -> next;  
        };
        
        int lengthOf() {
            return length;
        };

        void unshilf(int data) {
            Node * newNode = (Node *) malloc(sizeof( Node ));
            newNode -> data = data;

            if (start == NULL) {
                newNode -> next = newNode;
                start = newNode;
                length++;
                return;
            }
            
            Node * ptrTraver = start;
            while (ptrTraver -> next != start && ptrTraver != NULL) {
                ptrTraver = ptrTraver -> next;
            }

            ptrTraver -> next = newNode;
            newNode -> next = start;
            start = newNode;
            length++;
        };

        int indexOf(int data) {
            Node * ptrTraver = start;
            int position = -1;
            while(ptrTraver && ptrTraver -> next != start) {
                position++;
                if (ptrTraver -> data == data) return position;
                ptrTraver = ptrTraver -> next;
            }

            return -1;
        };

        bool isEmpty() {
            return start;
        };

        void display() {
            Node * ptrTraver = start;
            while (ptrTraver) {
                std::cout << ptrTraver -> data << std::endl;
                if (ptrTraver -> next == start) return;
                ptrTraver = ptrTraver -> next;
            }
        };
};


int main() {
    CircularLinkedlist listOne;
    listOne.unshilf(3);
    listOne.unshilf(4);
    listOne.unshilf(6);
    listOne.append(8);
    listOne.display();

    listOne.insert(12, 4);
    listOne.display();
    listOne.shift();
    listOne.pop();
    listOne.removeAt(1);
    listOne.display();
    std::cout << listOne.indexOf(8) << std::endl;
    return 0;
}
