//FIRST APPROACH

class Solution {
    
    int length(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    
public:
    
    ListNode* rotateList(ListNode* head,int k){
        ListNode* fast=head;
        ListNode* slow = head;
        ListNode* newHead = NULL;
        
        while(k--){
            fast=fast->next;
        }
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        //after this while loop, slow->next will point to newHead;
        //and fast pointer will be on last node
        newHead = slow->next;
        slow->next=NULL;
        fast->next=head;
        return newHead;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)return NULL;
        int len = length(head);
        
        k = k%len; //so that value of "k" can be adjusted
        
        if(k==0 || k==len)return head;
        
        ListNode* ans = rotateList(head,k);
        
        return ans;
    }
};

//SECOND APPROACH

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if(head==NULL)return NULL;

		ListNode* temp = head;

		int len=0;
		//len will store the length of LL;
		while(temp){
			len++;
			temp=temp->next;
		}


		k = k%len;
		if(k==0)return head;

		int kfront = len - (k+1);

		temp=head;

		while(kfront--){
			temp=temp->next;
		}

		ListNode* newHead = temp->next;
		temp->next=NULL;

		ListNode* tmp=newHead;

		while(tmp->next){
			tmp=tmp->next;
		}

		tmp->next = head;

		return newHead;     
	}

};