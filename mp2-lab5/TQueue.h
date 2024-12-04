#include <iostream>

template <class T>
class TQueue
{
    T* pMem;
    int indHead;
    int indTail;
    int size;        // размер массива
    int counterSize; // сколько элементов в очереди

public:
    TQueue(int _size = 20)       { size = _size; pMem = new T[size]; indTail = -1; indHead = 0; counterSize = 0; }
    ~TQueue()                    { delete[] pMem; }
    TQueue(const TQueue<T>& q);
    void clear()                 { counterSize = 0; indHead = 0; indTail = -1; delete[] pMem; }

    int getSize()                { return size; }
    int getCounterSize()         { return counterSize; }

    bool isEmpty()               { return counterSize == 0; }
    bool isFull()                { return counterSize == size; }

    T TFront()                   { return pMem[indHead]; }
    T TBack()                    { return pMem[indTail]; }

    void Push(T elem);
    T    Pop();

    TQueue<T>& operator=(const TQueue<T>& _q);
    bool operator==(const TQueue<T>& _q) const;
    bool operator!=(const TQueue<T>& _q) const;

    friend std::ostream& operator<<(std::ostream& ostr, const TQueue<T>& q) {
        if (q.indTail >= q.indHead) {
            for (int i = q.indHead; i <= q.indTail; i++)
                ostr << q.pMem[i] << " ";
        }
        else {
            for (int i = q.indHead; i < q.size; i++)
                ostr << q.pMem[i] << " ";
            for (int i = 0; i <= q.indTail; i++)
                ostr << q.pMem[i] << " ";
        }
        return ostr;
    };
    
    // заполняет массив (уже выделенная снаружи память) текущим состоянием очереди от головы до хвоста
    void getQ(T* arr) {
        int k = 0;
        if (indTail >= indHead) {
            for (int i = indHead; i <= indTail; i++)
                arr[k++] = pMem[i];
        }
        else {
            for (int i = indHead; i < size; i++)
                arr[k++] = pMem[i];
            for (int i = 0; i <= indTail; i++)
                arr[k++] = pMem[i];
        }
    }
};



template <class T>
TQueue<T>::TQueue(const TQueue& q) {
    counterSize = q.counterSize;
    size = q.size;
    pMem = new T[size];
    
    indHead = q.indHead;
    indTail = q.indTail;

    if (indTail >= indHead) {
        for (int i = indHead; i < indTail; i++)
            pMem[i] = q.pMem[i];
    }
    else {
        for (int i = indHead; i < size; i++)
            pMem[i] = q.pMem[i];

        for (int i = 0; i < indTail; i++)
            pMem[i] = q.pMem[i];
    }
};

template <class T>
void TQueue<T>::Push(T elem) {
    if (isFull()) throw - 100;

    if (indTail + 1 == size)
        indTail = 0;
    else
        indTail++;

    pMem[indTail] = elem;
    counterSize++;
}

template <class T>
T TQueue<T>::Pop() {
    if (isEmpty()) throw - 101;

    T res = pMem[indHead];

    if (indHead + 1 == size)
        indHead = 0;
    else
        indHead++;

    counterSize--;
    return res;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue& q) {
    counterSize = q.counterSize;
    if (size != q.size) {
        size = q.size;
        delete[] pMem;
        pMem = new T[size];
    }
    indHead = q.indHead;
    indTail = q.indTail;

    if (indTail >= indHead) {
        for (int i = indHead; i < indTail; i++)
            pMem[i] = q.pMem[i];
    }
    else {
        for (int i = indHead; i < size; i++)
            pMem[i] = q.pMem[i];

        for (int i = 0; i < indTail; i++)
            pMem[i] = q.pMem[i];
    }
    return *this;
};

template <class T>
bool TQueue<T>::operator==(const TQueue& q) const {
    if (counterSize != q.counterSize) return false;
    
    if (indTail >= indHead) {
        for (int i = indHead; i < indTail; i++)
        {
            if (pMem[i] != q.pMem[i + (-indHead + q.indHead)]) return false;
        }
    }
    else {
        for (int i = indHead; i < size; i++)
        {
            if (pMem[i] != q.pMem[i + (-indHead + q.indHead)]) return false;
        }

        for (int i = 0; i < indTail; i++)
        {
            if (pMem[i] != q.pMem[i + (-indHead + q.indHead)]) return false;
        }
    }

    return true;
}

template <class T>
bool TQueue<T>::operator != (const TQueue& q) const {
    return !(*this == q);
};
