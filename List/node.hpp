#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode> m_Next;
    std::shared_ptr<CNode> m_Prev;
public:
    //constructor
    CNode (const T &  val = T(), std::shared_ptr<CNode> ptr = nullptr);
    //destructor
    ~CNode ();

    //getter / setter
    const T &GetData () const;
    std::shared_ptr<CNode<T>> GetNextNode () const;
    std::shared_ptr<CNode<T>> GetPrevNode () const;
    void SetData (const T & val);
    void SetNextNode (const std::shared_ptr<CNode> &);
    void SetPrevNode (const std::shared_ptr<CNode> &);
};


template <typename T>
CNode<T>::CNode (const T & val, std::shared_ptr<CNode> ptr ) : m_Data (val), m_Next (ptr), m_Prev (ptr)
{
}

template <typename T>
CNode<T>::~CNode ()
{
    //delete m_Next;
    //cout << m_Data << endl;
}

template <typename T>
const T & CNode<T>::GetData () const
{
    return m_Data;
}

template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetNextNode () const
{
    return m_Next;
}

template <typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetPrevNode() const
{
    return m_Prev;
}

template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::SetNextNode (const std::shared_ptr<CNode> & ANode)
{
    m_Next = ANode;
}

template <typename T>
void CNode<T>::SetPrevNode(const std::shared_ptr<CNode> & ANode)
{
    m_Prev = ANode;
}

#endif // NODE_HPP
