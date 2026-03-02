#include <iostream>

template< class T > struct BiList {
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template< class T >
BiList< T >* add(BiList< T >* h, T v) {
  BiList< T >* newNode = new BiList< T >{v, h, nullptr}; //копирование
  if (h) {
    if (h->prev) {
      h->prev->next = newNode;
    }
    h->prev = newNode;
  }
  return newNode;
}

template< class T >
BiList< T >* insert(BiList< T >* node, T v) {
  BiList< T >* newNode = new BiList< T >{v, nullptr, node}; //копирование
  if (node) {
    if (node->next) {
      node->next->prev = newNode;
    }
    node->next = newNode;
  }
  return newNode;
}

template< class T >
BiList< T >* cut(BiList< T >* h) {
  BiList< T >* res = h->next;
  if (h->next) {
    h->next->prev = h -> prev;
  }
  if (h->prev) {
    h->prev->next = h->next;
  }
  delete h;
  return res;
}

template< class T >
BiList< T >* erase(BiList< T >* node) {
  BiList< T >* toDelete = node->next;
  if (toDelete->next) {
    toDelete->next->prev = node;
    node->next = toDelete->next;
  }
  delete toDelete;
  return node;
}

template< class T >
void clear(BiList< T >* b, BiList< T >* e) {
  while (b != e) {
    b = cut(b);
  }
}

template< class T >
void printList(BiList< T >* head) {
  std::cout << "Список: ";
  while (head) {
    std::cout << head->val << " -> "; //Должен выводиться
    head = head->next;
  }
  std::cout << "\n";
}

template< class T >
BiList< T >* arrToList(const T* arr, size_t s) {
  BiList< T >* head = nullptr;
  BiList< T >* tail = nullptr;
  if (!s or !arr) {
    return nullptr;
  }
  for (size_t i = 0; i < s; i++) {
    if (!head) {
      head = add(head, arr[i]);
      tail = head;
    } else {
      tail = insert(tail, arr[i]);
    }
  }
  return head;
}

int main()
{
  
}
