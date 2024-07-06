#include <stdio.h>

#define MAX_P 30

long long dp[MAX_P + 1][4];

long long countValidNumbers(int p) {
    if (p == 0) return 0;
    
    // Initialize base cases
    dp[1][0] = 1; // Ending with single 5
    dp[1][1] = 0; // No sequence of length 1 ends with two 5s
    dp[1][2] = 1; // Ending with single 9
    dp[1][3] = 0; // No sequence of length 1 ends with two 9s

    // Fill dp table
    for (int i = 2; i <= p; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][2];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][2] + dp[i-1][0];
        dp[i][3] = dp[i-1][2];
    }

    // Result is the sum of all valid sequences of length p
    return dp[p][0] + dp[p][1] + dp[p][2] + dp[p][3];
}

int main() {
    int p;
    printf("Enter the value of p (1 <= p <= 30): ");
    scanf("%d", &p);

    if (p < 1 || p > 30) {
        printf("Invalid input. p should be in the range 1 to 30.\n");
        return 1;
    }

    long long result = countValidNumbers(p);
    printf("The number of valid %d-digit numbers is: %lld\n", p, result);

    return 0;
}
