https://leetcode.com/problems/reorder-list/

//ALGORITHMS
put all the node in stack for rev order
traverse till list_size/2 + 1
        


//CODE

class Solution {
public:
void reorderList(ListNode* head) {
        stack<ListNode *> s;
        ListNode* p = head;
        while(p){
            s.push(p);
            p = p->next;
        }
        int num_nodes = s.size();
        while(s.size() > num_nodes / 2 + 1){
            ListNode * temp = head->next;
            head->next = s.top();
            s.top()->next = temp;
            head = temp;
            s.pop();
        }
        s.top()->next = NULL;
    }
};


// INPLACE 


class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL)
        return head;

        ListNode* second = head->next;
        head->next = NULL;
        ListNode* rev = reverseList(second);
        second->next=head;
        return rev;
    }



    void reorderList(ListNode* head) {
         if(head==NULL or head->next==NULL)
         return;

         ListNode* mid = middleNode(head);
       

         ListNode* REV = reverseList(mid);

         ListNode* curr = head;
         ListNode* tmp = REV;

         ListNode* savedcurrnxt=head->next;
         ListNode* savedtmpnxt=REV->next;

         while(tmp->next!=NULL)
         {
             savedcurrnxt = curr->next;
             curr->next = tmp;
             savedtmpnxt = tmp->next;
             tmp->next = savedcurrnxt;
             curr=savedcurrnxt;
             tmp=savedtmpnxt;
         }

         
    }
};
