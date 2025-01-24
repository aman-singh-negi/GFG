//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    void find(Node* root,int x,int* ans)
    {
        if(root==NULL)return;
        else if(root->data>x)
        {
            find(root->left,x,ans);
        }
        else if(root->data<x)
        {
            *ans=root->data;
            find(root->right,x,ans);
        }
        else
        {
            *ans=root->data;
        }
    }
    int floor(Node* root, int x) 
    {
        // Code here
        int ans=-1;
        find(root,x,&ans);
        return ans;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends