#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *fast = head, *slow = head;
        bool flag = false;
        bool cyc = false;
        while (fast->next != nullptr && fast->next->next!= nullptr) {
            if (flag && fast == slow) {
                cyc = true;
                break;
            } 
            flag = flag | true;
            fast = fast->next->next;
            slow = slow ->next;
        }
        if (cyc) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        else {
            return nullptr;
        }
    }
};

