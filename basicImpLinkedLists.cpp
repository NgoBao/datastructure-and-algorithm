#include <iostream>

struct Node
{
    int data;
    Node *next;
};


class LinkedList {
    private:
        Node * start;
        int length;

    public:
        LinkedList() {
            start = NULL;
            length = 0;
        }

        void insert(int data, int position) {
            if (position > length - 1) return;

            if (position == 0 || start == NULL) {
                unshift(data);
                return;
            }

            if (position == length) {
                append(data);
                return;
            }


            Node * newNode = (Node *) malloc(sizeof( Node ));
            Node * ptrTraver = start;
            for (int i = 1; i < position; i++) {
                ptrTraver = ptrTraver -> next;
            }

            newNode -> data = data;
            newNode -> next = ptrTraver -> next;
            ptrTraver -> next = newNode;
            length++;
        } 

        void unshift(int data) {
            Node * newNode = (Node *) malloc(sizeof( Node ));
        
            newNode -> data = data;
            newNode -> next = start;
            start = newNode;
            length++;
        }

        void display() {
            Node * ptrTraver = start;

            while (ptrTraver != NULL) {
                std::cout << ptrTraver -> data << " ";
                ptrTraver = ptrTraver -> next;
            }
        }

        int lengthOf() {
            return length;
        }

        void append(int data) {
            Node * newNode = (Node *) malloc(sizeof( Node ));
            newNode -> data = data;
            newNode -> next = NULL;
            
            if (start == NULL) {
                start = newNode;
                length++;
                return;
            }

            Node * ptrTravel = start;
            while (ptrTravel->next != NULL) {
                ptrTravel = ptrTravel->next;
            }

            ptrTravel->next = newNode;
            length++;
        }

        void removeAt(int position) {
            Node * ptrTraver = start;

            if (position > length - 1) return;
            if (position == 0) start = start -> next;
            

            for (int i = 1; i < position; i++) {
                ptrTraver = ptrTraver -> next;
            }

            ptrTraver -> next = ptrTraver -> next -> next;
            length--;
        }   

        bool isEmpty() {
            return length;
        }

        int indexOf(int data) {
            int position = -1;
            Node * ptrTraver = start;
            while (ptrTraver != NULL) {
                position++;
                if (ptrTraver -> data == data) return position;
                ptrTraver = ptrTraver -> next;
            }

            return -1;
        }
};



int main() {
    LinkedList listOne;
    listOne.unshift(4);
    listOne.unshift(3);
    listOne.unshift(1);
    listOne.unshift(9);
    listOne.append(88);
    listOne.append(42);
    listOne.display();
    std::cout << listOne.lengthOf() << std::endl;
    std::cout << listOne.isEmpty() << std::endl;
    std::cout << listOne.indexOf(88) << std::endl;
    std::cout << listOne.indexOf(0) << std::endl;
    std::cout << listOne.indexOf(42) << std::endl;
    std::cout << listOne.indexOf(9) << std::endl;
    listOne.insert(1607, 4);
    listOne.removeAt(4);
    listOne.removeAt(0);
    listOne.display();
    return 0;
}