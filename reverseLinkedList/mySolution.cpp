LinkedListNode* reverse(LinkedListNode* headOfList)
{
    // reverse the linked list in place
    if (!headOfList || !headOfList->next_) 
        return headOfList;
    
    LinkedListNode * swapFrom = headOfList,
                   * swapTo = nullptr;
                   
    while (swapFrom->next_) {
        swapTo = swapFrom->next_;
        swapFrom->next_ = swapTo->next_;
        swapTo->next_ = headOfList;
        headOfList = swapTo;
    }

    return headOfList;
}
