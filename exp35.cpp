#include <stdio.h>
#include <limits.h>

#define N 4 // Number of workers/tasks (adjust as needed)
#define INF INT_MAX

// Function prototypes
void branchAndBound(int cost[N][N], int n);
int minimumCost(int cost[N][N], int rowMask, int colMask, int n);
void printAssignment(int assignment[], int n);

int main() {
    int cost[N][N] = {
        {10, 19, 8, 15},
        {10, 18, 7, 17},
        {13, 16, 9, 14},
        {12, 19, 8, 18}
    };

    printf("Cost matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    branchAndBound(cost, N);
    return 0;
}

// Recursive Branch and Bound function
int branchAndBoundHelper(int cost[N][N], int row, int colMask, int assignment[], int n) {
    if (row == n) {
        // All rows are processed, calculate total cost
        int totalCost = 0;
        for (int i = 0; i < n; i++) {
            totalCost += cost[i][assignment[i]];
        }
        return totalCost;
    }

    int minCost = INF;
    for (int col = 0; col < n; col++) {
        if (!(colMask & (1 << col))) {
            assignment[row] = col;
            int currentCost = cost[row][col] + branchAndBoundHelper(cost, row + 1, colMask | (1 << col), assignment, n);
            if (currentCost < minCost) {
                minCost = currentCost;
            }
        }
    }
    return minCost;
}

void branchAndBound(int cost[N][N], int n) {
    int assignment[N];
    int minCost = branchAndBoundHelper(cost, 0, 0, assignment, n);

    printf("Minimum cost is %d\n", minCost);
    printf("Optimal assignment:\n");
    printAssignment(assignment, n);
}

void printAssignment(int assignment[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Worker %d -> Task %d\n", i + 1, assignment[i] + 1);
    }
}

