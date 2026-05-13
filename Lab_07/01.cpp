#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cost(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    vector<int> dp(n + 1, INT_MAX);
    vector<int> ways(n + 1, 0);

    dp[1] = cost[1];
    ways[1] = 1;

    for (int i = 2; i <= n; i++) {

        for (int jump = 1; jump <= 2; jump++) {

            int prev = i - jump;

            if (prev >= 1) {

                int currentCost = dp[prev] + cost[i];

                if (currentCost < dp[i]) {
                    dp[i] = currentCost;
                    ways[i] = ways[prev];
                } else if (currentCost == dp[i]) {
                    ways[i] += ways[prev];
                }
            }
        }
    }

    cout << ways[n] << endl;

    return 0;
}