#include "LinkedList.h"

int main() {
  LinkedList *list = new LinkedList();

  Node* node = new Node(5);

  list->insert(node);
  list->display();
  list->insert(new Node(10));
  list->display();
  list->append(new Node(57));
  list->display();
  //list->del(node);
  //list->display();
}
