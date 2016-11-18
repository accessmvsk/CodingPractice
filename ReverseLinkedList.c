/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    // check for NULL case
    if (!head) {
        return head;
    }
    // take two pointers left and right
    // left is the first node of the list, starting from head
    Node *left = head;
    // right is the next node of left
    Node *right = head->next;
    // rightNext is the next node of right
    Node *rightNext = NULL;
    while (right)
    {
        // save right's next element
        rightNext = right->next;
        // point right's next now to left (reverse the link)
        right->next = left;
        // update left node to right node
        left = right;
        // update right node to right's next node
        right = rightNext;
    }
    // make sure we terminate the list by pointing old head's next to null
    head->next = NULL;
    // point head to the right most node (new start of list after reversing)
    head = left;
    return head;
}
