//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

//intution - first remove valid pairs by using logic of valid parenthesis
int countRev (string s)
{
    // your code here
    //if string is of odd length
    if(s.size() & 1){
        return -1;
    }
    
    //Minimum Number of Swaps to Make the String Balanced
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else{    //closing bracket
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    
    //now we remain with invalid pairs which requires swaps
    // {{ or }} requires 1 swap only, while }{ requires 2 swaps
    int cnt=0;
    while(!st.empty()){
        char second = st.top();
        st.pop();
        char first = st.top();
        st.pop();
        if((first=='{' && second=='{') || (first=='}' && second=='}')){
            cnt++;
        }
        else if((first=='}' && second=='{')){
            cnt = cnt+2;
        }
    }
    return cnt;
}