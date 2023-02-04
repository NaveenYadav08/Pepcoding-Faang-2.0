https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1




SOLUTION 

// your task is to complete this function
// void sort(Node **head)
// {
//      // Code here
//      stack<Node* > S;
//      if(*head==NULL or (*head)->next==NULL)
//      return;
     
//      Node* traverse = (*head)->next;  // point to 9
//      while( traverse!=NULL )
//      {
//          S.push(traverse); // 9 8 7
//          if(traverse->next==NULL or (traverse)->next->next==NULL)
//          break;

         
//          traverse = (traverse)->next->next; // point to 7
//      }
     

     
//      traverse = *head; // point to head 
     
//       while(traverse!=NULL)
//      {
         
//          if(traverse->next==NULL or (traverse)->next->next==NULL)
//          break;
         
//          traverse->next = (traverse)->next->next;
//          traverse = (traverse)->next;
//      }
     
//      while(!S.empty())
//      {
//          traverse->next = S.top();
//          S.pop();
//          traverse= (traverse)->next;
//      }
//      traverse->next = NULL;
     
     
     
//      return;
     
// }

// SOLUTION AT GFG 
void reverselist(Node *&head)
{
	Node* prev = NULL, *curr = head, *next;
	
	while (curr)
	{
		next = curr->next;   // storing value for next node
		curr->next = prev;   // linking node to previous node
		prev = curr;         // updating value of prev node
		curr = next;         // updating value of current node
	}
	head = prev;
}

Node *mergelist(Node *head1, Node *head2)
{
	if (!head1) return head2;  // base cases
	if (!head2) return head1;  // base cases
	
	Node *temp = NULL;
	
	if (head1->data < head2->data)
	{
		temp = head1;     // picking the lower value
		head1->next = mergelist(head1->next, head2);
		// recursively merging the remaining list
	}
	else
	{
		temp = head2;     // picking the lower value
		head2->next = mergelist(head1, head2->next);
		// recursively merging the remaining list
	}
	return temp;
}

void splitList(Node *head, Node **Ahead, Node **Dhead)
{
	*Ahead = new Node(0);
	    // first node for the list (will be discarded later)
	*Dhead = new Node(0);
	    // first node for the list (will be discarded later)
	
	Node *ascn = *Ahead;
	Node *dscn = *Dhead;
	Node *curr = head;
	
	while (curr)
	{
	    // first element goes to ascending list
		ascn->next = curr;
		ascn = ascn->next;
		curr = curr->next;
		
		if (curr)
		{
		    // second element goes to descending list
			dscn->next = curr;
			dscn = dscn->next;
			curr = curr->next;
		}
	}
	ascn->next = NULL;
	dscn->next = NULL;
	
	*Ahead = (*Ahead)->next;   // discarding first element
	*Dhead = (*Dhead)->next;   // discarding first element
}

void sort(Node **head)
{
	Node *Ahead, *Dhead;
	splitList(*head, &Ahead, &Dhead);
	// function to split the list
	// Ahead stores the elements with even index (0,2,4...)
	// Dhead stores elements with odd index
	
	reverselist(Dhead);
	// reversing list with head Dhead since it contains
	// elements in decreasing order
	
	*head = mergelist(Ahead, Dhead);
	// merging back both lists in increasing order
}




// bubble sort n2

//  // 1->9->2->8->3->7
// void sort(Node **head)
// {
    
//     // Code here
//     Node* ptr1 = *head ;  //Pointer that moves one at a time        // 1
//     Node* ptr2 = (*head)->next ; //Pointer that runs from ptr1 to end to sort  // 9
    
//     while(ptr2!=NULL || ptr1->next!=NULL){  //if ptr2!=NULL or ptr1->next!=NULL
        
//         if(ptr1->data > ptr2->data){ 
//             int temp = ptr1->data ;  // swap the values if ptr1 is less than ptr2
//             ptr1->data = ptr2->data ; 
//             ptr2->data = temp ;
//         }
        
//         ptr2= ptr2->next;
//         if(ptr2==NULL){ // If ptr2 reaches NULL, increment ptr1 and put ptr2 next to ptr1
//             ptr1 = ptr1->next ;
//             ptr2 = ptr1->next;
//         }
//     }
// }
