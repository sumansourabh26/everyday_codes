#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<string> st;

    st.push("suman");
    st.push(" is good ");
    st.push("boy");

    cout<<st.top();
    st.pop();
    cout<<st.top();
}
