#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(const vector<int>& arr, int n) {
    int expectedSum = (n + 1) * (n + 2) / 2;
    int actualSum = 0;

    for (int num : arr) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << findMissingNumber(arr, n) << endl;

    return 0;
}