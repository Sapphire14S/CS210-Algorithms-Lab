#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int left, int right, int pivotValue) {
    int pivotIndex = left;

    for (int i = left; i <= right; i++) {
        if (arr[i] == pivotValue) {
            pivotIndex = i;
            break;
        }
    }

    swap(arr[pivotIndex], arr[right]);

    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }

    swap(arr[storeIndex], arr[right]);

    return storeIndex;
}

int medianOfMedians(vector<int>& arr, int left, int right);

int kthSmallest(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotValue = medianOfMedians(arr, left, right);

    int pivotIndex = partition(arr, left, right, pivotValue);

    int order = pivotIndex - left + 1;

    if (order == k) {
        return arr[pivotIndex];
    }

    if (k < order) {
        return kthSmallest(arr, left, pivotIndex - 1, k);
    }

    return kthSmallest(arr, pivotIndex + 1, right, k - order);
}

int medianOfMedians(vector<int>& arr, int left, int right) {
    int n = right - left + 1;

    if (n <= 5) {
        sort(arr.begin() + left, arr.begin() + right + 1);
        return arr[left + n / 2];
    }

    vector<int> medians;

    for (int i = left; i <= right; i += 5) {
        int subRight = min(i + 4, right);

        sort(arr.begin() + i, arr.begin() + subRight + 1);

        int medianIndex = i + (subRight - i) / 2;

        medians.push_back(arr[medianIndex]);
    }

    return kthSmallest(medians, 0, medians.size() - 1, (medians.size() + 1) / 2);
}

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cout << kthSmallest(arr, 0, n - 1, k) << endl;

    return 0;
}