#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int n = arr.size();

    if (n % 2 == 1) {
        return arr[n / 2];
    }

    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    double median = findMedian(arr);

    vector<pair<double, int>> distanceArray;

    for (int value : arr) {
        distanceArray.push_back({abs(value - median), value});
    }

    sort(distanceArray.begin(), distanceArray.end());

    for (int i = 0; i < k; i++) {
        cout << distanceArray[i].second;

        if (i != k - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}