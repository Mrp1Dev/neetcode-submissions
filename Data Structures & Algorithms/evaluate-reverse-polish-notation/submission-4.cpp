class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        
        for(const string& t : tokens){
            if(isdigit(t[t.size() - 1])){
                vals.push(stoi(t));
            } else{
                int b = vals.top();
                vals.pop();
                int a = vals.top();
                vals.pop();
                int result;
                switch (t[0]){
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        result = a / b;
                        break;    
                
                }

                vals.push(result);
            }            
        }
        return vals.top();
    }
};
