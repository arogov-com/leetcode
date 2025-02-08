#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addNode(struct ListNode* head, int val) {
    struct ListNode *ptr = head;
    if(ptr == NULL) {
        ptr = malloc(sizeof(struct ListNode));
        ptr->val = val;
        ptr->next = NULL;
        return ptr;
    }

    while(ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = malloc(sizeof(struct ListNode));
    ptr->next->val = val;
    ptr->next->next = NULL;

    return head;
}


void printList(struct ListNode* head) {
    while(head) {
        printf("[%p] %d\n", head, head->val);
        head = head->next;
    }
    printf("\n");
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 == NULL) {
        return NULL;
    }
    if(list1 == NULL) {
        return list2;
    }
    if(list2 == NULL) {
        return list1;
    }

    if(list2->val > list1->val) {
        void *tmp = list1;
        list1 = list2;
        list2 = tmp;
    }
    struct ListNode *head = list2;

    struct ListNode *prev;
    while(list1 && list2) {
        if(list1->val >= list2->val) {
            prev = list2;
            list2 = list2->next;
        }
        else {
            struct ListNode *tmp1 = list1->next;

            prev->next = list1;
            list1->next = list2;
            prev = list1;
            list1 = tmp1;
        }
    }
    if(list1 != NULL) {
        prev->next = list1;
    }

    return head;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(lists == NULL) {
        return NULL;
    }
    if(listsSize == 0) {
        return NULL;
    }

    int left;
    int right = listsSize - 1;
    while(right > 0) {
        left = 0;
        while(left < right) {
            lists[left] = mergeTwoLists(lists[left], lists[right]);
            ++left;
            --right;
        }
    }
    return lists[0];
}

int main(int argc, char const *argv[]) {
    int listsSize = 3;
    struct ListNode **lists = malloc(sizeof(struct ListNode*) * listsSize);

    lists[0] = addNode(NULL, 1);
    addNode(lists[0], 4);
    addNode(lists[0], 5);

    lists[1] = addNode(NULL, 1);
    addNode(lists[1], 3);
    addNode(lists[1], 4);

    lists[2] = addNode(NULL, 2);
    addNode(lists[2], 6);

    for(int i = 0; i < listsSize; ++i) {
        printList(lists[i]);
    }

    struct ListNode* merged = mergeKLists(lists, listsSize);

    printList(merged);

    return 0;
}
