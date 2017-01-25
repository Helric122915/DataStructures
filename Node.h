#ifndef NODE_H
#define NODE_H

class Node {
  private:
    int data;

  public:
    Node* next;
    Node* prev;

    Node(int);
    ~Node();

    int getData();
    void setData(int);
};

Node::Node(int d) : data(d) {
  next = prev = 0;
}

Node::~Node() {
  delete next;
  delete prev;
}

int Node::getData() {
  return data;
}

void Node::setData(int d) {
  data = d;
}
#endif
