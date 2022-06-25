// link: https://www.interviewcake.com/question/cpp/kth-to-last-node-in-singly-linked-list?course=fc1&section=linked-lists
int listLength(LinkedListNode * head) {
    int length = 0;
    while (head) {
        ++length;
        head = head->next_;
    }
    
    return length;
}

LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head)
{
    // return the kth to last node in the linked list
    int listSize = listLength(head);
    
    if (listSize < k)
        throw new std::invalid_argument("k must not be greater than the size of the list");
    else if (k < 1)
        throw new std::invalid_argument("k must be greater than 0");
        
    else {
        for (int index = listSize - k; index > 0; --index) {
            head = head->next_;
        }
    }

    return head;
}