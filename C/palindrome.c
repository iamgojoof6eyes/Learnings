/*
Palindrome are those string or numbers which is equal even if you reverse them
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_lower(int, char*);

int main() {
    char p[50]; //will update when learn more c
    
    printf("Give me any character or number ");
    scanf("%s", &p);
    
    int j = strlen(p) - 1; //put a pointer at end of the string i.e. on last character
    
    int i = 0; //put a pointer at first character
    convert_lower(j, p);
    while(i<j){
        if(p[i] != p[j]){
            printf("Give string %s is not a palindrome\n", p);
            return 0;
        }
        else{
            i++;
            j--;
            continue;
        }
    }
    printf("Given string %s is plaindrome\n", p);

    return 0;
}

void convert_lower(int len, char* string) {
    for(int i = 0; i <= len; i++){
        string[i] = tolower(string[i]);
    }
}