#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

vector<int> minimumCoverPoints(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<int> selectedPoints;

    int currentPoint = -1;

    for (const Interval& interval : intervals) {

        if (currentPoint < interval.start) {
            currentPoint = interval.end;
            selectedPoints.push_back(currentPoint);
        }
    }

    return selectedPoints;
}

int main() {
    int n;
    cin >> n;

    vector<Interval> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    vector<int> result = minimumCoverPoints(intervals);

    cout << "Selected points: ";

    for (int point : result) {
        cout << point << " ";
    }

    cout << endl;

    return 0;
}