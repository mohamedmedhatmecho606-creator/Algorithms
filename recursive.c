#include <stdio.h>

typedef struct {
    int index;
    int count;
} Pair;

int countOccurrencesRange(int A[], int candidate, int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (A[i] == candidate) {
            count++;
        }
    }
    return count;
}

Pair getDominatorRecursiveUtil(int A[], int start, int end) {
    if (start == end) {
        Pair res = {start, 1};
        return res;
    }

    int mid = start + (end - start) / 2;
    Pair leftRes = getDominatorRecursiveUtil(A, start, mid);
    Pair rightRes = getDominatorRecursiveUtil(A, mid + 1, end);

    if (leftRes.index != -1 && rightRes.index != -1 && A[leftRes.index] == A[rightRes.index]) {
        Pair res = {leftRes.index, leftRes.count + rightRes.count};
        return res;
    }

    int leftCount = 0;
    if (leftRes.index != -1) {
        leftCount = countOccurrencesRange(A, A[leftRes.index], start, end);
    }

    int rightCount = 0;
    if (rightRes.index != -1) {
        rightCount = countOccurrencesRange(A, A[rightRes.index], start, end);
    }

    int size = end - start + 1;
    if (leftCount > size / 2) {
        Pair res = {leftRes.index, leftCount};
        return res;
    } else if (rightCount > size / 2) {
        Pair res = {rightRes.index, rightCount};
        return res;
    }

    Pair res = {-1, 0};
    return res;
}

int recursive6DivideAndConquer(int A[], int N) {
    if (N == 0) return -1;
    Pair res = getDominatorRecursiveUtil(A, 0, N - 1);
    return res.index;
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

    int index = recursive6DivideAndConquer(arr, n);
    
    if (index == -1) {
        printf("Result: -1\n");
    } else {
        int value = arr[index];
        printf("Result: ");
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
        printf("-1\n");
    } 
    else {
        int value = arr[index];  
        for (int i = 0; i < n; i++) {
            if (arr[i] == value) {
                printf("%d\n", i);
            }   
        }
    }


    return 0;
}
