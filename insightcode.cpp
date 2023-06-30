#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void closestToZero(int arr[], int n, int *num1, int *num2) {
    if (n < 2) {
        printf("Invalid input. At least two numbers are required.\n");
        return;
    }

    int minSum = INT_MAX;
    int minDiff = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            int diff = abs(arr[i]) - abs(arr[j]);

            if (abs(sum) < abs(minSum) || (abs(sum) == abs(minSum) && abs(diff) < abs(minDiff))) {
                minSum = sum;
                minDiff = diff;
                *num1 = arr[i];
                *num2 = arr[j];
            }
        }
    }
}

int main() {
    int arr[] = {-1, 2, -3, 4, -5, 6,1,12,34};
    int num1, num2;

    closestToZero(arr, sizeof(arr) / sizeof(arr[0]), &num1, &num2);

    printf("Closest pair: [%d, %d]\n", num1, num2);

    return 0;
}
