/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    // PS: we are not worrying about free()'ing the deleted nodes for now.
    // this is a quick and easy routine to de-dup the linked list
    // keep looping, skip elements if they are same.
    // stop if an unique element is found:
    //         Update the next of current to the unique element.
    
    // previous node - tracks the previous unique node
    Node *previousNode = head;
    // current node - tracks the current node - could be a dup node or unique node
    Node *currentNode = head;
    for(; (currentNode); (currentNode = currentNode->next)) {
        // if there is no next element, update previous node and return
        if (!(currentNode->next)) {
            previousNode->next = currentNode->next;
            break;
        }
        // skip if the next node has a duplicate value
        if ((currentNode->next)->data == (currentNode->data)){
            continue;
        } else {
            // if unique node found, update previousNode next to it
            previousNode->next = currentNode->next;
            // currentNode->next become previousNode now
            previousNode = currentNode->next;
        }
    }
    return head;
}
