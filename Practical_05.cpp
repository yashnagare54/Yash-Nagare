//
// Created by NIHAAL on 5/1/2022.
//

#include <bits/stdc++.h>
#include<string>
using namespace std;
class dictionary;
class node
{
    string word,meaning;
    node *left,*right;
public:
    friend class dictionary;
    node()
    {
        left=NULL;
        right=NULL;
    }
    node(string word, string meaning)
    {
        this->word=word;
        this->meaning=meaning;
        left=NULL;
        right=NULL;
    }
};
class dictionary
{
public:
    node *root;
    dictionary()
    {
        root=NULL;
    }
    void create();
    int update(node*,string k);
    void inorder_rec(node *rnode);
    void postorder_rec(node *rnode);
    void inorder()
    {
        inorder_rec(root);
    }
    void postorder();
    bool insert(string word,string meaning);
    int search(string key);
};
int dictionary::search(string key)
{
    node *tmp=root;
    int count=0;
    if(tmp==NULL)
    {
        return -1;
    }
    if(root->word==key)
        return 1;
    while(tmp!=NULL)
    {
        if((tmp->word)>key)
        {
            tmp=tmp->left;
            count++;
        }
        else if((tmp->word)<key)
        {
            tmp=tmp->right;
            count++;
        }
        else if(tmp->word==key)
        {
            return ++count;
        }
    }
    return -1;
}
void dictionary::postorder()
{
    postorder_rec(root);
}
void dictionary::postorder_rec(node *rnode)
{
    if(rnode)
    {
        postorder_rec(rnode->right);
        cout<<" "<<rnode->word<<" : "<<rnode->meaning<<endl;
        postorder_rec(rnode->left);
    }
}
void dictionary::create()
{
    int n;
    string wordI,meaningI;
    cout<<"\nHow many Word to insert?:\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Word: ";
        cin>>wordI;
        cout<<"\nEnter Meaning: ";
        cin>>meaningI;
        insert(wordI,meaningI);
    }
}
void dictionary::inorder_rec(node *rnode)
{
    if(rnode)
    {
        inorder_rec(rnode->left);
        cout<<" "<<rnode->word<<" : "<<rnode->meaning<<endl;
        inorder_rec(rnode->right);
    }
}
bool dictionary::insert(string word, string meaning)
{
    node *p=new node(word, meaning);
    if(root==NULL)
    {
        root=p;
        return true;
    }
    node *cur=root;
    node *par=root;
    while(cur!=NULL) //traversal
    {
        if(word>cur->word)
        {par=cur;
            cur=cur->right;
        }
        else if(word<cur->word)
        {
            par=cur;
            cur=cur->left;
        }
        else
        {
            cout<<"\nWord is already in the dictionary.";
            return false;
        }
    }
    if(word>par->word) //insertion of node
    {
        par->right=p;
        return true;
    }
    else
    {
        par->left=p;
        return true;
    }
}
int dictionary::update(node* root,string k)
{
    while(root!=NULL)
    {
        if(k.compare(root->word)==0)
        {
            cout<<"\nenter new meaning of "<<root->word<<" ";
            cin>>root->meaning;
            return 1;
        }
        if(k.compare(root->word)<0)
            root = root->left;
        if(k.compare(root->word)>0)
            root = root->right;
    }
    return -1;
}
int main() {
    string word;
    dictionary months;
    months.root = NULL;
    int ch;
    int comparisons;
    do{
        cout<<"\nMenu\n1.create\n2.Display(in ascending)\n3.Display(in descending)\n4.Search\n5.Update\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                months.create();
                break;
            case 2:
                cout<<"Ascending order\n";
                months.inorder();
                break;
            case 3:
                cout<<"\nDescending order:\n";
                months.postorder();
                break;
            case 4:
                cout<<"\nEnter word to search: ";
                cin>>word;
                comparisons= months.search(word);
                if(comparisons==-1)
                {
                    cout<<"\nNot found word";
                }
                else
                {
                    cout<<"\n "<<word<<" found in "<<comparisons<<" comparisons";
                }
                break;
            case 5:
                if(months.root == NULL)
                {
                    cout<<"\nWord is empty, enter first";
                }
                else
                {
                    cout<<"\nenter word to update: ";
                    string k;
                    cin>>k;
                    if(months.update(months.root,k)==1)
                        cout<<"\nword updated";
                    else
                        cout<<"\nword not found";
                }
                break;
        }
    }while(ch<=5);
    return 0;
}