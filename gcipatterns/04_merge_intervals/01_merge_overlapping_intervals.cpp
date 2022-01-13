using namespace std;
 
#include <algorithm>
#include <iostream>
#include <vector>
 
class Interval {
 public:
  int start = 0;
  int end = 0;
 
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};
 
class MergeIntervals {
 public:
  static vector<Interval> merge(vector<Interval> &intervals) {

    if (intervals.size() < 2)     //empty or only 1 interval
        return intervals;
    
    sort(intervals.begin(), intervals.end(), [](Interval &i1, Interval &i2) { return i1.start < i2.start; });


    vector<Interval> mergedIntervals;
    vector<Interval>::const_iterator itr = intervals.begin();
    int start = itr->start;
    int end = itr->end;
    
    itr++;
    cout << endl;
    while (itr != intervals.end())
    {
        if (itr->start <= end)
        {
            end = max(end, itr->end);
        }
        else
        {
            mergedIntervals.push_back({start, end});
            start = itr->start;
            end = itr->end;
        }
        itr++;
    }

    mergedIntervals.push_back({start, end});

    return mergedIntervals;
  }
};
 
int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
 
  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
 
  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}

