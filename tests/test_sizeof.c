#include <stdio.h>
#include <string.h>

int main() {
    char f[10];
    float f1 = 10.20;
    sprintf(f, "%2.1f", f1);
    printf("%s\n", f);
    printf("%d\n", strlen(f));
}
