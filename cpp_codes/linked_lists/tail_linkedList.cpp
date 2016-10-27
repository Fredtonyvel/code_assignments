/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(head != NULL)
    {
        temp->next = head;    
    }
    head = temp;
    
    return head;
}

