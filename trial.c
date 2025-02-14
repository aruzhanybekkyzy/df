
#include <stdio.h>

void reverseStringRecursively(char* str, char* rev, int start, int end) {
    if(start < end){
        int temp = rev[start];
        rev[start] = str[end];
        str[end] = temp;
        reverseStringRecursively(str, rev, start + 1, end - 1);
    }
}

_Bool areStringsSame(char* str1, char* str2, int length) {
    
    for(int i = 0; i < length; i++){
        str2[i] = str2[i+1];
    }
    
    str2[length-1] = '\n';
    
    for(int i = 0; i < length; i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    char inputStr[100], reversedStr[100];
    int length = 0; // To store the length of the input string
    
    printf("Enter a string: ");
    fgets(inputStr, sizeof(inputStr), stdin);

    // Remove newline character added by fgets, if any
    if (inputStr[length] == '\n') {
        inputStr[length] = '\0';
    }
    
    // Calculating length of the string and copying to reversedStr without using strlen and strcpy
    while (inputStr[length] != '\0') {
        reversedStr[length] = inputStr[length];
        length++;
    }
    reversedStr[length] = '\0'; // Adding null terminator to the end of reversedStr

    reverseStringRecursively(reversedStr, reversedStr, 0, length - 1); // Passing reversedStr as both original and destination to avoid strcpy
    
    printf("Reversed String: %s\n", reversedStr);
    
    if (areStringsSame(inputStr, reversedStr, length)) {
        printf("The original and reversed strings are the same.\n");
    } else {
        printf("The original and reversed strings are different.\n");
    }
    
    return 0;
}

 

