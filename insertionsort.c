/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *ptr,*search,*tHead,*tmp;
    if(!head) return head;
    else{
        ptr = head;
        search = ptr->next;
        ptr->next = NULL;
        tHead = ptr;}
    
    while(search != NULL){
        ptr = tHead;
        while(ptr != NULL){
             if(search->val > ptr->val){
                 if(ptr->next != NULL){     //Middle
                     if(ptr->next->val >= search->val){
                        tmp = search->next;
                        search->next = ptr->next;
                        ptr->next = search;
                        search = tmp;
                        break;
                     }
                     else
                         ptr = ptr->next;
                 }
                 else{ //MAX
                     tmp = search ->next;
                     search->next =NULL;
                     ptr->next = search;
                     search = tmp;
                     break;
                 }
             }
             else{ //MIN
                tmp = search->next;
                search->next = ptr;
                ptr = search;
                tHead = ptr;
                search = tmp; 
                break;
             }
        }
    }
    ptr = tHead;
    return ptr;
}