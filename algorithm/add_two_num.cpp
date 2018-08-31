#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void _add_node(ListNode** l, int v)
    {
        ListNode *_l = *l;
        if (_l == NULL)
        {
            _l = new ListNode(v);
        }
        else
        {
            while(_l->next != NULL)
            {
                _l = _l->next;
            }
            _l->next = new ListNode(v);
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *_l1 = l1;
        ListNode *_l2 = l2;
        ListNode *l3 = NULL;
        int tmp = 0;
        int res = 0;
        int carry = 0;

        while (_l1 != NULL || _l2 != NULL)
        {
            if (_l1 != NULL && _l2 != NULL)
            {
                tmp = _l1->val + _l2->val + carry;
            }
            else if (_l1 != NULL)
            {
                tmp = _l1->val + carry;
            }
            else
            {
                tmp = _l2->val + carry;
            }
            
            carry = 0;
            if (tmp > 10)
            {
                carry = 1;
                res = tmp % 10;
            }
            
            _add_node(&l3, res);

            _l1 = _l1->next;
            _l2 = _l2->next;
        }

        return l3;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *l1,*l2, *l3 = NULL;
    Solution *s = new Solution;

    s->_add_node(&l1,2);
    s->_add_node(&l1,4);
    s->_add_node(&l1,3);
    s->_add_node(&l2,5);
    s->_add_node(&l2,6);
    s->_add_node(&l2,4);

    l3 = s->addTwoNumbers(l1,l2);

    while (l3 != NULL)
    {
        cout << l3->val << endl;
        l3 = l3->next;
    }

    return 0;
}
