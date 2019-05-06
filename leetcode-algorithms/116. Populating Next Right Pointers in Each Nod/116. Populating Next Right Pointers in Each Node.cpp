/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        queue<Node *> record;

        record.push(root);
        int count = 1;

        while (record.empty() == 0)
        {

            while (count--)
            {
                Node *temp = record.front();
                record.pop();

                if (count == 0)
                    temp->next = NULL;
                else if (count > 0)
                    temp->next = record.front();

                if (temp->left)
                    record.push(temp->left);
                if (temp->right)
                    record.push(temp->right);
            }

            count = record.size();
        }

        return root;
    }
};
