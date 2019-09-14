#include "EmbCom/Data.hpp"

namespace emb
{
    namespace com
    {
        Data::BadCast::BadCast(std::string message) :
            std::runtime_error(message)
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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
                throw BadCast();
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