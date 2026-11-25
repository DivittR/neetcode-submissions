class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string c:tokens){
            if (c != "+" && c != "-" && c != "*" && c != "/") {
                int num=stoi(c);
                st.push(num);
            }else{
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(c=="+")st.push(a+b);
                else if(c=="-")st.push(a-b);
                else if(c=="*")st.push(a*b);
                else if(c=="/")st.push(a/b);
            }
        }
         return st.top();
    }
};
