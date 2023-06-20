class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    int num_events = events.size();
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int max_events_attendable = 0;

    // sort events based on start-day
    sort(begin(events), end(events));

    for (int day = 1, idx = 0; day <= (int)1e5; day++) {
      while (!min_heap.empty() && min_heap.top() < day)
        min_heap.pop();

      // add the end-day of events that started today
      while (idx < num_events && events[idx][0] == day)
        min_heap.push(events[idx++][1]);

      if (!min_heap.empty()) {
        min_heap.pop();
        max_events_attendable++;
      }
    }

    return max_events_attendable;
  }
};
