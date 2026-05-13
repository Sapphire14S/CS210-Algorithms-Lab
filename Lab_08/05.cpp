#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    int answer = arr[0];

    for (int d = 0; d <= k; d++) {
        dp[0][d] = arr[0];
    }

    for (int i = 1; i < n; i++) {
        for (int d = 0; d <= k; d++) {

            dp[i][d] = arr[i];

            dp[i][d] = max(dp[i][d], dp[i - 1][d] + arr[i]);

            if (d > 0) {
                dp[i][d] = max(dp[i][d], dp[i - 1][d - 1]);
            }

            answer = max(answer, dp[i][d]);
        }
    }

    cout << answer << endl;

    return 0;
}