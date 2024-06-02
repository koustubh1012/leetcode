class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> s1;
        for (int i = 0; i < s.length(); i++){
            char current = s[i];
            if (current == '(' || current == '[' || current == '{') {
                s1.push(current);
            } else {
                if (s1.empty()){
                    return false;
                }
                char top = s1.top();
                if ((current == ')' && top == '(') || 
                    (current == ']' && top == '[') || 
                    (current == '}' && top == '{')) {
                    s1.pop();
                } else {
                    return false;
                }
            }
        }
        return s1.empty();
    }
};
