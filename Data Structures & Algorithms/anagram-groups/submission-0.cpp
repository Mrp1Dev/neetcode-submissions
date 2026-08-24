class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //unordered_map<int, unordered_map<char, int>> charCountsForSizes = {};
        vector<unordered_map<char, int>> charCounts(strs.size());
        for(int i = 0; i < strs.size(); i++){
            for (char c : strs[i]){
                charCounts[i][c] += 1;
            }
        }
        vector<vector<string>> result = {};
        unordered_set<int> seenStrings = {};
        for(int i = 0; i < strs.size(); i++){
            if(seenStrings.contains(i)) continue;
            vector<string> currentAnagramList = {};
            for(int j = i; j < strs.size(); j++){
                if(seenStrings.contains(j)) continue;
                if(charCounts[j] == charCounts[i]){
                    currentAnagramList.push_back(strs[j]);
                    seenStrings.insert(j);
                }
            }
            result.push_back(currentAnagramList);
        }

        return result;
    }
};
