#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* tmp = head;
    struct ListNode* headt = head;
    struct ListNode* prev;

    while(tmp->next && --n) {
        tmp = tmp->next;
    }

    while(tmp->next) {
        prev = headt;
        headt = headt->next;
        tmp = tmp->next;
    }

    if(prev == NULL) {
        tmp = headt->next;
        free(headt);
        return tmp;
    }

    prev->next = headt->next;
    free(headt);

    return head;
}

int main(int argc, char const *argv[]) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *tmp = head;
    int i;
    for(i = 1; i < 9; ++i) {
        tmp->val = i;
        tmp->next = malloc(sizeof(struct ListNode));
        tmp = tmp->next;
    }
    tmp->val = i;
    tmp->next = NULL;

    head = removeNthFromEnd(head, 2);

    while(head) {
        printf("%d, ", head->val);
        head = head->next;
    }
    printf("\n");

    return 0;
}
