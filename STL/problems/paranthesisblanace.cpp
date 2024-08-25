#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool b=true;
        unordered_map<char, int> symbols = {{'[', 1}, {'(', 2}, {'{', 3}, {']', -1}, {')', -2}, {'}', -3}};
        for(int i=0; i<s.size(); i++){
            if(symbols[s[i]]>0){
                st.push(s[i]);
            }
        else
            {
                if (st.empty())
                {
                    b=false;
                    break;
                }
                
                if(symbols[s[i]]+symbols[st.top()] !=0){
                    b=false;
                    break;
                }
                else{
                    st.pop();
                }
            }
            
        }
        return b && st.empty();
    }
};

int main(){
    string str;
    cin >> str;
    Solution sol;
    cout << sol.isValid(str);
}