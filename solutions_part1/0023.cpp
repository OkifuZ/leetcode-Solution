#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsSol(lists.begin(), lists.end());
    }

    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* head = list1->val < list2->val ? list1 : list2;
        ListNode* tail = head;
        if (head == list1) {
            list1 = list1->next;
        }
        else {
            list2 = list2->next;
        }
        while(list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                tail->next = list2;
                list2 = list2->next;
            }
            else {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        while (list1 != nullptr) {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next; 
        }
        while (list2 != nullptr) {
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
        return head;
    }
    
    ListNode* mergeKListsSol(vector<ListNode*>::iterator l, vector<ListNode*>::iterator r) {
        int k = r - l;
        if (k == 0) {
            return nullptr;
        }
        if (k == 1) {
            return *l;
        }
        auto mid = l + k / 2;
        ListNode* part1 = mergeKListsSol(l, mid);
        ListNode* part2 = mergeKListsSol(mid, r);
        return merge2Lists(part1, part2);
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(0);
    vector<ListNode*> l{a, b};
    Solution s;
    s.mergeKLists(l);
}