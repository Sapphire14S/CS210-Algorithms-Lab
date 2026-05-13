#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int n = A.length();
    int m = B.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs = "";

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {

        if (A[i - 1] == B[j - 1]) {
            lcs += A[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "Length: " << dp[n][m] << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}