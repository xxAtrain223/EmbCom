#ifndef EMBCOM_DATA_HPP
#define EMBCOM_DATA_HPP

#include <cstdint>
#include <string>
#include <stdexcept>

namespace emb::com
{
    class Data
    {
    public:
        enum class Type
        {
            Bool,
            Float,
            Uint8,
            Uint16,
            Uint32,
            Uint64,
            Int8,
            Int16,
            Int32,
            Int64
        };

        static Type StringToType(std::string strType);

        union Value
        {
            bool m_bool;
            float m_float;
            uint8_t m_uint8;
            uint16_t m_uint16;
            uint32_t m_uint32;
            uint64_t m_uint64;
            int8_t m_int8;
            int16_t m_int16;
            int32_t m_int32;
            int64_t m_int64;
        };

        class BadCast : public std::runtime_error
        {
        public:
            BadCast(std::string message = "");
        };

        Data(Type type);

        template <typename T>
        Data(Type type, T value) :
            m_type(type)
        {
            set(value);
        }

        template <typename T>
        void operator=(const T& v)
        {
            set(v);
        }

        template <typename T>
        void set(const T& v)
        {
            if constexpr (std::is_same_v<T, bool>)
            {
                setBool(v);
            }
            else if constexpr (std::is_same_v<T, float>)
            {
                setFloat(v);
            }
            else if constexpr (std::is_same_v<T, uint8_t>)
            {
                setUint8(v);
            }
            else if constexpr (std::is_same_v<T, uint16_t>)
            {
                setUint16(v);
            }
            else if constexpr (std::is_same_v<T, uint32_t>)
            {
                setUint32(v);
            }
            else if constexpr (std::is_same_v<T, uint64_t>)
            {
                setUint64(v);
            }
            else if constexpr (std::is_same_v<T, int8_t>)
            {
                setInt8(v);
            }
            else if constexpr (std::is_same_v<T, int16_t>)
            {
                setInt16(v);
            }
            else if constexpr (std::is_same_v<T, int32_t>)
            {
                setInt32(v);
            }
            else if constexpr (std::is_same_v<T, int64_t>)
            {
                setInt64(v);
            }
            else
            {
                throw BadCast("Tried to set " + TypeToString() + " with " + typeid(T).name() + ".");
            }
        }

        template <typename T>
        operator T() const
        {
            return get<T>();
        }

        template <typename T>
        T get() const
        {
            if constexpr (std::is_same_v<T, bool>)
            {
                return getBool();
            }
            else if constexpr(std::is_same_v<T, float>)
            {
                return getFloat();
            }
            else if constexpr(std::is_same_v<T, uint8_t>)
            {
                return getUint8();
            }
            else if constexpr(std::is_same_v<T, uint16_t>)
            {
                return getUint16();
            }
            else if constexpr(std::is_same_v<T, uint32_t>)
            {
                return getUint32();
            }
            else if constexpr(std::is_same_v<T, uint64_t>)
            {
                return getUint64();
            }
            else if constexpr(std::is_same_v<T, int8_t>)
            {
                return getInt8();
            }
            else if constexpr(std::is_same_v<T, int16_t>)
            {
                return getInt16();
            }
            else if constexpr(std::is_same_v<T, int32_t>)
            {
                return getInt32();
            }
            else if constexpr(std::is_same_v<T, int64_t>)
            {
                return getInt64();
            }
            else
            {
                throw BadCast("Tried to get " + TypeToString() + " with " + typeid(T).name() + ".");
            }
        }

        Type getType() const;
        Value getValue() const;

        std::string TypeToString() const;
        static std::string TypeToString(Type type);

    protected:
        Type m_type;
        Value m_value;

        void setBool(const bool& v);
        void setFloat(const float& v);
        void setUint8(const uint8_t& v);
        void setUint16(const uint16_t& v);
        void setUint32(const uint32_t& v);
        void setUint64(const uint64_t& v);
        void setInt8(const int8_t& v);
        void setInt16(const int16_t& v);
        void setInt32(const int32_t& v);
        void setInt64(const int64_t& v);

        bool getBool() const;
        float getFloat() const;
        uint8_t getUint8() const;
        uint16_t getUint16() const;
        uint32_t getUint32() const;
        uint64_t getUint64() const;
        int8_t getInt8() const;
        int16_t getInt16() const;
        int32_t getInt32() const;
        int64_t getInt64() const;
    };
}

#endif // EMBCOM_DATA_HPP