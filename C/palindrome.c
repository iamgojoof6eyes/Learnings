/*
Palindrome are those string or numbers which is equal even if you reverse them
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lower(char*);
void reverse(char*);

int main() {
    char s[50];
    printf("Give me a string ");
    scanf("%s", &s);
    to_lower(s);
    reverse(s);
    return 0;
}

void to_lower(char* p){
    int l = strlen(p) - 1;
    for(int i = 0; i<=l; i++){
        p[i] = tolower(p[i]);
    }
}

void reverse(char* p){
    int l = strlen(p);
    char t[l], temp;
    strcpy(t,p);
    for(int i = 0; i <= l-1; i++, l--){
        temp = t[i];
        t[i] = t[l-1];
        t[l-1] = temp;
    }
    (strcmp(t, p)) ? printf("Not palindrome") : printf("Palindrome");
    printf("\nPalindrome of %s is %s", p, t);
}
