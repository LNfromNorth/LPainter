#include <string.h>
#include <stdio.h>

#define PRINT_VALUE(format, value, type) do {\
    type* ptr = (type*)(value); \
    printf(format, *ptr); \
} while(0);

int parse_para(const char* format, void* value) {
    int* ptr = (int*)value;
    printf(format, *ptr);
    return 0;
}

int main() {
    int a = 10;
    float b = 20.0;
    PRINT_VALUE("%d\n", &a, int);
    PRINT_VALUE("%.2f\n", &b, float);
    return 0;
}
