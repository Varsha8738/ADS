#include <stdio.h>

// Function to solve the 0/1 Knapsack problem
int knapsack(int w, int weight[], int values[], int n) {
    int dp[w + 1];
    
    // Initialize the dp array
    for (int i = 0; i <= w; i++)
        dp[i] = 0;
    
    // Process each item
    for (int i = 0; i < n; i++) {
        // Iterate backward to avoid overwriting results
        for (int currentWeight = w; currentWeight >= weight[i]; currentWeight--) {
            dp[currentWeight] = dp[currentWeight] > (dp[currentWeight - weight[i]] + values[i])
                                    ? dp[currentWeight]
                                    : (dp[currentWeight - weight[i]] + values[i]);
        }
    }
    return dp[w];
}

int main() {
    int values[] = {60, 100, 120}; // Item values
    int weight[] = {10, 20, 30};  // Item weights
    int w = 50;                   // Knapsack capacity
    int n = sizeof(values) / sizeof(values[0]); // Number of items

    // Call the knapsack function and print the result
    int max_value = knapsack(w, weight, values, n);
    printf("Maximum value in the knapsack: %d\n", max_value);

    return 0;
}
