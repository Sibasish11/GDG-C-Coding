#include <stdio.h>
#include <stdlib.h>


// Function to check if a number is prime or not 
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// My Core logic function that computes the zigzag sum
int compute_zigzag_sum(int** matrix, int n) {
    int sum = 0;

    // Loop through all diagonals of the matrix
    for (int d = 0; d <= 2 * (n - 1); d++) {
        int start_row = (d < n) ? d : n - 1;
        int start_col = (d < n) ? 0 : d - n + 1;

        // Even diagonals: down-left (↙)
        if (d % 2 == 0) {
            for (int i = start_row, j = start_col; i >= 0 && j < n; i--, j++) {
                int val = *(*(matrix + i) + j);
                sum += is_prime(val) ? -val : val;
            }
        }
        // Odd diagonals: up-right (↗)
        else {
            for (int i = start_col, j = start_row; i < n && j >= 0; i++, j--) {
                int val = *(*(matrix + j) + i);
                sum += is_prime(val) ? -val : val;
            }
        }
    }

    return sum;
}

int main() {
    int n;
    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    // Allocate memory dynamically for an n x n matrix 
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        *(matrix + i) = (int*)malloc(n * sizeof(int));
    }

    // Inputing the matrix values
    printf("Enter the matrix values row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", *(matrix + i) + j);
        }
    }

    // To Compute result i am using the zigzag sum logic
    int result = compute_zigzag_sum(matrix, n);
    printf("Final computed zigzag sum is: %d\n", result);

    //  i will assign free memory allocation for the matrix
    for (int i = 0; i < n; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}
