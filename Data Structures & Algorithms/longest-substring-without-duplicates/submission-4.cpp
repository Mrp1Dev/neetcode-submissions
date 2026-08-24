class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_set<char> chars{};
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        int longest = 0;
        while (r < s.size()) {
            chars.insert(s[r]);
            if (chars.contains(s[r + 1])) {
                int len = r - l + 1;
                chars.erase(s[l]);
                if(l==r) r++;
                l++;
                if (len > longest) longest = len;
            } else {
                r++;
            }
        }
        if (r - l > longest) longest = r - l;
        return longest;
    }
};
