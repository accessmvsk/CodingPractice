/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head, bool print)
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
        // print elment in left node if we are asked to print
        if (print) {
            std::cout<<left->data<<std::endl;
        }
        // save right's next element
        rightNext = right->next;
        // point right's next now to left (reverse the link)
        right->next = left;
        // update left node to right node
        left = right;
        // update right node to right's next node
        right = rightNext;
    }
    // print elment in left node if we are asked to print
    // this print is for 1 node list or the list's last element (loop breaks without printing it)
    if (print) {
        std::cout<<left->data<<std::endl;
    }
    // make sure we terminate the list by pointing old head's next to null
    head->next = NULL;
    // point head to the right most node (new start of list after reversing)
    head = left;
    return head;
}

void ReversePrint(Node *head)
{
    // quickly return if list is empty
    if (!head) {
        return;
    }
    // logic is to Reverse the list, print elements and reverse it again.
    // reverse list once without printing
    head = Reverse(head, false);
    // reverse list again, priting elements this time
    // so that we print the reversed list along with it reversing it again (ie- un-reversing it )
    head = Reverse(head, true);
}
