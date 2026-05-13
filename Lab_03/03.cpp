#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int minimumEnergy(const vector<int>& height, int n) {
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);

        int jumpTwo = INT_MAX;

        if (i > 1) {
            jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);
        }

        dp[i] = min(jumpOne, jumpTwo);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << minimumEnergy(height, n) << endl;

    return 0;
}