//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    bool knows(vector<vector<int> >& M, int a, int b){
        int n = M.size();
        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //step 1 push all elements in stack
        stack<int> s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        //step 2
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(knows(M, a, b)){  //jo push kr rahe h vo potential candidates
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int candidate = s.top();    //potential candidate
        
        //step 3-> single element in stack is potential celeb
        //so verify it
        
        //row check
        bool rowCheck = false;
        int zeroCnt=0;
        for(int j=0; j<n; j++){
            if(M[candidate][j] == 0){
                zeroCnt++;  
            }
        }
        
        //all zeroes
        if(zeroCnt==n){
            rowCheck = true;
        }
        
        //col check
        bool columnCheck = false;
        int oneCnt = 0;
        for(int i=0; i<n; i++){
            if(M[i][candidate] == 1){
                oneCnt++;
            }
        }
        
        if(oneCnt == n-1){
            columnCheck = true;
        }
        
        if(rowCheck && columnCheck){
            return candidate;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends