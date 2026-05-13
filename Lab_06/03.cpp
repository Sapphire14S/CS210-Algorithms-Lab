#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

struct GroupInfo {
    int endTime;
    int groupIndex;

    bool operator>(const GroupInfo& other) const {
        return endTime > other.endTime;
    }
};

bool compareIntervals(const pair<Interval, int>& a, const pair<Interval, int>& b) {
    return a.first.start < b.first.start;
}

int main() {
    int n;
    cin >> n;

    vector<pair<Interval, int>> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first.start >> intervals[i].first.end;

        intervals[i].second = i;
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    priority_queue<GroupInfo, vector<GroupInfo>, greater<GroupInfo>> minHeap;

    vector<vector<Interval>> groups;

    for (const auto& item : intervals) {

        Interval current = item.first;

        if (!minHeap.empty() && minHeap.top().endTime < current.start) {

            GroupInfo topGroup = minHeap.top();
            minHeap.pop();

            groups[topGroup.groupIndex].push_back(current);

            minHeap.push({current.end, topGroup.groupIndex});
        } else {
            groups.push_back({current});

            int newGroupIndex = groups.size() - 1;

            minHeap.push({current.end, newGroupIndex});
        }
    }

    cout << "Minimum groups: " << groups.size() << endl;

    for (int i = 0; i < (int)groups.size(); i++) {

        cout << "Group " << i + 1 << ": ";

        for (const Interval& interval : groups[i]) {
            cout << "[" << interval.start << ", " << interval.end << "] ";
        }

        cout << endl;
    }

    return 0;
}