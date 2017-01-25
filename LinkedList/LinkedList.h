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

    bool empty();

    bool isEmpty();

    void display();

    void displayBackward();
};

LinkedList::LinkedList() : count(0) {
  head = tail = 0;
}

LinkedList::~LinkedList() {
  if (head)
    delete head;
  if (tail)
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
    head->prev = item;
    item->next = head;
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

      count--;
      return true;
    }
    else {
      temp = temp->next;
    }
  }
  return false;
}

bool LinkedList::empty() {
  while(head)
    if (!del(head))
      return false;
  return true;
}

bool LinkedList::isEmpty() {
  if (count)
    return false;
  else
    return true;
}

void LinkedList::display() {
  if (!isEmpty()) {
    Node *temp = head;

    while(temp) {
      std::cout << "<-[" << temp->getData() << "]->";

      temp = temp->next;
    }

    std::cout << "\n";
    //std::cout << "<-[" << temp->getData() << "]->\n";
  }
  else
    std::cout << "Nothing to print list is empty.\n";
}

void LinkedList::displayBackward() {
  if (!isEmpty()) {
    Node *temp = tail;

    while (temp) {
      std::cout << "<-[" << temp->getData() << "]->";

      temp = temp->prev;
    }

    std::cout << "\n";
    //std::cout << "<-[" << temp->getData() << "]->\n";
  }
  else
    std::cout << "Nothing to print list is empty.\n";
}
#endif
