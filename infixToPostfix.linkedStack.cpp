#include <iostream>

struct Node
{
    char data;
    Node *next;
};

class LinkedStack
{
private:
    Node *top;
    int length;

public:
    LinkedStack()
    {
        top = NULL;
        length = 0;
    }

    void push(char data);
    void pop();
    char peek();
    void display();
    void clear();
    bool isEmpty();
    int lengthOf();
};

void LinkedStack::push(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    length++;
};

void LinkedStack::pop()
{
    if (top == NULL)
        return;

    Node *currentTop = top;
    top = top->next;
    free(currentTop);
    length--;
}

char LinkedStack::peek()
{
    return top->data;
}

void LinkedStack::display()
{
    Node *ptrTraver = top;
    while (ptrTraver != NULL)
    {
        std::cout << ptrTraver->data << ' ';
        ptrTraver = ptrTraver->next;
    }
}

void LinkedStack::clear()
{
    if (top == NULL)
        return;

    Node *nextPtr = NULL;
    Node *currentPtr = top;

    while (currentPtr != NULL)
    {
        nextPtr = currentPtr->next;
        free(currentPtr);
        currentPtr = nextPtr;
    }

    top = NULL;
};

bool LinkedStack::isEmpty()
{
    return length == 0;
};

int LinkedStack::lengthOf()
{
    return length;
}

int getPriority(char aOperator)
{
    if (aOperator == '%' || aOperator == '*' || aOperator == '/')
        return 1;
    return 0;
}

void infixToPostfix(char expressString[], char targetString[])
{
    LinkedStack stack;
    int i = 0;
    int j = 0;

    while (expressString[i] != '\0')
    {
        if (expressString[i] == '(')
        {
            stack.push(expressString[i]);
            i++;
        }
        else if (expressString[i] == ')')
        {
            while (stack.peek() != '(' && !stack.isEmpty())
            {
                targetString[j] = stack.peek();
                stack.pop();
                j++;
            }

            stack.pop();
            i++;
        }
        else if (
            expressString[i] == '+' ||
            expressString[i] == '/' ||
            expressString[i] == '%' ||
            expressString[i] == '*' |
                expressString[i] == '-')
        {
            while (
                stack.peek() != '(' &&
                !stack.isEmpty() &&
                getPriority(stack.peek()) > getPriority(expressString[i]))
            {
                targetString[j] = stack.peek();
                stack.pop();
                j++;
            }

            stack.push(expressString[i]);
            i++;
        }
        else
        {
            targetString[j] = expressString[i];
            i++;
            j++;
        }
    }

    while (!stack.isEmpty() && stack.peek() != '(')    {
        targetString[j] = stack.peek();
        stack.pop();
        j++;
    }
    targetString[j] = '\0';
}

int main()
{
    char expressionString[100];
    char targetString[100];
    gets(expressionString);
    infixToPostfix(expressionString, targetString);

    int k = 0;
    while (targetString[k] != '\0')
    {
        std::cout << targetString[k] << " ";
        k++;
    }

    return 0;
}