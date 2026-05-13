#include <iostream>
#include <vector>

using namespace std;

int findMinimumIndex(const vector<int>& arr, int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index = findMinimumIndex(arr, n);

    cout << index << endl;

    return 0;
}