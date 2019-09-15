#include "EmbCom/Data.hpp"

namespace emb
{
    namespace com
    {
        std::string Data::TypeToString(const Data::Type type)
        {
            switch (type)
            {
            case Data::Type::Bool:
                return "Bool";
            case Data::Type::Float:
                return "Float";
            case Data::Type::Uint8:
                return "Uint8";
            case Data::Type::Uint16:
                return "Uint16";
            case Data::Type::Uint32:
                return "Uint32";
            case Data::Type::Uint64:
                return "Uint64";
            case Data::Type::Int8:
                return "Int8";
            case Data::Type::Int16:
                return "Int16";
            case Data::Type::Int32:
                return "Int32";
            case Data::Type::Int64:
                return "Int64";
            default:
                return "";
            }
        }

        Data::BadCast::BadCast(std::string message) :
            std::runtime_error("BadCast: " + message)
        {
        }

        Data::Data(Type m_type) :
            m_type(m_type)
        {
            m_value.m_uint64 = 0;
        }

        void Data::set(const bool& v)
        {
            if (m_type == Type::Bool)
            {
                m_value.m_bool = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Bool.");
            }
        }

        void Data::set(const float& v)
        {
            if (m_type == Type::Float)
            {
                m_value.m_float = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Float.");
            }
        }

        void Data::set(const uint8_t& v)
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
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Uint8.");
            }
        }

        void Data::set(const uint16_t& v)
        {
            if (m_type == Type::Uint16 ||
                m_type == Type::Uint32 ||
                m_type == Type::Uint64)
            {
                m_value.m_uint16 = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Uint16.");
            }
        }

        void Data::set(const uint32_t& v)
        {
            if (m_type == Type::Uint32 ||
                m_type == Type::Uint64)
            {
                m_value.m_uint32 = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Uint32.");
            }
        }

        void Data::set(const uint64_t& v)
        {
            if (m_type == Type::Uint64)
            {
                m_value.m_uint64 = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Uint64.");
            }
        }

        void Data::set(const int8_t& v)
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
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Int8.");
            }
        }

        void Data::set(const int16_t& v)
        {
            if (m_type == Type::Int16 ||
                m_type == Type::Int32 ||
                m_type == Type::Int64)
            {
                m_value.m_int16 = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Int16.");
            }
        }

        void Data::set(const int32_t& v)
        {
            if (m_type == Type::Int32 ||
                m_type == Type::Int64)
            {
                m_value.m_int32 = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Int32.");
            }
        }

        void Data::set(const int64_t& v)
        {
            if (m_type == Type::Int64)
            {
                m_value.m_int64 = v;
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString(m_type) + " with Int64.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Bool.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Float.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Uint8.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Uint16.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Uint32.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Uint64.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Int8.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Int16.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Int32.");
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
                throw BadCast("Tried to get " + TypeToString(m_type) + " with Int64.");
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
}