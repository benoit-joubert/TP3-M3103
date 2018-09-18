#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"
#include<memory>

template <typename T>
class CList
{
private:
    std::shared_ptr<CNode<T>> m_fictionalHead;
    std::shared_ptr<CNode<T>> m_fictionalTail;
    std::shared_ptr<CNode<T>> m_realTail;

public:
    CList ();
    ~CList ();
    void push_front (const T & val);
    void Show () const;
    std::shared_ptr<CNode<T>> Find (const T & val) const;
    void Add (const T & val, std::shared_ptr<CNode<T>>);
    void Delete (std::shared_ptr<CNode<T>>);
    void push_back (const T & val);
    std::shared_ptr<CNode<T>> Begin () const;
    void AddAfter (std::shared_ptr<CNode<T>>, const T & val);
    void AddBefore (const std::shared_ptr<CNode<T>> &, const T & val);
};

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::Begin () const
{
    return m_fictionalHead;
}

template <typename T>
void CList<T>::AddAfter (std::shared_ptr<CNode<T>> ptr, const T & val)
{
    std::shared_ptr<CNode<T>> tmp (new CNode<T> (val, ptr-> GetNextNode()));
    ptr -> SetNextNode(tmp);
    ptr -> GetNextNode()->SetPrevNode(tmp);
    if(ptr == m_fictionalTail) m_realTail = ptr ->GetPrevNode();

}

template <typename T>
void CList<T>::AddBefore (const std::shared_ptr<CNode<T>> & ptr, const T & val)
{
    AddAfter(ptr -> GetPrevNode(),val);
}

template <typename T>
void CList<T>::Add (const T & val, std::shared_ptr<CNode<T>> ptr)
{
    std::shared_ptr<CNode<T>> ptrTmp (new CNode<T> (val, ptr -> GetNextNode ()));
    ptr -> SetNextNode (ptrTmp);
    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}

/*Ptr_t AjoutApres (Ptr_t Tete, int NewVal, Ptr_t PtrElem)
{
    if (! PtrElem) PtrElem = Tete;

    PtrElem->SetSuivant
           (new C1Link (NewVal, PtrElem->GetSuivant()));

    return PtrElem->GetSuivant();

} // AjoutApres()
*/

template <typename T>
CList<T>::CList () : m_fictionalHead (new CNode<T> ()),m_fictionalTail(new CNode<T> ()), m_realTail (m_fictionalHead)
{
    m_fictionalTail->SetPrevNode (m_fictionalHead);
    m_fictionalHead->SetNextNode (m_fictionalTail);
}

template <typename T>
CList<T>::~CList () {
    //delete m_fictionalHead;
}

template <typename T>
std::shared_ptr<CNode<T>> CList<T>::Find (const T & val) const
{
    std::shared_ptr<CNode<T>> Ptr (m_fictionalHead->GetNextNode ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());

    return Ptr;
}



template <typename T>
void CList<T>::push_front (const T & val)
{
    std::shared_ptr<CNode<T>> tmp(new CNode<T> (val, m_fictionalHead->GetNextNode ()));
    m_fictionalHead->SetNextNode(tmp);
    if (m_realTail == m_fictionalHead) m_realTail = m_fictionalHead->GetNextNode ();
}

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (std::shared_ptr<CNode<T>> Ptr (m_fictionalHead -> GetNextNode()); Ptr; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr<CNode<T>> pDelete)
{
    std::shared_ptr<CNode<T>> pFind (m_fictionalHead);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());

    pFind -> SetNextNode (pDelete -> GetNextNode ());
    if (pDelete == m_realTail) m_realTail = pFind;
    pDelete -> SetNextNode (nullptr);

    //delete pDelete;
}

template <typename T>
void CList<T>::push_back (const T & val)
{
    std::shared_ptr<CNode<T>> pTmp (new CNode<T> (val, NULL));
    m_realTail -> SetNextNode (pTmp);
    m_realTail = pTmp;
}


#endif // LIST_HPP
