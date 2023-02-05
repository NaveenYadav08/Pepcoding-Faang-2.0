https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

class Solution
{
    public:
    
Node* reverse( Node *head)
    {
        
        if(head==NULL)
            return NULL;
        
        //taking three pointers to store the current, previous and next nodes.
         Node *prev = NULL;   
         Node *current = head;
         Node *next= current->next;
        
        while(current!=NULL)
        {
            //taking the next node as next.
            next=current->next;
            
            //storing the previous node in link part of current node.
            current->next=prev; 
            
            //updating prev from previous node to current node.
            prev=current; 
            
            //updating current node to next node.
            current =next;        
        }
        
        return prev;
    }
    
    
Node *compute(Node *head)

    {

        // your code goes her

        head = reverse(head);
        int maxy = INT_MIN;
        Node* ans = new Node(0);
        Node* stored_ans = ans;
        
        Node* curr = head;
        while(curr!=NULL)
        {
            maxy = max(maxy,curr->data);
            if(maxy == curr->data)
            {
                ans->next = curr;
                ans = ans->next;
            }
            curr=curr->next;
        }
        ans->next = NULL;

        return reverse(stored_ans->next);
            

        }

       

    
    
};
