#ifndef LIST_H
#define LIST_H

#include <list>
#include <cstddef>
#include <iterator>

#include <QDebug>

template <class T> class List {
private:
    std::list<T *> objects;
    int count;
    uint currentIndex;
    typename std::list<T*>::iterator item_iter;

public:
    T *currentItem;
    T *get(int idx);
    void remove(unsigned const int idx);
    void add(T *obj);
    void start();
    bool empty();
    void next();
    int getCurrentIndex();
    List<T> operator++();

    List() {
        this->currentItem = NULL;
        this->currentIndex = 0;
        this->count = 0;
    }
    ~List() {
    }
};

template <class T>
void List<T>::add(T *obj) {
    this->objects.push_back(obj);
}

template <class T>
T *List<T>::get(int idx) {
    if (idx < this->objects.size()) {
      typename std::list<T*>::iterator it = this->objects.begin();
      std::advance(it, idx);
      return *it;
    } else {
      return NULL;
    }
}

template <class T>
void List<T>::remove(unsigned const int idx) {
    if (idx < this->objects.size()) {
      typename std::list<T*>::iterator it = this->objects.begin();
      std::advance(it, idx);
      this->objects.remove(*it);
    }
}

template <class T>
void List<T>::start() {
    this->currentIndex = 0;
    if (this->objects.size() > 0) {
      this->item_iter = this->objects.begin();
      this->currentItem = *(this->item_iter);
    } else {
      this->currentItem = NULL;
    }
}

template <class T>
void List<T>::next() {
    if (!this->empty() && (this->currentIndex == 0) && (this->currentItem == NULL)) {
        this->start();
    } else if (this->currentIndex < this->objects.size() - 1) {
      this->currentIndex++;
      std::advance(item_iter, 1);
      this->currentItem = *item_iter;
    } else {
      this->currentItem = NULL;
    }
}

template <class T>
bool List<T>::empty() {
    return !this->objects.size();
}

template <class T>
int List<T>::getCurrentIndex() {
    return this->currentIndex;
}

template <class T>
List<T> List<T>::operator++(){
    this->next();
    return *this;
}

#endif // LIST_H
