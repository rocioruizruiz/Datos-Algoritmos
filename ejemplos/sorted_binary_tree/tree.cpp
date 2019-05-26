#include "tree.h"

Tree::Tree():
    first{nullptr}
{

}

void Tree::push(Data* d)
{
    Node* n = new Node(d);
    if(!first)
        first = n;
    else
        first->push(n);
}

Node *Tree::search(Node* n)
{
    Node* it = first;

    while(it){
        if(it->data == n->getData()) return it;
        else if(it->data->getValue() > n->getData()->getValue()) it = it->left;
        else if(it->data->getValue() < n->getData()->getValue()) it = it->right;
    }
    return nullptr;
}

Node *Tree::getFirst() const
{
    return first;
}

void Tree::depthFirstRun() const
{
    if(first) first->depthFirstRun();
}


void Tree::breadthFirstRun() const {
    if (first) first->breadthFirstRun();
}
void Tree::erase(Node* n){
    Node* found = search(n);
    if(first && found) first->erase(found);
}


