//
// Created by NIHAAL on 3/19/2022.
//

#include <iostream>

using namespace std;

struct Bstnode {
    int data{};
    Bstnode *left = nullptr;
    Bstnode *right = nullptr;
};

class Btree {
    int n;
    int x;
public:
    bool flag = false;
    Bstnode *root;

    Btree() {
        root = nullptr;
    }

    Bstnode *GetNewNode(int in_data) {
        Bstnode *ptr = new Bstnode();
        ptr->data = in_data;
        ptr->left = nullptr;
        ptr->right = nullptr;
        return ptr;
    }

    Bstnode *insert(Bstnode *temp, int in_data) {
        if (temp == nullptr) {
            temp = GetNewNode(in_data);
        } else if (temp->data > in_data) {
            temp->left = insert(temp->left, in_data);
        } else {
            temp->right = insert(temp->right, in_data);
        }
        return temp;
    }

    void input() {
        cout << "No. of elements: ", cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Number: ", cin >> x;
            root = insert(root, x);
        }
    }

    void search(Bstnode *temp, int in_data) {
        if (temp != nullptr) {
            if (temp->data == in_data) {
                cout << "Found!!" << endl;
            } else if (flag) {
                if (in_data < temp->data) {
                    this->search(temp->right, in_data);
                } else if (in_data > temp->data) {
                    this->search(temp->left, in_data);
                }
            } else if (!flag) {
                if (in_data < temp->data) {
                    this->search(temp->left, in_data);
                } else if (in_data > temp->data) {
                    this->search(temp->right, in_data);
                }
            }

        } else {
            cout << "Not Found!" << endl;
        }
    }

    void minvalue(Bstnode *temp) {
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        cout << "Min. Value: " << temp->data << endl;
    }

    void mirror(Bstnode *temp) {
        if (temp == nullptr) {
            return;
        } else {
            Bstnode *ptr;
            mirror(temp->left);
            mirror(temp->right);
            ptr = temp->left;
            temp->left = temp->right;
            temp->right = ptr;
        }
    }

    void display(Bstnode *temp) {
        cout << "\nInorder Traversal" << endl;
        inorder(temp);
        cout << "\nPostOrder Traversal" << endl;
        postorder(temp);
        cout << "\nPreOrder Traversal" << endl;
        preorder(temp);
    }

    void inorder(Bstnode *temp) {
        if (temp != nullptr) {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    void postorder(Bstnode *temp) {
        if (temp != nullptr) {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }

    void preorder(Bstnode *temp) {
        if (temp != nullptr) {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    int depth(Bstnode *temp) {
        if (temp == nullptr)
            return 0;
        return (max((depth(temp->left)), depth(temp->right)) + 1);
    }
};

int main() {
    int ch, key, a;
    Btree obj;
    cout << "1. Insert\n2. Depth\n3. Mirror\n4. Search\n5. Display\n6. Minimum\n7. Exit" << endl;
    do {
        cout << "\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                obj.input();
                break;
            case 2:
                cout << "Depth: " << obj.depth(obj.root) << endl;
                break;
            case 3:
                obj.mirror(obj.root);
                obj.flag = !obj.flag;
                break;
            case 4:
                cout << "Element?! ", cin >> key;
                obj.search(obj.root, key);
                break;
            case 5:
                obj.display(obj.root);
                break;
            case 6:
                obj.minvalue(obj.root);
                break;
            case 7:
                cout << "Exiting..." << endl;
                exit(0);
        }
    } while (ch != 7);
    return 0;
}