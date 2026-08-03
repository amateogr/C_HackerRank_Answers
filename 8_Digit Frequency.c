#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[1001];
    int count[10] = {0};
    
    scanf("%s", s);
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count[s[i] - '0']++;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d", count[i]);
        if (i < 9) printf(" ");
    }
    
    return 0;
}