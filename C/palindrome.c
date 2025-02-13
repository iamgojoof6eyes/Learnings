/*
Palindrome are those string or numbers which is equal even if you reverse them
*/

#include <stdio.h>
#include <string.h>

int main() {
    char p[50]; //will update when learn more c
    
    printf("Give me any character or number ");
    scanf("%s", &p);
    
    int j = strlen(p) - 1; //put a pointer at end of the string i.e. on last character
    
    int i = 0; //put a pointer at first character

    while(i<j){
        if(p[i] != p[j]){
            printf("Give string is not a palindrome\n");
            return 0;
        }
        else{
            i++;
            j--;
            continue;
        }
    }
    printf("Given string is plaindrome\n");

    return 0;
}