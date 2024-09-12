#include <stdio.h>

#define INF 9999999
#define N 20  // Adjust N to a manageable size

int tsp(int graph[][N], int pos, int visited, int n, int dp[][1 << N]) {
    // Base case: All cities have been visited
    if (visited == (1 << n) - 1)
        return graph[pos][0];

    // Return cached result if already computed
    if (dp[pos][visited] != -1)
        return dp[pos][visited];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        // Visit the next city if it hasn't been visited
        if ((visited & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, city, visited | (1 << city), n, dp);
            ans = (ans < newAns) ? ans : newAns;
        }
    }

    return dp[pos][visited] = ans;
}

int main() {
    int n;

    printf("Enter the number of cities (<= %d): ", N);
    scanf("%d", &n);

    if (n > N) {
        printf("Number of cities exceeds the maximum limit of %d.\n", N);
        return 1;
    }

    int graph[N][N], dp[N][1 << N];

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Initialize the dp table
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = -1;

    // Start the TSP from the first city
    printf("Minimum cost is %d\n", tsp(graph, 0, 1, n, dp));

    return 0;
}

