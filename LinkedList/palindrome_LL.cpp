#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr) {
            return nullptr; // Already reversed or empty list
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode* dummy = head;

        while (slow != nullptr) {
            if (dummy->val != slow->val)
                return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};

int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution solution;
    bool result = solution.isPalindrome(head);

    if (result) {
            cout << "The linked list is a palindrome." <<endl;
    } else {
            cout << "The linked list is not a palindrome." <<endl;
    }

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
