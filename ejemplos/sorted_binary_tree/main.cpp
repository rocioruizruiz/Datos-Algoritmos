#include <iostream>
#include <time.h>

#include "tree.h"

using namespace std;

int main()
{
    /*srand(time(NULL));
    int range = 100;
    int size = 10;

    Tree tree;

    // Creating the tree
    for(int i{0}; i<size; i++){
        int d = rand()%range;
        cout << d << endl;
        Data* data = new Data(d);
        tree.push(data);
    }

    // Searching for a value


    Data toFind{rand()%range};
    cout << "Looking for " << toFind << endl;
    Node* result = tree.search(toFind);
    if(result){
        cout << "Found: " << *result << endl;
    }else{
        cout << "Not found!" << endl;
    }
     */

    // Depth run of the tree
    Tree tree;
    tree.push(new Data(5));
    tree.push(new Data(3));
    tree.push(new Data(1));
    tree.push(new Data(2));
    tree.push(new Data(10));
    Node* n = new Node(new Data(7));
    tree.push(n->getData());
    tree.push(new Data(14));
    tree.push(new Data(6));
    tree.push(new Data(9));
    tree.push(new Data(12));
    tree.push(new Data(20));

    tree.breadthFirstRun();
    
    tree.erase(n);
    
    tree.breadthFirstRun();


    // Wide run of the tree

    return 0;
}
