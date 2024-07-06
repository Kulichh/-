#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int lcm_multiple(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    int p;
    printf("Введіть кількість чисел: ");
    scanf("%d", &p);
    
    int numbers[p];
    printf("Введіть %d натуральних чисел: ", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &numbers[i]);
    }

    int result = lcm_multiple(numbers, p);
    printf("Найменше спільне кратне: %d\n", result);
    
    return 0;
}
