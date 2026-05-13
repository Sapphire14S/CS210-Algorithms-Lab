#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minimumCoins(const vector<int>& coins, int m, int target) {
    vector<int> dp(target + 1, INT_MAX);

    dp[0] = 0;

    for (int amount = 1; amount <= target; ++amount) {

        for (int i = 0; i < m; i++) {

            if (coins[i] <= amount && dp[amount - coins[i]] != INT_MAX) {
                dp[amount] = min(dp[amount], dp[amount - coins[i]] + 1);
            }
        }
    }

    return (dp[target] == INT_MAX) ? -1 : dp[target];
}

int main() {
    int m, target;
    cin >> m >> target;

    vector<int> coins(m);

    for (int i = 0; i < m; i++) {
        cin >> coins[i];
    }

    cout << minimumCoins(coins, m, target) << endl;

    return 0;
}