//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int precedence(char op){
    	if(op=='^'){
    		return 3;
    	}
    	else if(op == '*' || op == '/'){
    		return 2;
    	}
    	else if(op == '+' || op == '-'){
    		return 1;
    	}
    	else
    		return -1;
    }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string ans = "";
    	stack<char> st;
    	for(int i=0; i<s.size(); i++){
    		char ch = s[i];
    
    		if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')){
    			ans += ch;
    		}
    		else if(ch == '('){
    			st.push(ch);
    		}
    		else if(ch == ')'){
    			while(!st.empty() && st.top()!='('){
    				ans += st.top();
    				st.pop();
    			}
    			if(!st.empty()){
    				st.pop();
    			}
    		}
    		else{
    			while(!st.empty() && precedence(ch) <= precedence(st.top())){
    				ans += st.top();
    				st.pop();
    			}
    			st.push(ch);
    		}
    	}
    
    	while(!st.empty()){
    		ans += st.top();
    		st.pop();
    	}
    
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends