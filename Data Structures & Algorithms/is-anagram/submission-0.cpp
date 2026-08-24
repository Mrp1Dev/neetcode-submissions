class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charCountsS = {};
        unordered_map<char, int> charCountsT = {};
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            if(charCountsS.contains(s[i]))
                charCountsS[s[i]] += 1;
            else
                charCountsS[s[i]] = 1;
        }

        for(int i =0; i < t.size(); i++){
            if(charCountsT.contains(t[i]))
                charCountsT[t[i]] += 1;
            else
                charCountsT[t[i]] = 1;
        }

        return charCountsS == charCountsT;
    }
};
