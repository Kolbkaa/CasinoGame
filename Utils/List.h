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

    void RemoveById(int id) {
        if (id >= _length || id < 0) {
            return;
        }
        ListElement<T> *_elementToRemove;

        if (id == 0) {
            _elementToRemove = _element;
            _element = _element->GetNextElement();
        } else {
            int index = 0;
            ListElement<T> *_head = _element;
            while (index != id - 1) {
                ++index;
                _head = _head->GetNextElement();
            }

            _elementToRemove = _head->GetNextElement();
            _head->SetNextElement(_elementToRemove->GetNextElement());
        }
        delete _elementToRemove;
        _length--;
    }


    void Clear() {
        while (_element != NULL) {
            ListElement<T> *elementToDelete = _element;
            _element = _element->GetNextElement();
            delete elementToDelete->GetItem();
            delete elementToDelete;

        }
    }

    void Iterate(const std::function<void(T *)> &fn) {
        ListElement<T> *_head = _element;
        while (_head != NULL) {
            fn(_head->GetItem());
            _head = _head->GetNextElement();
        }
    }

    T **ToArray() {
        T **array = new T *[_length];

        ListElement<T> *_head = _element;

        for (int i = 0; i < _length; i++) {
            array[i] = _head->GetItem();
            _head = _head->GetNextElement();
        }
        return array;
    }

    int Length() {
        return _length;
    }

};


#endif //CASINOGAME_LIST_H
