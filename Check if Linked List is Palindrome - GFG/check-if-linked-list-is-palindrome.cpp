//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome( struct Node *head)
    {
        if(head == NULL ||head->next == NULL){
            return true;
        }
        Node* slow=head;
        Node* fast=head;
        //find middle of linkedlist
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        //reverse the right half
        slow->next=reverselist(slow->next);
        
        //move slow to right half
        slow=slow->next;
        
        //now check left half and right half are equal or not
        while(slow!=NULL){
            
            if(head->data!=slow->data)
            return false;
            head=head->next;
            slow=slow->next;
            
            }
            return true;
        
    }
    Node* reverselist (Node* head){
        Node* prev=NULL;
        Node* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
            
        }
        return prev;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends