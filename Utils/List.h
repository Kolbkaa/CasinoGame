//
// Created by dawid on 15.04.2022.
//

#ifndef CASINOGAME_LIST_H
#define CASINOGAME_LIST_H


#include <functional>
#include "ListElement.h"

template<typename T>
class List {
private:
    ListElement<T> *_element;
    int _length = 0;
public:
    int AddItem(T *item) {
        if (_element == NULL) {
            _element = new ListElement(item);
            return ++_length;
        }
        ListElement<T> *_head = _element;
        while (_head->IsNextElement()) {
            _head = _head->GetNextElement();
        }
        _head->SetNextElement(new ListElement(item));
        return ++_length;

    }

    T *GetItemById(int id) {
        if (id >= _length) {
            return NULL;
        }
        ListElement<T> *_head = _element;

        int index = 0;
        while (index != id) {
            ++index;
            _head = _head->GetNextElement();
        }
        return _head->GetItem();

    }

    void Clear() {
        while (_element != NULL) {
            ListElement<T> *elementToDelete = _element;
            _element = _element->GetNextElement();
            delete elementToDelete->GetItem();
            delete elementToDelete;

        }
    }

    void Iterate(const std::function<void(T*)>& fn){
        ListElement<T> *_head = _element;
        while(_head!=NULL){
            fn(_head->GetItem());
            _head = _head->GetNextElement();
        }
    }

};


#endif //CASINOGAME_LIST_H
