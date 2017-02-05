/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* bubbleSortList(struct ListNode* head) {
    struct ListNode *ptr,*search,*index;
    int tmp;
    ptr = head;
    search = head;
    
    while(ptr != NULL){
        search = head;
        while(search->next != NULL){
            if(search->val > search->next->val){
                tmp = search->val;
                search->val = search->next->val;
                search->next->val = tmp;
            }
            search = search->next;
        }
        ptr = ptr->next;
    }
    return head;
}