//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       int freq[26] = {0};
       queue<char> q;
       string ans = "";
       
       for(int i=0; i<S.length(); i++){
           char ch = S[i];
           
           //increment frequency
           freq[ch-'a']++;
           
           //q.push()
           q.push(ch);
           
           //find ans from front of queue
           while(!q.empty()){
               if(freq[q.front()-'a'] > 1){     //repeating char
                   q.pop();
               }
               else{
                   ans.push_back(q.front());
                   break;
               }
           }
           
           if(q.empty()){
               ans.push_back('$');
           }
       }
       return ans.back(); 
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends