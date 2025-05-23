//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
        void add(Node* head,int& cnt)
        {
            if(head->next==NULL)
            {
                int val=head->data;
                val=val+1;
                cnt=val/10;
                val=val%10;
                head->data=val;
                return;
            }
            add(head->next,cnt);
            if(cnt)
            {
                int val=head->data;
                val=val+cnt;
                cnt=val/10;
                val=val%10;
                head->data=val;
            }
        }
  public:
    Node* addOne(Node* head) {
        // Your Code here
        int cnt=0;
        if(head==NULL)return NULL;
        add(head,cnt);
        if(cnt)
        {
            Node* temp= new Node(cnt);
            temp->next=head;
            return temp;
        }
        return head;
        // return head of list after adding one
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends