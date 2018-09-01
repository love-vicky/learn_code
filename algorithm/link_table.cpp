#include <iostream>
using namespace std;

struct Link_Node
{
    int val;
    Link_Node *next;
    Link_Node(int v) : val(v), next(NULL) {}
};
class link_Op
{
    public:
        void insert_node(Link_Node *l, int v)
        {
            Link_Node *tmp = NULL;
            Link_Node *node = new Link_Node(v);
            tmp = l;

            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = node;

            return;
        }
};
int main(int argc, char const *argv[])
{
    Link_Node *l = new Link_Node(1);

    link_Op *op = new link_Op;
    op->insert_node(l,2);
    op->insert_node(l,3);

    while (l != NULL)
    {
        cout << l->val << endl;
        l = l->next;
    }
    return 0;
}
