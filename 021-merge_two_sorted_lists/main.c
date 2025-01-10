#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addNode(struct ListNode* head, int val) {
    if(head == NULL) {
        head = malloc(sizeof(struct ListNode));
        head->val = val;
        head->next = NULL;
        return head;
    }
    while(head->next) {
        head = head->next;
    }
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = val;
    head->next->next = NULL;
}


void printList(struct ListNode* head) {
    while(head) {
        printf("[%p] %d\n", head, head->val);
        head = head->next;
    }
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


int main(int argc, char const *argv[]) {
    struct ListNode *list1 = addNode(NULL, -10);
    addNode(list1, -10);
    addNode(list1, -9);
    addNode(list1, -4);
    addNode(list1, 1);
    addNode(list1, 6);
    addNode(list1, 6);
    // addNode(list1, 2);
    // addNode(list1, 4);
    printList(list1);

    printf("\n");

    struct ListNode *list2 = addNode(NULL, -7);
    // addNode(list2, 3);
    // addNode(list2, 4);
    printList(list2);
    printf("\n");


    struct ListNode *merged = mergeTwoLists(list1, list2);
    printList(merged);

    return 0;
}
