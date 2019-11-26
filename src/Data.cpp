#include "EmbCom/Data.hpp"

namespace emb::com
{
    std::string Data::TypeToString() const
    {
        return TypeToString(m_type);
    }

    std::string Data::TypeToString(Type type)
    {
        switch (type)
        {
        case Data::Type::Bool:
            return "bool";
        case Data::Type::Float:
            return "float";
        case Data::Type::Uint8:
            return "uint8_t";
        case Data::Type::Uint16:
            return "uint16_t";
        case Data::Type::Uint32:
            return "uint32_t";
        case Data::Type::Uint64:
            return "uint64_t";
        case Data::Type::Int8:
            return "int8_t";
        case Data::Type::Int16:
            return "int16_t";
        case Data::Type::Int32:
            return "int32_t";
        case Data::Type::Int64:
            return "int64_t";
        default:
            return "";
        }
    }

    Data::BadCast::BadCast(std::string message) :
        std::runtime_error("BadCast: " + message)
    {
    }

    Data::Type Data::StringToType(std::string strType)
    {
        if (strType == "bool")
            return Data::Type::Bool;
        else if (strType == "float")
            return Data::Type::Float;
        else if (strType == "uint8_t")
            return Data::Type::Uint8;
        else if (strType == "uint16_t")
            return Data::Type::Uint16;
        else if (strType == "uint32_t")
            return Data::Type::Uint32;
        else if (strType == "uint64_t")
            return Data::Type::Uint64;
        else if (strType == "int8_t")
            return Data::Type::Int8;
        else if (strType == "int16_t")
            return Data::Type::Int16;
        else if (strType == "int32_t")
            return Data::Type::Int32;
        else if (strType == "int64_t")
            return Data::Type::Int64;
        else
            throw std::exception();
    }

    Data::Data(Type type) :
        m_type(type)
    {
        m_value.m_uint64 = 0;
    }

    void Data::setBool(const bool& v)
    {
        if (m_type == Type::Bool)
        {
            m_value.m_bool = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with bool.");
        }
    }

    void Data::setFloat(const float& v)
    {
        if (m_type == Type::Float)
        {
            m_value.m_float = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with float.");
        }
    }

    void Data::setUint8(const uint8_t& v)
    {
        if (m_type == Type::Uint8 ||
            m_type == Type::Uint16 ||
            m_type == Type::Uint32 ||
            m_type == Type::Uint64)
        {
            m_value.m_uint8 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with uint8_t.");
        }
    }

    void Data::setUint16(const uint16_t& v)
    {
        if (m_type == Type::Uint16 ||
            m_type == Type::Uint32 ||
            m_type == Type::Uint64)
        {
            m_value.m_uint16 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with uint16_t.");
        }
    }

    void Data::setUint32(const uint32_t& v)
    {
        if (m_type == Type::Uint32 ||
            m_type == Type::Uint64)
        {
            m_value.m_uint32 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with uint32_t.");
        }
    }

    void Data::setUint64(const uint64_t& v)
    {
        if (m_type == Type::Uint64)
        {
            m_value.m_uint64 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with uint64_t.");
        }
    }

    void Data::setInt8(const int8_t& v)
    {
        if (m_type == Type::Int8 ||
            m_type == Type::Int16 ||
            m_type == Type::Int32 ||
            m_type == Type::Int64)
        {
            m_value.m_int8 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with int8_t.");
        }
    }

    void Data::setInt16(const int16_t& v)
    {
        if (m_type == Type::Int16 ||
            m_type == Type::Int32 ||
            m_type == Type::Int64)
        {
            m_value.m_int16 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with int16_.");
        }
    }

    void Data::setInt32(const int32_t& v)
    {
        if (m_type == Type::Int32 ||
            m_type == Type::Int64)
        {
            m_value.m_int32 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with int32_t.");
        }
    }

    void Data::setInt64(const int64_t& v)
    {
        if (m_type == Type::Int64)
        {
            m_value.m_int64 = v;
        }
        else
        {
            throw BadCast("Tried to set " + TypeToString() + " with int64_t.");
        }
    }

    bool Data::getBool() const
    {
        if (m_type == Type::Bool)
        {
            return m_value.m_bool;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with bool.");
        }
    }

    float Data::getFloat() const
    {
        if (m_type == Type::Float)
        {
            return m_value.m_float;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with float.");
        }
    }

    uint8_t Data::getUint8() const
    {
        if (m_type == Type::Uint8)
        {
            return m_value.m_uint8;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with uint8_t.");
        }
    }

    uint16_t Data::getUint16() const
    {
        if (m_type == Type::Uint8)
        {
            return m_value.m_uint8;
        }
        else if (m_type == Type::Uint16)
        {
            return m_value.m_uint16;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with uint16_t.");
        }
    }

    uint32_t Data::getUint32() const
    {
        if (m_type == Type::Uint8)
        {
            return m_value.m_uint8;
        }
        else if (m_type == Type::Uint16)
        {
            return m_value.m_uint16;
        }
        else if (m_type == Type::Uint32)
        {
            return m_value.m_uint32;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with uint32_t.");
        }
    }

    uint64_t Data::getUint64() const
    {
        if (m_type == Type::Uint8)
        {
            return m_value.m_uint8;
        }
        else if (m_type == Type::Uint16)
        {
            return m_value.m_uint16;
        }
        else if (m_type == Type::Uint32)
        {
            return m_value.m_uint32;
        }
        else if (m_type == Type::Uint64)
        {
            return m_value.m_uint64;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with uint64_t.");
        }
    }

    int8_t Data::getInt8() const
    {
        if (m_type == Type::Int8)
        {
            return m_value.m_int8;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with int8_t.");
        }
    }

    int16_t Data::getInt16() const
    {
        if (m_type == Type::Int8)
        {
            return m_value.m_int8;
        }
        else if (m_type == Type::Int16)
        {
            return m_value.m_int16;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with int16_t.");
        }
    }

    int32_t Data::getInt32() const
    {
        if (m_type == Type::Int8)
        {
            return m_value.m_int8;
        }
        else if (m_type == Type::Int16)
        {
            return m_value.m_int16;
        }
        else if (m_type == Type::Int32)
        {
            return m_value.m_int32;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with int32_t.");
        }
    }

    int64_t Data::getInt64() const
    {
        if (m_type == Type::Int8)
        {
            return m_value.m_int8;
        }
        else if (m_type == Type::Int16)
        {
            return m_value.m_int16;
        }
        else if (m_type == Type::Int32)
        {
            return m_value.m_int32;
        }
        else if (m_type == Type::Int64)
        {
            return m_value.m_int64;
        }
        else
        {
            throw BadCast("Tried to get " + TypeToString() + " with int64_t.");
        }
    }

    Data::Type Data::getType() const
    {
        return m_type;
    }

    Data::Value Data::getValue() const
    {
        return m_value;
    }
}