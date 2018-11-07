#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
public:
    int x, y;
    T data;
    Node* next;
    Node* down;
    Node(){next=nullptr; down=nullptr;}
};

#endif