#include <stdio.h>
#include <string.h>

#define MAX 14

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

unsigned long long countAnagrams(char* word) {
    int len = strlen(word);
    int charCount[256] = {0};

    for (int i = 0; i < len; i++) {
        charCount[(int)word[i]]++;
    }

    unsigned long long result = factorial(len);

    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 1) {
            result /= factorial(charCount[i]);
        }
    }

    return result;
}

int main() {
    char word[MAX + 1];
    
    printf("Введіть слово: ");
    scanf("%14s", word);

    unsigned long long anagrams = countAnagrams(word);
    printf("Кількість анаграм: %llu\n", anagrams);

    return 0;
}
