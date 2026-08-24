class Solution {
public:

    bool isAlphaNumeric(char c){
        if(c - 'A' <= 25 && c - 'A' >= 0) return true;
        if(c - 'a' <= 25 && c - 'a' >= 0) return true;
        if(c - '0' <= 9 && c - '0' >= 0) return true;
        return false;
    }

    char toLower(char c){
        if(c - 'a' <= 25 && c - 'a' >= 0) return c;
        return (c - 'A') + 'a';
    }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        for(int i = 0; i < s.size()/2; i++){
            while(isAlphaNumeric(s[l]) == false && l < s.size() - 1)
                l++;
            while(isAlphaNumeric(s[r]) == false && r > 0)
                r--;
            if((isAlphaNumeric(s[l]) && isAlphaNumeric(s[r])) == false) return true;
            if(toLower(s[l]) != toLower(s[r])){
                cout << s[l] << ' ' << s[r] << '\n';
                return false;
            }
                
            l++;
            r--;
        }
        return true;
    }
};
