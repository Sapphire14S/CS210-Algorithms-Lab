#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {

        for (int i = 0; i + len - 1 < n; i++) {

            int j = i + len - 1;

            if (s[i] == s[j]) {

                if (len == 2) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    string leftPart = "";
    string rightPart = "";

    int i = 0;
    int j = n - 1;

    while (i <= j) {

        if (s[i] == s[j]) {

            if (i == j) {
                leftPart += s[i];
            } else {
                leftPart += s[i];
                rightPart = s[j] + rightPart;
            }

            i++;
            j--;
        } else if (dp[i + 1][j] > dp[i][j - 1]) {
            i++;
        } else {
            j--;
        }
    }

    string lps = leftPart + rightPart;

    cout << "Length: " << dp[0][n - 1] << endl;
    cout << "LPS: " << lps << endl;

    return 0;
}