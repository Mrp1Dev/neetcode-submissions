class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //unordered_map<int, unordered_map<char, int>> charCountsForSizes = {};
        map<map<char, int>, int> resultIndices = {};
        vector<vector<string>> result = {};
        for(int i = 0; i < strs.size(); i++){
            map<char, int> charCounts = {};
            for (char c : strs[i]){
                charCounts[c] += 1;
            }
            if(auto existingMap = resultIndices.find(charCounts);
                existingMap != resultIndices.end()){
                result[existingMap->second].push_back(strs[i]);
            } else {
                result.push_back({strs[i]});
                resultIndices[charCounts] = result.size() - 1;
            }
        }
        return result;
    }
};
