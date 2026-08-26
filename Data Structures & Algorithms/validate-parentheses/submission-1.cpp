class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> corresponding {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
        };
        for(char c : s){
            if(c == '(' || c=='{' || c== '['){
                brackets.push(c);
            } else{
                if(brackets.empty() == false && corresponding[brackets.top()] == c)
                    brackets.pop();
                else return false;
            }

        }
        return brackets.empty();
    }
};
