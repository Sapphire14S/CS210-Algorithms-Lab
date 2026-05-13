#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);

    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    vector<vector<int>> dp(n, vector<int>(2, 1));

    int answer = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            for (int prevChoice = 0; prevChoice < 2; prevChoice++) {

                int prevValue = (prevChoice == 0) ? pairs[j].first : pairs[j].second;

                for (int currChoice = 0; currChoice < 2; currChoice++) {

                    int currValue = (currChoice == 0) ? pairs[i].first : pairs[i].second;

                    if (currValue > prevValue) {
                        dp[i][currChoice] = max(dp[i][currChoice], dp[j][prevChoice] + 1);
                    }
                }
            }
        }

        answer = max(answer, max(dp[i][0], dp[i][1]));
    }

    cout << answer << endl;

    return 0;
}