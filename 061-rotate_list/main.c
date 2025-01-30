#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addList(struct ListNode* list, int k) {
    if(list == NULL) {
        list = malloc(sizeof(struct ListNode));
        list->val = k;
        list->next = NULL;
        return list;
    }

    struct ListNode *head = list;
    while(list->next) {
        list = list->next;
    }
    list->next = malloc(sizeof(struct ListNode));
    list->next->val = k;
    list->next->next = NULL;
    return head;
}


void printList(struct ListNode* list) {
    printf("--------------------\n");
    while(list) {
        printf("[%p] %d\n", list, list->val);
        list = list->next;
    }
    printf("--------------------\n");
}


struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL) {
        return NULL;
    }
    if(k == 0) {
        return head;
    }
    int n = 0;
    struct ListNode *ptr = head;
    while(k--) {
        if(ptr->next == NULL) {
            ptr = head;
            ++n;
            return rotateRight(head, k % n);
        }
        else {
            ptr = ptr->next;
            ++n;
        }
    }

    struct ListNode *late = head;

    while(ptr->next) {
        ptr = ptr->next;
        late = late->next;
    }

    ptr->next = head;
    head = late ? late->next : head;
    if(late) {
        late->next = NULL;
    }

    return head;
}

// l       p
//           l       p
// 1 2 3 4 5 6 7 8 9 0
// 0 1 2 3 4 5 6 7 8 9
// 9 0 1 2 3 4 5 6 7 8
// 8 9 0 1 2 3 4 5 6 7
// 7 8 9 0 1 2 3 4 5 6

// 1 2 3
// 3 1 2
// 2 3 1

int main(int argc, char const *argv[]) {
    struct ListNode* list = addList(NULL, 1);
    addList(list, 2);
    addList(list, 3);
    // addList(list, 4);
    // addList(list, 5);
    // addList(list, 6);
    // addList(list, 7);
    // addList(list, 8);
    // addList(list, 9);
    // addList(list, 0);

    printList(list);

    list = rotateRight(list, 2000000000);

    printList(list);

    return 0;
}
