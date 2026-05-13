#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<int> dp(m, 0);

    for (int i = 0; i < n; i++) {

        int current = 0;

        for (int j = 0; j < m; j++) {

            if (A[i] == B[j]) {
                dp[j] = max(dp[j], current + 1);
            } else if (A[i] > B[j]) {
                current = max(current, dp[j]);
            }
        }
    }

    int answer = 0;

    for (int value : dp) {
        answer = max(answer, value);
    }

    cout << answer << endl;

    return 0;
}