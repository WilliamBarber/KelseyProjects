#include <stdio.h>

int main() {
    int startValue;
    printf("Enter the start value for the series: ");
    scanf("%d", &startValue);

    int endValue;
    printf("Enter the end value for the series: ");
    scanf("%d", &endValue);
    printf("The series is:\n");
    for (int i = startValue; i < endValue; i = i + 1) {
        printf("%d, ", i);
    }
    printf("%d.\n", endValue);
}