#include <iostream>

int const stackMaxSize = 10;

class Stack {
    private:
        int stackStorage[stackMaxSize];
        int length;

    public:
        Stack() {
            length = 0;
        }

        void push(int data) {
            if (length == stackMaxSize) {
                std::cout << "stack overflow" << std::endl;
                return;
            };
            stackStorage[length] = data;
            length++;
        };

        void pop() {
            if (length == 0) return;
            length--;
        };

        int peek() {
            if (length == 0) return -1;
            return stackStorage[length - 1];
        };

        bool isEmpty() {
            return length == 0;
        };

        void clear() {
            length = 0;
        };

        int lengthOf() {
            return length;
        };

        void display() {
            if (length == 0) return;
            for (int i = 0; i < length; i++) {
                std::cout << stackStorage[i] << " ";
            }
        }
};


int main() {
    Stack stackOne;
    stackOne.pop();
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