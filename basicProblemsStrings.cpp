#include <iostream>

int lengthOfString(char aString[]) {
    int length = 0;

    while (aString[length] != '\0') {
        length++;
    }
    
    return length;
}

void toUppercase(char aString[]) {
    int i = 0;
    while (aString[i] != '\0') {
        if (aString[i] >= 'a' && aString[i] <= 'z') {
            aString[i] = aString[i] - 32;
        }

        i++;
    }
}

void toLowercase(char aString[]) {
    int i = 0;
    while (aString[i] != '\0') {
        if (aString[i] >= 'A' && aString[i] <= 'Z') {
            aString[i] = aString[i] + 32;
        }

        i++;
    }
}

void printString(char aString[]) {
    int i = 0;
    while (aString[i] != '\0') {
        std::cout << aString[i];
        i++;
    }
}

void concatString(char firstString[], char secondString[]) {
    int lengthOfFirstString = lengthOfString(firstString);
    int i = 0;
    while (secondString[i] != '\0') {
        firstString[lengthOfFirstString] = secondString[i];
        i++;
        lengthOfFirstString++;
    }
    firstString[lengthOfFirstString] = '\0';
}

bool isEqualString(char firstString[], char secondString[]) {
    int lengthOftheFirst = lengthOfString(firstString);
    int lengthOftheSecond = lengthOfString(secondString);

    if (lengthOftheFirst != lengthOftheSecond) {
        return false;
    }

    for (int i = 0; i < lengthOftheFirst; i++) {
        if (firstString[i] != secondString[i]) {
            return false;
        }
    }
    
    return true;
}

void reversingString(char aString[]) {
    int length = lengthOfString(aString);

    for (int i = 0; i < length/2; i++) {
        char current = aString[i];
        aString[i] = aString[length - 1 - i];
        aString[length - 1 - i] = current;
    }
}

char* subString(char aString[], int position, int length) {
    char *name = &aString[position];
    *(name + length) = '\0';  
    return name;
}

void insertStrToStr(char firstString[], char secondString[], int position) {
    int lengthOfSecond = lengthOfString(secondString);
    int lengthOfFirst = lengthOfString(firstString);
    int i = lengthOfSecond + lengthOfFirst - 1;

    for (; i > position + lengthOfSecond - 1; i--) {
        firstString[i] =  firstString[i - lengthOfSecond];
    }
    i = 0;

    while (secondString[i] != '\0') {
        firstString[position + i] = secondString[i]; 
        i++;
    }
}

int positionSubString(char aString[], char subString[]) {
    int i = 0;
    int j = 0;
    while (aString[i] != '\0') {
        if (aString[i] == subString[j]) {
            int k = i;
            while (subString[j] != "\0" && subString[j] == aString[k]) {
                k++;
                j++;
            } 

            if (subString[j] == '\0') {
                return i;
            } 

            j = 0;
        }
    }

    return -1;
}

void deleteString(char aString[], int &position, int &length) {
    for (int i = position; i <  lengthOfString(aString) - length - 1; i++) {
        aString[i] = aString[position + length];
    }
}

void replacePatternToString(char aString[], char pattern[], char bySubString[]) {
    int positionOfPattern = positionSubString(pattern);
    deleteString(aString, positionOfPattern, lengthOfString(pattern));
    insertStrToStr(aString, bySubString, positionOfPattern);
}

int main () {
    char aString[100], aSecondString[100];
    gets(aString);
    gets(aSecondString);
    toUppercase(aString);
    toLowercase(aString);
    printString(aString);
    std::cout << lengthOfString(aString) << std::endl;
    concatString(aString, aSecondString);
    printString(aString);
    std::cout << isEqualString(aString, aString) << std::endl;
    reversingString(aString);
    printString(aString);
    printString(subString(aString, 4, 3));
    return 0;
}