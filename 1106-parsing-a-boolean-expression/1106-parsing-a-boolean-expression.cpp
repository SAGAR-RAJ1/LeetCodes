class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char>st;

        for(auto &a:expression){

            if(a!=',' && a!=')'){
                st.push(a);
                continue;
            }else if(a==','){
                continue;
            }
             bool hastrue = false;
             bool hasfalse = false;
            if(a==')'){
                while(!st.empty() && st.top()!='('){
                    if(st.top()=='t')hastrue=true;
                    if(st.top()=='f')hasfalse=true;
                    st.pop();
                }
                st.pop();
            }

            char op = st.top();
            st.pop();
            bool result;
            if(op=='!'){
               if(hastrue)result = false;
               if(hasfalse)result = true;
            }
            if(op=='|'){
                if(hastrue)result = true;
                else result = false;
            }
            if(op=='&'){
                if(hasfalse)result = false;
                else result = true;
            }
           st.push(result ? 't' : 'f');

        }
        return (st.top()=='t'?true:false);
    }
};