/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode ret;
    struct ListNode *tmp = &ret;
    int sum_w_carry = 0;

    do {
        if(l1) {
            sum_w_carry += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            sum_w_carry += l2->val;
            l2 = l2->next;
        }

        tmp->next = malloc(sizeof(struct ListNode));
        tmp->next->next = NULL;
        tmp = tmp->next;

        tmp->val = sum_w_carry % 10;
        sum_w_carry = sum_w_carry / 10;
    }while(l1 || l2);

    if(sum_w_carry > 0) {
        tmp->next = malloc(sizeof(struct ListNode));
        tmp->next->val = sum_w_carry;
        tmp->next->next = NULL;
    }

    return ret.next;
}

int main(int argc, char const *argv[]) {
    // int a1[] = {9,9,9,9,9,9,9}; int a1sz = 7;
    // int a2[] = {9,9,9,9}; int a2sz = 4;
    int a1[] = {2,4,3}; int a1sz = 3;
    int a2[] = {5,6,4}; int a2sz = 3;

    // int a1sz = 1000000, a2sz = 1000000;
    // int *a1 = malloc(a1sz * sizeof(int));
    // int *a2 = malloc(a2sz * sizeof(int));
    // while(a1sz || a2sz) {
    //     if(a1sz) {
    //         a1[a1sz - 1] = rand() % 10;
    //     }
    //     if(a2sz) {
    //         a2[a2sz - 1] = rand() % 10;
    //     }
    //     --a1sz;
    //     --a2sz;
    // }
    // for(int i = 0; i < a1sz; ++i) {
    //     a1[i] = rand() % 10;
    //     a2[i] = rand() % 10;
    // }

    struct ListNode* l1 = malloc(sizeof(struct ListNode)), *tmp;
    tmp = l1;
    int i = 0;
    while(1) {
        tmp->val = a1[i];
        if(++i >= a1sz) break;
        else {
            tmp->next = malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;

    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    tmp = l2;
    i = 0;
    while(1) {
        tmp->val = a2[i];
        if(++i >= a2sz) break;
        else {
            tmp->next = malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;

struct timespec tstart = {0, 0}, tend = {0, 0};
clock_gettime(CLOCK_MONOTONIC, &tstart);

    struct ListNode* res = addTwoNumbers(l1, l2);

clock_gettime(CLOCK_MONOTONIC, &tend);
printf("operation took about %f seconds\n", ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec));

    while(res) {
        printf("%d", res->val);
        res = res->next;
    }
    printf("\n");

    return 0;
}
