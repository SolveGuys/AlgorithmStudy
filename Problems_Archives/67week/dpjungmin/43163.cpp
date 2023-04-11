#include <bits/stdc++.h>

using namespace std;

int solution(string begin, string target, vector<string> words) {
  auto n = words.size();
  auto len = begin.length();
  unordered_map<string, int> cnt;
  queue<string> q;

  q.push(begin);
  cnt[begin] = 0;

  while (!q.empty()) {
    auto w = q.front();
    q.pop();

    if (w == target)
      break;

    for (auto i = 0; i < words.size(); i++) {
      auto word = words[i];
      if (cnt.count(word))
        continue;
      int d = 0;
      assert(word.length() == len);
      for (int j = 0; j < len; j++)
        d += w[j] != word[j];
      if (d == 1) {
        cnt[word] = cnt[w] + 1;
        q.push(word);
      }
    }
  }

  return cnt[target];
}
