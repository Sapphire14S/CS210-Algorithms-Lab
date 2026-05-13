#include <iostream>
#include <vector>

using namespace std;

int interpolationSearch(const vector<int>& arr, int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {

        // Avoid division by zero
        if (arr[low] == arr[high]) {
            if (arr[low] == target) {
                return low;
            }
            return -1;
        }

        int pos = low + (
            (static_cast<long long>(target - arr[low]) * (high - low)) /
            (arr[high] - arr[low])
        );

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = interpolationSearch(arr, n, target);

    cout << result << endl;

    return 0;
}