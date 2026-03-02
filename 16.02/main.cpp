template< class T > struct BiList {
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template< class T >
BiList< T >* add(BiList< T >* h, T v) {
  BiList< T >* newNode = new BiList< T >{v, h, nullptr};
  if (h) {
    h->prev = newNode;
  }
  return newNode;
}

template< class T >
BiList< T >* insert(BiList< T >* node, T v) {
  BiList< T >* newNode = new BiList< T >{v, nullptr, node};
  if (node) {
    node->next = newNode;
  }
  return newNode;
}

int main()
{
  
}
