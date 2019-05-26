#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

Node::Node(Data *d):
    data{d},
    parent{nullptr},
    left{nullptr},
    right{nullptr}
{

}

void Node::push(Node *n)
{
    if( n->getData()->getValue() > this->getData()->getValue()){
        if(right)
            right->push(n);
        else{
            right = n;
            n->parent = this;
        }
    }else{
        if(left)
            left->push(n);
        else{
            left = n;
            n->parent = this;
        }
    }
}

Node *Node::getRight() const
{
    return right;
}

void Node::depthFirstRun() const
{
    cout << *(this) << endl;
    if(left) left->depthFirstRun();
    if(right) right->depthFirstRun();

}


Node *Node::getParent() const
{
    return parent;
}

Node *Node::getLeft() const
{
    return left;
}

Data *Node::getData() const
{
    return data;
}

void Node::breadthFirstRun() {
    vector<Node*> queue;
    queue.push_back(this);
    cout << this->getData()->getValue() << endl;
    for(int i{0}; i < queue.size(); i++){
        if(queue.at(i)->left) {queue.push_back(queue.at(i)->left);
            cout << "Izquierda:    " << queue.at(i)->left->getData()->getValue() << endl;}
        if(queue.at(i)->right){ queue.push_back(queue.at(i)->right);
            cout << "Derecha:    " << queue.at(i)->right->getData()->getValue() << endl;}
    }
    cout << "Arbol recorrido" << endl;
}
void Node::erase(Node *found){
    Node* arriba = found->parent;
    Node* der = found->right;
    Node* izq = found->left;
    if (found->getData()->getValue() == arriba->left->getData()->getValue()) arriba->left = nullptr;
    if (found->getData()->getValue() == arriba->getRight()->getData()->getValue()) arriba->right = nullptr;
    found->right = nullptr;
    found->left = nullptr;
    found->parent = nullptr;
    delete found;
    
    if(der) push(der);
    if(izq) push(izq);
}


bool operator ==(const Node &n1, const Node &n2)
{
    return ( *(n1.data) == *(n2.data));
}

bool operator <=(const Node &n1, const Node &n2)
{
    return ( *(n1.data) <= *(n2.data));
}

bool operator >=(const Node &n1, const Node &n2)
{
    return ( *(n1.data) >= *(n2.data));
}

bool operator >(const Node &n1, const Node &n2)
{
    return ( *(n1.data) > *(n2.data));
}

bool operator <(const Node &n1, const Node &n2)
{
    return ( *(n1.data) < *(n2.data));
}

std::ostream &operator <<(std::ostream &os, const Node &d)
{
    os << *(d.data);
    return os;
}
