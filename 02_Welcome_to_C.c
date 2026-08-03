#include <stdio.h>
#include <string.h>

int main() {
    char ch;
    char s[100];
    char sen[100];
    
    // Read a single character
    scanf("%c", &ch);
    
    // Read a string (single word, no spaces)
    scanf("%s", s);
    
    // Consume the leftover newline before reading the sentence
    scanf("\n");
    
    // Read a full sentence (until newline)
    scanf("%[^\n]%*c", sen);
    
    // Print outputs
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    
    return 0;
}