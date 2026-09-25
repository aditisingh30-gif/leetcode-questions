class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // If it is an opening bracket, push it to the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If it's a closing bracket, check if stack is empty
                if (st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                // Check for matching pairs
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
