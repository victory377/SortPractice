/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* selecttionSortList(struct ListNode* head) {
    struct ListNode *ptr,*search,*index;
    int tmp;
    ptr = head;
    
    while(ptr != NULL){
        search = ptr;
        index = search;
        while(search != NULL){
            if(search->val < index->val)
                index = search;
            search = search->next;
        }
        tmp = index->val;
        index->val = ptr->val;
        ptr->val = tmp;
        ptr = ptr->next;
    }
    return head;
}