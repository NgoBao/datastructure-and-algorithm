#include <iostream>

void readingArray(int array[], int &length) {
    std::cout << "entering your array's length" << std::endl;
    std::cin >> length;

    for (int i = 0; i < length; i++) {
        std::cout << "value for [" << i << "] ";
        std::cin >> array[i];
    }
}

void displayingArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << "[" << i << "] " << array[i] << std::endl; 
    }
} 

int poisitionSmallestElement(int array[], int &length) {
    int smallestPosition = 0;
    
    for (int i = 1; i < length; i++) {
        if (array[smallestPosition] > array[i]) {
            smallestPosition = i;
        }
    }

    return smallestPosition;
}

int poisitionLargestElement(int array[], int &length) {
    int LargestPosition = 0;
    
    for (int i = 1; i < length; i++) {
        if (array[LargestPosition] < array[i]) {
            LargestPosition = i;
        }
    }

    return LargestPosition;
}

int secondLargestElement(int array[], int &length) {
    int secondLargestPosition = -1;
    int largestPosition = poisitionLargestElement(array, length);

    for (int i = 0; i < length; i++) {
        if (
            array[i] != array[largestPosition] && 
            array[i] > array[secondLargestPosition]
        ) {
            secondLargestPosition = i;
        }
    }

    return array[secondLargestPosition];
}

bool isDuplicatedElementArray(int array[], int &length) {
    bool isDuplication = false;
    
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length;  j++) {
            if (array[i] == array[j] && i != j) {
                isDuplication = true;
            } 
        }
    }

    return isDuplication;
}

void insertElementToArray(int array[], int &length, int value, int position) {
    for (int i = length; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = value;
    length++;
}

void insertEleToASCEArray(int array[], int &length, int value) {
    int positionInArr = -1;

    for (int i = 0; i < length; i++) {
        if (array[i] > value) {
            positionInArr = i;
            break;
        }
    }

    insertElementToArray(array, length, value, positionInArr);
}

void deleteElementFromArray(int array[], int &length, int position) {
    for (int i = position; i < length - 1; i++) {
        array[i] = array[i + 1];
    }

    length--;
}

void deleteElementFromASCEArray(int array[], int &length, int value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            deleteElementFromArray(array, length, i);
            i--;
        } 
    }
}

void mergingTwoArray(int firstArray[], int &firstLength, int secondArray[], int &secondLength, int newArray[]) {
    for (int i = 0; i < firstLength; i++) {
        newArray[i] = firstArray[i];
    } 

    for (int i = 0; i < secondLength; i++) {
        newArray[firstLength + i] = secondArray[i];
    }
}

int main() {
    int array[20], length;
    int theSecondArray[20], secondLength;
    int newArray[40];
    readingArray(array, length);
    readingArray(theSecondArray, secondLength);
    displayingArray(array, length);
    std::cout << poisitionSmallestElement(array, length) << std::endl;
    std::cout << "the second largest element " << secondLargestElement(array, length) << std::endl;
    std::cout << "the array contained duplicated element or not ?? " << isDuplicatedElementArray(array, length) << std::endl;
    insertElementToArray(array, length, 4, 0);
    displayingArray(array, length);
    deleteElementFromArray(array, length, 0);
    displayingArray(array, length);
    deleteElementFromASCEArray(array, length, 7);
    displayingArray(array, length);
    mergingTwoArray(array, length, theSecondArray, secondLength, newArray);
    displayingArray(newArray, (length + secondLength));
}