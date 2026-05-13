#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
    int m = A.size();
    int n = B.size();

    // Ensure A is the smaller array
    if (m > n) {
        return findMedianSortedArrays(B, A);
    }

    int low = 0;
    int high = m;

    while (low <= high) {
        int partitionA = (low + high) / 2;
        int partitionB = (m + n + 1) / 2 - partitionA;

        int maxLeftA = (partitionA == 0) ? INT_MIN : A[partitionA - 1];
        int minRightA = (partitionA == m) ? INT_MAX : A[partitionA];

        int maxLeftB = (partitionB == 0) ? INT_MIN : B[partitionB - 1];
        int minRightB = (partitionB == n) ? INT_MAX : B[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {

            // Odd total length
            if ((m + n) % 2 == 1) {
                return max(maxLeftA, maxLeftB);
            }

            // Even total length
            return ( max(maxLeftA, maxLeftB) + min(minRightA, minRightB) ) / 2.0;
        }

        else if (maxLeftA > minRightB) {
            high = partitionA - 1;
        }

        else {
            low = partitionA + 1;
        }
    }

    return 0.0;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> A(m);
    vector<int> B(n);

    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    double median = findMedianSortedArrays(A, B);

    // Print integer if whole number
    if (median == static_cast<int>(median)) {
        cout << static_cast<int>(median) << endl;
    } else {
        cout << median << endl;
    }

    return 0;
}