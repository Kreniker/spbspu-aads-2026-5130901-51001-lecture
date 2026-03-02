template< class T > struct BiList {
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template<class T>
BiList< T >* add(BiList<T>* head, T v) {
  BiList< T >* newNode = new BiList< T >{v, head, nullptr};
  if (head) {
    head->prev = newNode;
  }
  return newNode;
}

int main()
{
  
}
