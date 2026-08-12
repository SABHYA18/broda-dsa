class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // if(tokens.size()==1 && (tokens[0]!="+" || tokens[0]!="-" || tokens[0]!="/" || tokens[0]!="*")) return tokens[0];

        stack<string> st;

        for(string s: tokens){
            int a,b;
            if(s=="+") {
                a = stoi(st.top());
                st.pop();
                b = stoi(st.top());
                st.pop();
                st.push(to_string(a+b));
            }
            else if(s=="*"){
                a = stoi(st.top());
                st.pop();
                b = stoi(st.top());
                st.pop();
                st.push(to_string(a*b));
            }
            else if(s=="-") {
                a = stoi(st.top());
                st.pop();
                b = stoi(st.top());
                st.pop();
                st.push(to_string(b-a));
            }
            else if(s=="/"){
                a = stoi(st.top());
                st.pop();
                b = stoi(st.top());
                st.pop();
                st.push(to_string(b/a));
            }
            else st.push(s);
           
        }
        return stoi(st.top());
    }
};
