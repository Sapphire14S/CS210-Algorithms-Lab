#include <iostream>
#include <vector>

using namespace std;

int binarySearchIncreasing(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int binarySearchDecreasing(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int findPeakIndex(const vector<int>& arr, int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int searchMountainArray(const vector<int>& arr, int n, int target) {
    int peak = findPeakIndex(arr, n);

    int index = binarySearchIncreasing(arr, 0, peak, target);

    if (index != -1) {
        return index;
    }

    return binarySearchDecreasing(arr, peak + 1, n - 1, target);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int result = searchMountainArray(arr, n, target);

    cout << result << endl;

    return 0;
}