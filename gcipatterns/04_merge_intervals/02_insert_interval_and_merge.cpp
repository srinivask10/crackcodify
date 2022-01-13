using namespace std;
 
#include <iostream>
#include <vector>
#include <algorithm>
 
class Interval {
 public:
  int start = 0;
  int end = 0;
 
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};
 
class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> mergedIntervals;
    
    vector<Interval>::const_iterator itr = intervals.begin();
    while (itr->end < newInterval.start)
        mergedIntervals.push_back(*itr++);
    
    while (itr != intervals.end() && itr->start <= newInterval.end)
    {
        newInterval.start = min(newInterval.start, itr->start);
        newInterval.end = max(newInterval.end, itr->end);
        itr++;
    }

    mergedIntervals.push_back(newInterval);
    
    while (itr != intervals.end())
        mergedIntervals.push_back(*itr++);

    return mergedIntervals;
  }
};
 
int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
 
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
 
  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}

