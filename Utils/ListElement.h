//
// Created by dawid on 15.04.2022.
//

#ifndef CASINOGAME_LISTELEMENT_H
#define CASINOGAME_LISTELEMENT_H


template<typename T>
class ListElement {
private:
    T *_item;
    ListElement<T> *_nextElement = 0;

public:
    ListElement(T *item) {
        _item = item;
    }

    T *GetItem() {
        return _item;
    };

    bool IsNextElement() {
        return !(_nextElement == NULL);
    }

    ListElement<T> *GetNextElement() {
        return _nextElement;
    }

    void SetNextElement(ListElement<T> *nextElement) {
        _nextElement = nextElement;
    }

};


#endif //CASINOGAME_LISTELEMENT_H
