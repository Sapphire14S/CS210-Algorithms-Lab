#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

int maximumOverlap(vector<Interval>& intervals, int n) {
    sort(intervals.begin(), intervals.end(),
         [](const Interval& a, const Interval& b) {
             return a.start < b.start;
         });

    int maxOverlap = 0;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            int overlapStart = max(intervals[i].start, intervals[j].start);

            int overlapEnd = min(intervals[i].end, intervals[j].end);

            if (overlapStart <= overlapEnd) {
                int overlapLength = overlapEnd - overlapStart + 1;

                maxOverlap = max(maxOverlap, overlapLength);
            }
        }
    }

    return maxOverlap;
}

int main() {
    int n;
    cin >> n;

    vector<Interval> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    cout << maximumOverlap(intervals, n) << endl;

    return 0;
}