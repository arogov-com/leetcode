#include <stdio.h>
#include <stdlib.h>


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


struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL) {
        return NULL;
    }
    if(head->next == NULL) {
        return head;
    }

    struct ListNode *head_new = head->next;
    struct ListNode *prev = NULL;

    while(head) {
        if(head->next == NULL) {
            break;
        }

        struct ListNode *right = head->next;

        head->next = right->next;
        right->next = head;

        if(prev) {
            prev->next = right;
        }

        prev = head;
        head = head->next;

    }

    return head_new;
}


int main(int argc, char const *argv[]) {
    struct ListNode *list1 = addNode(NULL, 1);
    addNode(list1, 2);
    addNode(list1, 3);
    addNode(list1, 4);
    // addNode(list1, 5);
    printList(list1);
    printf("\n");

    list1 = swapPairs(list1);

    printList(list1);

    return 0;
}
