#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    string meaning;
    Node* right;
    Node* left;
};

class BT {
public:
    Node* root;
    BT() {
        root = NULL;
    }
    void create();
    void insert(Node*, Node*);
    void ascending(Node*);
    void descending(Node*);
    void update(Node*, string);
    void delete_key(Node*, string);
};

void BT::create() {
    Node* temp;
    char choice;
    do {
        temp = new Node;
        cout << "Enter data: ";
        cin >> temp->data;
        cout << "Enter Meaning: ";
        cin.ignore();
        getline(cin, temp->meaning);

        temp->right = NULL;
        temp->left = NULL;

        if (root == NULL) {
            root = temp;
            cout << "\nAdded to root\n";
        }
        else {
            insert(root, temp);
        }
        cout << "\nDo you want to continue to add data (y/n): ";
        cin >> choice;
    } while (choice == 'y');
}

void BT::insert(Node* root, Node* temp) {
    if (temp->data < root->data) {
        if (root->left == NULL) {
            root->left = temp;
        }
        else {
            insert(root->left, temp);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = temp;
        }
        else {
            insert(root->right, temp);
        }
    }
}

void BT::ascending(Node* temp) {
    if (temp != NULL) {
        ascending(temp->left);
        cout << temp->data << "|-" << temp->meaning << "-->";
        ascending(temp->right);
    }
}

void BT::descending(Node* temp) {
    if (temp != NULL) {
        descending(temp->right);
        cout << temp->data << "|-" << temp->meaning << "-->";
        descending(temp->left);
    }
}

void BT::update(Node* temp, string key) {
    if (temp != NULL) {
        if (temp->data == key) {
            cout << "Enter new meaning: ";
            cin.ignore();
            getline(cin, temp->meaning);
        }
        update(temp->left, key);
        update(temp->right, key);
    }
}

void BT::delete_key(Node* temp, string key) {
    // Code to delete a key from the binary tree
}

int main() {
    BT bt;
    int choice;
    char ch;
    string key_2;
    string key_1;

    do {
        cout << "1. Create\n2. Ascending\n3. Descending\n4. Update\n5. Delete\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bt.create();
            break;
        case 2:
            if (bt.root == NULL) {
                cout << "Tree cannot be displayed as it is not created." << endl;
            }
            else {
                bt.ascending(bt.root);
                cout << endl;
            }
            break;
        case 3:
            if (bt.root == NULL) {
                cout << "Tree cannot be displayed as it is not created." << endl;
            }
            else {
                bt.descending(bt.root);
                cout << endl;
            }
            break;
        case 4:
            cout << "Enter the value for changing meaning: ";
            cin >> key_2;
            bt.update(bt.root, key_2);
            break;
        case 5:
            cout << "Enter value to be deleted: ";
            cin >> key_1;
            bt.delete_key(bt.root, key_1);
            break;
        }

        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}