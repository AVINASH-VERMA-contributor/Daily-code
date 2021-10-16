#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^')
    return 3;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;    
    
}

void infixToPostfix(string s){
stack<char> st;
string result;

for(int i=0;i<s.length();i++){
    char c=s[i];

    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>'0' && c<'9')){
        result+=c;
    }
    else if(c=='('){
        st.push('(');
    }
    else if(c==')'){
        while(st.top() != '('){
            result+=st.top();
            st.pop();
        }
        st.pop();
    }
    else{
        while(!st.empty() && prec(s[i])<=prec(st.top())){
            result +=st.top();
            st.pop();
        }
        st.push(c);
    }

}

    while(!st.empty()){
result+=st.top();
st.pop();
    }

reverse(result.begin(),result.end());
cout<<result<<endl;

}

void infixToPrefix(string infix)
{
    
    int l = infix.size();
 
    reverse(infix.begin(), infix.end());
 
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
 
    infixToPostfix(infix);
  
}
 


int main(){
    string s= "a+b";
    infixToPrefix(s);
    return 0;
}