#pragma once
#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>

class ListException : public std::exception
{
public:
    ListException(const std::string& message) : m_message(message) {}
    virtual const char* what() const noexcept override { return m_message.c_str(); }

private:
    std::string m_message;
};

class IndexError : public ListException
{
public:
    IndexError() : ListException("Index out of range") {}
};

class SizeError : public ListException
{
public:
    SizeError() : ListException("Lists have different sizes") {}
};

#endif // ERROR_H
