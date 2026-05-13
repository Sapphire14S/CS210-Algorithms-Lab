#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp = arr;

    int answer = arr[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }

        answer = max(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}