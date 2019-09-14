#ifndef EMBCOM_DATA_HPP
#define EMBCOM_DATA_HPP

#include <cstdint>
#include <string>
#include <stdexcept>

namespace emb
{
    namespace com
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

            Data(Type m_type);

            template <typename T>
            void operator=(const T& v)
            {
                set(v);
            }

            void set(const bool& v);
            void set(const float& v);
            void set(const uint8_t& v);
            void set(const uint16_t& v);
            void set(const uint32_t& v);
            void set(const uint64_t& v);
            void set(const int8_t& v);
            void set(const int16_t& v);
            void set(const int32_t& v);
            void set(const int64_t& v);

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
                else
                {
                    throw BadCast();
                }
            }

            Type getType() const;
            Value getValue() const;

        protected:
            Type m_type;
            Value m_value;

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
}

#endif // EMBCOM_DATA_HPP