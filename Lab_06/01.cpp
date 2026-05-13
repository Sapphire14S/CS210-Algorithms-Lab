#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long minimumMergeCost(const vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int fileSize : files) {
        minHeap.push(fileSize);
    }

    long long totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int merged = first + second;

        totalCost += merged;

        minHeap.push(merged);
    }

    return totalCost;
}

int main() {
    int n;
    cin >> n;

    vector<int> files(n);

    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    cout << minimumMergeCost(files) << endl;

    return 0;
}