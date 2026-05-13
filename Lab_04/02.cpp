#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProductSubarray(const vector<int>& arr, int n) {
    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; ++i) {

        // Swap when current element is negative
        if (arr[i] < 0) {
            swap(maxProduct, minProduct);
        }

        maxProduct = max(arr[i], maxProduct * arr[i]);
        minProduct = min(arr[i], minProduct * arr[i]);

        result = max(result, maxProduct);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maximumProductSubarray(arr, n) << endl;

    return 0;
}