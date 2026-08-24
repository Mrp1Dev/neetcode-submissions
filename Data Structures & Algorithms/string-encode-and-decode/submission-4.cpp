class Solution {
public:
    string encode(vector<string>& strs) {
        string result = {};
        vector<int> lengths = {};

        for(int i = 0; i < strs.size(); i++){
            lengths.push_back(strs[i].size());
        }
        if(lengths.size()/10 == 0) result += "0";
        
        result+= to_string(lengths.size());
        for(int i = 0; i < lengths.size(); i++){
            if(lengths[i]/10 == 0) result += "0";
            if(lengths[i]/100 == 0) result += "0";
            result += to_string(lengths[i]);
        }
        for(int i = 0; i < strs.size(); i++){
            result += strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result = {};
        
        int stringCount = (s[0]-'0') * 10 + (s[1]-'0');
        if (stringCount == 0) return result;
        int currentString = 0;
        
        for(int i = 0; i < s.size(); i++){
            int len = (s[2 + currentString]-'0') * 100 + (s[2 + currentString + 1]-'0') * 10 + (s[2 + currentString + 2] - '0');
            result.push_back(s.substr(2 + stringCount*3 + i, len));
            i += len-1;
            currentString+= 3;
            if(currentString/3 >= stringCount) break;
        }
        return result;
    }
};
