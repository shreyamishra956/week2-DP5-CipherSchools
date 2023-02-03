#include <bits/stdc++.h> 


stack<int> pushAtBottom(stack<int>& st, int x) 
{
    int num = st.top();
    st.pop();
    if(st.size() > 0)
        pushAtBottom(st, x);
    else
        st.push(x);
    st.push(num);
    return st;
}

int main()
{

}