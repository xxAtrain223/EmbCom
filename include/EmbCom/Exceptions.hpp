#ifndef EMBCOM_PARSER_EXCEPTIONS_HPP
#define EMBCOM_PARSER_EXCEPTIONS_HPP

#include <stdexcept>

#define NEW_EMB_EX(name)                                  \
    class name : public emb::com::BaseException           \
    {                                                     \
    public:                                               \
        name(const std::string& message = "") :           \
            emb::com::BaseException(#name ": " + message) \
        {                                                 \
        }                                                 \
    };                                                    \

namespace emb::com
{
    class BaseException : public std::runtime_error
    {
    public:
        BaseException(const std::string& message) :
            std::runtime_error(message)
        {
        }
    };

    NEW_EMB_EX(FileException);
    NEW_EMB_EX(XmlParseException);
}

#endif // EMBCOM_PARSER_EXCEPTIONS_HPP