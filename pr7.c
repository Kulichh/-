#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, r1, x2, y2, r2;
    double d;

    printf("Введіть координати x1, y1, r1, x2, y2, r2 через пробіл: ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (d == 0 && r1 == r2) {
        printf("-1\n");
    } else if (d > r1 + r2 || d < fabs(r1 - r2)) {
        printf("0\n");
    } else if (d == r1 + r2 || d == fabs(r1 - r2)) {
        printf("1\n");
    } else {
        printf("2\n");
    }

    return 0;
}
