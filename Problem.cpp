

#include <iostream>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T data = 0, TreeNode* left = NULL, TreeNode* right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;
public:
    Tree(T data = 0) {
        root = new TreeNode<T>(data);

    }

    void buildTree()
    {
        
        insertNode(new TreeNode<T>('B'));
        insertNode(new TreeNode<T>('D'));
        insertNode(new TreeNode<T>('F'));
        insertNode(new TreeNode<T>('E'));
        insertNode(new TreeNode<T>('G'));
        insertNode(new TreeNode<T>('H'));
        insertNode(new TreeNode<T>('C'));
    }

    void insertNode(TreeNode<T>* node)
    {
        if (search(root, node->data) == NULL)
        {
            TreeNode<T>* parent = NULL;
            TreeNode<T>* current = root;

            while (current != NULL)
            {
                parent = current;
                if (node->data < parent->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            if (node->data < parent->data)
            {
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
            //cout << "insert " << node->data << endl;
        }
    }

    TreeNode<T>* getRoot()
    {
        return root;
    }

    void visit(TreeNode<T>* current)
    {
        cout << current->data << " ";
    }

    void preorder(TreeNode<T>* current)
    {
        if (current != NULL)
        {
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }

    void inorder(TreeNode<T>* current)
    {
        if (current != NULL)
        {
            inorder(current->left);
            visit(current);
            inorder(current->right);
        }
    }

    void postorder(TreeNode<T>* current)
    {
        if (current != NULL)
        {
            postorder(current->left);
            postorder(current->right);
            visit(current);
        }
    }

    TreeNode<T>* search(TreeNode<T>* current, T data)
    {
        if (current == NULL) return NULL;
        if (data == current->data)
        {
            return current;
        }
        else if (data < current->data)
        {
            search(current->left, data);
        }
        else
        {
            search(current->right, data);
        }
    }
};

int main()
{
    Tree<char> tree('A');
    tree.buildTree();
    cout << "Root A, B C D E F G H 추가됨\n";

   
    while (true)
    {
        int number;
        cout << "문자 추가 1, 검색 2, 순회 3, 종료 4\n";
        cin >> number;

        if (number == 1)
        {
            char c;
            cout << "추가할 문자 : ";
            cin >> c;
            tree.insertNode(new TreeNode<char>(c));
            cout << "문자가 추가되었습니다.\n";
        }
        else if (number == 2)
        {
            char s;
            cout << " 찾고싶은 문자 검색 : ";
            cin >> s;

            TreeNode<char>* found = tree.search(tree.getRoot(), s);

            if (found != NULL)
            {
                cout << "문자가 있습니다.\n";
            }
            else
            {
                cout << "문자가 없습니다.\n";
            }
        }
        else if (number == 3)
        {
            while (true)
            {
                int n;
                cout << "전위순회 1, 중위순회 2, 후위순회 3, 이전 메뉴 4\n";
                cin >> n;
                if (n == 1)
                {
                    cout << "Preorder >> ";
                    tree.preorder(tree.getRoot());
                    cout << endl;
                }
                else if (n == 2)
                {
                    cout << "inorder >> ";
                    tree.inorder(tree.getRoot());
                    cout << endl;
                }
                else if (n == 3)
                {
                    cout << "postorder >> ";
                    tree.postorder(tree.getRoot());
                    cout << endl;
                }
                else if (n == 4)
                {
                    break;
                }
            }
        }
        else if (number == 4)
        {
            break;
        }
        
    }

   
}

