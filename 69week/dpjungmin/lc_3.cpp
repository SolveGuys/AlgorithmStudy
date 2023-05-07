class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int l = 0, r = 0;

    // seen_at[i] = last index of the character `i` in `s` that we have seen
    unordered_map<char, int> seen_at;

    while (r < s.length()) {
      if (seen_at.count(s[r]))
        l = max(l, seen_at[s[r]] + 1);

      ans = max(ans, r - l + 1);
      seen_at[s[r]] = r;
      r++;
    }

    return ans;
  }
};
