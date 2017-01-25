#include "LinkedList.h"

int main() {
  LinkedList *list = new LinkedList();

  Node* node = new Node(5);

  list->insert(new Node(57));
  list->display();
  list->append(node);
  list->display();
  list->append(new Node(27));
  list->display();
  list->displayBackward();
  list->del(node);
  list->display();

  list->empty();
  list->display();
}
