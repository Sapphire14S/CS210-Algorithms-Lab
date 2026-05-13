#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(const vector<int>& arr, int n) {
    vector<int> dp(n, 1);

    int lisLength = 1;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        lisLength = max(lisLength, dp[i]);
    }

    return lisLength;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n) << endl;

    return 0;
}