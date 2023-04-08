#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(head!=NULL){
            curr=head;
            head=head->next;
            curr->next=prev;
            prev=curr;
        }
        
        return curr;
    }
    
    void merge(ListNode* l1, ListNode* l2){
        while(l1){
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
            
            l1->next=l2;
            
            if(l1_next){
                l2->next=l1_next;
                l1=l1_next;
                l2=l2_next;
            }else{
                break;
            }
        }
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        
//         split the list into two halves;;
//         head of first half
        ListNode* l1 = head;
//         head of second half
        ListNode* slow = head;
//         tail of second half
        ListNode* fast = head;
//         tail of first half
        ListNode* prev = NULL;
        
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev->next=NULL;
        
//         reverse the second half;;
//         head of second half after reversing
        ListNode* l2 = reverse(slow);
        
//         merge lists;;
        merge(l1, l2);
    }
};