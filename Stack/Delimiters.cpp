#include "Stack-Linked-List-Based/Stack_list.h"
#include "string"

using namespace std;

bool valid(string s){
    Stack_list<char>st;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='('||s[i]=='['||s[i]=='{') {
            st.push(s[i]);
        }
        else if(s[i]=='/'&&i+1<s.size()&&s[i+1]=='*') {
            st.push(s[i]);
        }
        else if(s[i]=='}') {
            if(st.peek()=='}')
                st.pop();
            else
                return false;
        }
        else if(s[i]==')') {
            if(st.peek()=='(')
                st.pop();
            else
                return false;
        }
        else if(s[i]==']') {
            if(st.peek()=='[')
                st.pop();
            else
                return false;
        }
        else if(s[i]=='*'&&i+1<s.size()&&s[i+1]=='/') {
            if(st.peek()=='/')
                st.pop();
            else
                return false;
        }


    }
    if(!st.isEmpty())
        return false;
    else
        return true;
}