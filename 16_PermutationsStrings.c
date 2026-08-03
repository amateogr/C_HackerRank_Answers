#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

int min(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int minimum = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val < minimum) {
            minimum = val;
        }
    }
    
    va_end(args);
    return minimum;
}

int max(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int maximum = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val > maximum) {
            maximum = val;
        }
    }
    
    va_end(args);
    return maximum;
}