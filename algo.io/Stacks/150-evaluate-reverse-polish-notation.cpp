class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // initlaise stack
        stack<int> stk;

        // declare answer variable
        int ans;

        // loop to go through each string
        for(string c : tokens){
            // if there is an operand, pop two values and perform operation
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(c == "+") ans = a + b;
                else if(c == "-") ans = a - b;
                else if(c == "*") ans = a * b;
                else if(c == "/") ans = a / b;
                stk.push(ans);
            }
            // is it is a number, push it to the stack
            else{
                stk.push(stoi(c));
            }
        }
        return stk.top();
    }
};
