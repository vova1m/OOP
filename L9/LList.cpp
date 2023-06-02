#include "LList.h"

List::List(const std::vector<int>& data)
{
    for (auto it = data.rbegin(); it != data.rend(); ++it)
    {
        auto node = new Node;
        node->data = *it;
        node->next = m_head;
        m_head = node;
        ++m_size;
    }
}

List::List(const List& other)
{
    for (auto it = other.m_head; it != nullptr; it = it->next)
    {
        auto node = new Node;
        node->data = it->data;
        node->next = m_head;
        m_head = node;
        ++m_size;
    }
}

List::List(List&& other) noexcept : m_head(other.m_head), m_size(other.m_size)
{
    other.m_head = nullptr;
    other.m_size = 0;
}

List::~List()
{
    deleteList();
}

List& List::operator=(const List& other)
{
    if (this != &other)
    {
        deleteList();

        for (auto it = other.m_head; it != nullptr; it = it->next)
        {
            auto node = new Node;
            node->data = it->data;
            node->next = m_head;
            m_head = node;
            ++m_size;
        }
    }

    return *this;
}

List& List::operator=(List&& other) noexcept
{
    if (this != &other)
    {
        deleteList();

        m_head = other.m_head;
        m_size = other.m_size;
        other.m_head = nullptr;
        other.m_size = 0;
    }

    return *this;
}
int& List::operator[](int index)
{
    if (index < 0 || index >= m_size)
    {
        throw IndexError();
    }
    auto node = m_head;
    for (int i = 0; i < index; ++i)
    {
        node = node->next;
    }

    return node->data;
}
const int& List::operator[](int index) const
{
    if (index < 0 || index >= m_size)
    {
        throw IndexError();
    }
    auto node = m_head;
    for (int i = 0; i < index; ++i)
    {
        node = node->next;
    }

    return node->data;
}
int List::size() const
{
    return m_size;
}

std::vector<int> List::operator*(const std::vector<int>& other) const
{
    if (m_size != other.size())
    {
        throw SizeError();
    }
    std::vector<int> result;
    result.reserve(m_size);

    auto node = m_head;
    for (const auto& value : other)
    {
        result.push_back(node->data * value);
        node = node->next;
    }

    return result;
}
void List::jump(int n)
{
    if (n < 0 || n >= m_size)
    {
        throw IndexError();
    }
    auto node = m_head;
    for (int i = 0; i < n; ++i)
    {
        node = node->next;
    }

    m_head = node;
    m_size -= n;
}
void List::deleteList()
{
    while (m_head != nullptr)
    {
        auto node = m_head;
        m_head = m_head->next;
        delete node;
    }
    m_size = 0;
}
