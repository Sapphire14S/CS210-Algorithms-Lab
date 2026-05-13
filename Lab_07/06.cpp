#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> profit(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    vector<int> dp(n + 1, 0);

    dp[1] = profit[1];

    for (int i = 2; i <= n; i++) {

        dp[i] = max(dp[i - 1], dp[i - 2] + profit[i]);
    }

    cout << dp[n] << endl;

    return 0;
}