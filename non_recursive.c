#include <stdio.h>
#include <stdlib.h>

int iterative1Bruteforce(int A[], int N) {
    for (int i = 0; i < N; i++) {
        int count = 0;

        for (int j = 0; j < N; j++) {
            if (A[j] == A[i]) {
                count++;
            }
        }

        if (count > N / 2) {
            return i;
        }
    }

    return -1;
}

int main() {

    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int index = iterative1Bruteforce(arr, n);

    if (index == -1) {
        printf("Result: -1\n");
    }
    else {
        int value = arr[index];

        printf("Dominator: %d\n", value);

        printf("Indices: ");

        int first = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == value) {
                if (!first) printf(", ");
                printf("%d", i);
                first = 0;
            }
        }

        printf("\n");
    }

    return 0;
}
