#include <iostream>
#include <vector>

using namespace std;

int findCandidate(const vector<int>& arr, int n) {
    int candidate = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    return candidate;
}

bool isMajorityElement(const vector<int>& arr, int n, int candidate) {
    int count = 0;

    for (int num : arr) {
        if (num == candidate) {
            count++;
        }
    }

    return count > n / 2;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int candidate = findCandidate(arr, n);

    if (isMajorityElement(arr, n, candidate)) {
        cout << candidate << endl;
    } else {
        cout << "No Majority Element" << endl;
    }

    return 0;
}