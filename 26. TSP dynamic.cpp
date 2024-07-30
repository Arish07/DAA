#include <stdio.h>
#include <limits.h>


#define N 4


int dp[1 << N][N];


int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};


int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
    if (mask == ((1 << N) - 1)) {
        
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int answer = INT_MAX;
    for (int city = 0; city < N; city++) {
    
            if ((mask & (1 << city)) == 0) {
               int newAnswer = dist[pos][city] + tsp(mask | (1 << city), city);
            answer = min(answer, newAnswer);
        }
    }

   
   
    dp[mask][pos] = answer;
    return answer;
}

int main() {
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

     int result = tsp(1, 0);

    printf("The minimum cost to visit all cities is: %d\n", result);
    return 0;
}

