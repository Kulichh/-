#include <stdio.h>

int main() {
    int n;
    printf("Введіть натуральне число n: ");
    scanf("%d", &n);

    int count = 0;

    for (int m = 1; m < n; ++m) {
        if (n % m == n / m) {
            count++;
        }
    }

    printf("Кількість рівних дільників числа %d: %d\n", n, count);
    return 0;
}
