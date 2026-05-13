#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<string> dp(n);

    dp[0] = string(1, s[0]);

    for (int i = 1; i < n; i++) {

        string option1 = dp[i - 1] + s[i];
        string option2 = "~";

        if (i > 1) {
            option2 = dp[i - 2] + s[i];
        }

        dp[i] = min(option1, option2);
    }

    cout << dp[n - 1] << endl;

    return 0;
}