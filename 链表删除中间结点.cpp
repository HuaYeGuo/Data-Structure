#include "bits/stdc++.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {

        //将next结点的值 赋值给 当前结点
        node->val = node->next->val;

        //干掉next结点
        ListNode* tmp = node->next;
        node->next = node->next->next;
        delete tmp;
    }
};
