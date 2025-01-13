//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) 
    {
        if(head==NULL)return NULL;
        Node* zerodummy= new Node(-1);
        Node* onedummy=new Node(-1);
        Node* twodummy=new Node(-1);
        Node* mover0=zerodummy;
        Node* mover1=onedummy;
        Node* mover2=twodummy;
        while(head!=NULL)
        {
            if(head->data==0)
            {
                mover0->next=head;
                mover0=head;
            }
            else if(head->data==1)
            {
                mover1->next=head;
                mover1=head;
            }
            else
            {
                mover2->next=head;
                mover2=head;
            }
            head=head->next;
        }
        if(onedummy->next)mover0->next=onedummy->next;
        if(onedummy->next && twodummy->next)mover1->next=twodummy->next;
        else if(twodummy->next)mover0->next=twodummy->next;
        if(twodummy->next)mover2->next=NULL;
        else if(onedummy->next)mover1->next=NULL;
        else mover0->next=NULL;
        return zerodummy->next;
        // Add code here
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends