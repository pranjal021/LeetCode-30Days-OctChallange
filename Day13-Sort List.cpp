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
class Solution {
    public:
    
    ListNode* findMid(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* sort(ListNode* first,ListNode* second){
        
        if(first==NULL)return second;
        if(second==NULL)return first;
        
        ListNode* temp;
        
        if(first->val < second->val){
            temp = first;
            temp->next = sort(first->next,second);
        }else{
            temp = second;
            temp->next = sort(first,second->next);
        }
        
        return temp;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)return head;
        
        ListNode* mid = findMid(head);
        
        ListNode* second = sortList(mid->next); //second linkedList will start from node next to the mid node
        
        mid->next = NULL;
        ListNode* first = sortList(head);
        
        return sort(first,second);
    }
};