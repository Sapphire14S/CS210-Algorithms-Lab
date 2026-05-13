#include <iostream>
#include <vector>

using namespace std;

int findFixedPoint(const vector<int>& arr, int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid) {
            return mid;
        }

        if (arr[mid] < mid) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findFixedPoint(arr, n);

    cout << result << endl;

    return 0;
}