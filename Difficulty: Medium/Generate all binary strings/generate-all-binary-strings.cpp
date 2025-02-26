//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    void f(vector<string>&ans,string s,int n)
    {
        if(n==0)
        {
            ans.push_back(s);
            return;
        }
        if(s.back()=='0')
        {
            string s1=s;
            s1.push_back('0');
            string s2=s;
            s2.push_back('1');
            f(ans,s1,n-1);
            f(ans,s2,n-1);
        }
        else if(s.back()=='1')
        {
            s.push_back('0');
            f(ans,s,n-1);
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        string s1="0";
        string s2="1";
        vector<string>ans;
        f(ans,s1,num-1);
        f(ans,s2,num-1);
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends