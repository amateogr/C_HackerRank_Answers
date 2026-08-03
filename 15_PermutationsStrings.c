#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    // Step 1: Find the largest index i such that s[i] < s[i+1]
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {
        i--;
    }
    
    // If no such index exists, this is the last permutation
    if (i < 0) {
        return 0;
    }
    
    // Step 2: Find the largest index j > i such that s[i] < s[j]
    int j = n - 1;
    while (j > i && strcmp(s[i], s[j]) >= 0) {
        j--;
    }
    
    // Step 3: Swap s[i] and s[j]
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    
    // Step 4: Reverse the suffix starting at i+1
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    
    return 1;
}