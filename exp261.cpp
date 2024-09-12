#include <stdio.h>

void printPattern(int n, int i) {
    if (i > n)
        return;

    for (int j = 1; j <= i; j++)
        printf("%d ", j);

    printf("\n");
    printPattern(n, i+1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printPattern(n, 1);

    return 0;
}
