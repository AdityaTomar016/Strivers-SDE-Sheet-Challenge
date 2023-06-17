class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == ')'){
                if(!st.empty()){
                    if(st.top() != '(') return false;
                    else st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '}'){
                if(!st.empty()){
                    if(st.top() != '{') return false;
                    else st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == ']'){
                if(!st.empty()){
                    if(st.top() != '[') return false;
                    else st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        
        return st.empty();
    }
};
