https://leetcode.com/problems/split-linked-list-in-parts/description/



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int size=0;
        vector<ListNode*> ans(k,NULL);

        if(head==NULL)
        return ans;

        ListNode* curr=head;
        while(curr!=NULL)
        {
            ++size;
            curr=curr->next;
        }

        int SIZE = size/k;

        int REM = size%k;


        curr=head;
        for(int i=0;i<k;i++)
        {  ListNode* temp = curr;
           for(int j=1;curr!=NULL and j<SIZE+(REM>0?1:0); j++)
           {
               curr=curr->next;
           }
 
           ListNode* prv = curr;
           if(curr!=NULL)
           curr=curr->next;
           if(prv!=NULL)
           prv->next=NULL;
           REM--;
           ans[i]=temp;
        }


        
        
        return ans;


        
    }
};
