ListNode* search_list(ListNode* head, element x)
{
    ListNode* p = head;

    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return NULL;
}