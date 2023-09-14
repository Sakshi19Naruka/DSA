//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int n, long long int k) {
    vector<long long> ans;
        queue<long long> q;
        
        //process first window of size k
        for(int i=0; i<k; i++){
            if(A[i] < 0){
                q.push(i);
            }
        }
        
        //remaining window ko process
        for(int i=k; i<n; i++){
            //first find answer of prev window
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(A[q.front()]);
            }
            
            //out of current window k elements ko remove krdo deque se ******most important
            while((!q.empty()) && (i-q.front() >= k)){
                q.pop();
            }
            
            
            //check current element for insertion
            if(A[i]<0){
                q.push(i);
            }
        }
        
        
        //print ans for last window, bcoz acc to written logic hm phle prev window ans find krte then curr window ko process krte
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(A[q.front()]);
        }
        return ans;
 }