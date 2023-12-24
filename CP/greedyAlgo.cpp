// Tomorrow Peter has a Biology exam. He does not like this subject much, but d days ago he learnt that he would have to take this exam. Peter's strict parents made him prepare for the exam immediately, for this purpose he has to study not less than minTimei and not more than maxTimei hours per each i-th day. Moreover, they warned Peter that a day before the exam they would check how he has followed their instructions.

// So, today is the day when Peter's parents ask him to show the timetable of his preparatory studies. But the boy has counted only the sum of hours sumTime spent him on preparation, and now he wants to know if he can show his parents a timetable sсhedule with d numbers, where each number sсhedulei stands for the time in hours spent by Peter each i-th day on biology studies, and satisfying the limitations imposed by his parents, and at the same time the sum total of all schedulei should equal to sumTime.

// Input
// The first input line contains two integer numbers d, sumTime (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during which Peter studied, and the total amount of hours, spent on preparation. Each of the following d lines contains two integer numbers minTimei, maxTimei (0 ≤ minTimei ≤ maxTimei ≤ 8), separated by a space — minimum and maximum amount of hours that Peter could spent in the i-th day.

// Output
// In the first line print YES, and in the second line print d numbers (separated by a space), each of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, if he followed his parents' instructions; or print NO in the unique line. If there are many solutions, print any of them.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int d, sumTime;
    cin >> d >> sumTime;

    vector<int> minTime(d), maxTime(d);
    for (int i = 0; i < d; ++i) {
        cin >> minTime[i] >> maxTime[i];
    }

    int minSum = 0, maxSum = 0;
    for (int i = 0; i < d; ++i) {
        minSum += minTime[i];
        maxSum += maxTime[i];
    }

    if (sumTime < minSum || sumTime > maxSum) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> schedule(d);
        for (int i = 0; i < d; ++i) {
            schedule[i] = minTime[i];
            sumTime -= minTime[i];
        }

        for (int i = d - 1; i >= 0 && sumTime > 0; --i) {
            int diff = maxTime[i] - minTime[i];
            int addTime = min(diff, sumTime);
            schedule[i] += addTime;
            sumTime -= addTime;
        }

        for (int i = 0; i < d; ++i) {
            cout << schedule[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
