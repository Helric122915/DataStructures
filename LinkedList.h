#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList {
  private:
    size_t count;

  public:
    Node* head;
    Node* tail;

    LinkedList();
    ~LinkedList();

    void append(Node*);

    void insert(Node*);

    bool del(Node*);

    bool isEmpty();

    void display();
};

LinkedList::LinkedList() : count(0) {
  head = tail = 0;
}

LinkedList::~LinkedList() {
  delete head;
  delete tail;
}

void LinkedList::append(Node* item) {
  if (!head)
    head = tail = item;
  else {
    item->prev = tail;
    tail->next = item;
    tail = item;
  }

  count++;
}

void LinkedList::insert(Node* item) {
  if (!head)
    head = tail = item;
  else {
    item->next = head;
    head->prev = item;
    head = item;
  }

  count++;
}

bool LinkedList::del(Node* item) {
  if (!head)
    return false;

  Node *temp = head;

  while(temp) {
    if (temp == item) {
      if (temp == head) {
        head = temp->next;
        if (temp->next)
          temp->next->prev = 0;
        else
          tail = 0;
      }
      else if (temp == tail) {
        tail = temp->prev;
        // Can only make it this far if this isn't the head.
        temp->prev->next = 0;
      }
      else {
        item->prev->next = item->next;
        item->next->prev = item->prev;
      }

      delete item;
      return true;
    }
    else
      temp = temp->next;
  }
  return false;
}

bool LinkedList::isEmpty() {
  if (count)
    return false;
  else
    return true;
}

void LinkedList::display() {

  Node *temp = head;

  while(temp->next) {
    std::cout << "<-[" << temp->getData() << "]->";

    temp = temp->next;
  }

  std::cout << "<-[" << temp->getData() << "]->\n";
}
#endif
