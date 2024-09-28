#include <stdio.h>
#include <string.h>

int main() {
    char p[50]; //will update when learn more c
    
    printf("Give me any character or number ");
    scanf("%s", &p);
    
    int j = strlen(p) - 1;
    int i = 0;
    while(i<j){
        if(p[i] != p[j]){
            printf("Give string is not a palindrome");
            return 0;
        }
        else{
            i++;
            j--;
            continue;
        }
    }
    printf("Given string is plaindrome");

    return 0;
}