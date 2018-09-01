#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void _init_list(ListNode **l)
    {
        (*l) = new ListNode(-1);
        (*l)->next = NULL;
    }
    void _insert_node(ListNode* l, int v)
    {
        while(l->next != NULL)
        {
            l = l->next;
        }
        l->next = new ListNode(v);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3,*_l3 = NULL;
        int tmp = 0;
        int res = 0;
        int carry = 0;

        _init_list(&l3);

        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL && l1->val == -1)
            {
                l1 = l1->next;
            }
            if (l2 != NULL && l2->val == -1)
            {
                l2 = l2->next;
            }
            if (l1 != NULL && l2 != NULL)
            {
                tmp = l1->val + l2->val + carry;
            }
            else if (l1 != NULL)
            {
                tmp = l1->val + carry;
            }
            else
            {
                tmp = l2->val + carry;
            }
            
            carry = 0;
            if (tmp >= 10)
            {
                carry = 1;
                res = tmp % 10;
            
                _insert_node(l3, res);
            }
            else
            {
                _insert_node(l3, tmp);
            }

            if (l1 != NULL)
            {
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                l2 = l2->next;
            }
        }

        if (carry != 0)
        {
            _insert_node(l3, carry);
        }

        return l3->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *l1,*l2, *l3 = NULL;
    Solution *s = new Solution;

    s->_init_list(&l1);
    s->_init_list(&l2);

    s->_insert_node(l1,2);
    s->_insert_node(l1,4);
    s->_insert_node(l1,3);
    
    s->_insert_node(l2,5);
    s->_insert_node(l2,6);
    s->_insert_node(l2,4);

    l3 = s->addTwoNumbers(l1,l2);

    while (l3 != NULL)
    {
        cout << l3->val << endl;
        l3 = l3->next;
    }

    return 0;
}
