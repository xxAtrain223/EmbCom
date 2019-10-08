#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "EmbCom/Data.hpp"

namespace emb::com::test
{
    TEST(embcom_Data, Bool)
    {
        Data data(Data::Type::Bool);
        bool value;
                
        data.set(false);
        value = data.get<bool>();
        EXPECT_EQ(value, false);

        data = true;
        value = data;
        EXPECT_EQ(value, true);

        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_THROW(data.set<uint8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint64_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int64_t>(), Data::BadCast);
    }

    TEST(embcom_Data, Float)
    {
        Data data(Data::Type::Float);
        float value;

        data.set(42.f);
        value = data.get<float>();
        EXPECT_FLOAT_EQ(value, 42.f);

        data = 3.14f;
        value = data;
        EXPECT_FLOAT_EQ(value, 3.14f);

        EXPECT_THROW(data.set<bool>(0.f), Data::BadCast);
        EXPECT_THROW(data.set<uint8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint64_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int64_t>(), Data::BadCast);
    }

    TEST(embcom_Data, Uint8)
    {
        Data data(Data::Type::Uint8);
        uint8_t value;

        data.set(static_cast<uint8_t>(255u));
        value = data.get<uint8_t>();
        EXPECT_EQ(value, 255u);

        data = static_cast<uint8_t>(127u);
        value = data;
        EXPECT_EQ(value, 127u);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_THROW(data.set<uint16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_NO_THROW(data.get<uint16_t>());
        EXPECT_NO_THROW(data.get<uint32_t>());
        EXPECT_NO_THROW(data.get<uint64_t>());
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int64_t>(), Data::BadCast);
    }

    TEST(embcom_Data, Uint16)
    {
        Data data(Data::Type::Uint16);
        uint16_t value;

        data.set(static_cast<uint16_t>(65535u));
        value = data.get<uint16_t>();
        EXPECT_EQ(value, 65535u);

        data = static_cast<uint16_t>(32767u);
        value = data;
        EXPECT_EQ(value, 32767u);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_NO_THROW(data.set<uint8_t>(0));
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_NO_THROW(data.get<uint32_t>());
        EXPECT_NO_THROW(data.get<uint64_t>());
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int64_t>(), Data::BadCast);
    }

    TEST(embcom_Data, Uint32)
    {
        Data data(Data::Type::Uint32);
        uint32_t value;

        data.set(static_cast<uint32_t>(4294967295u));
        value = data.get<uint32_t>();
        EXPECT_EQ(value, 4294967295u);

        data = static_cast<uint32_t>(2147483647u);
        value = data;
        EXPECT_EQ(value, 2147483647u);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_NO_THROW(data.set<uint8_t>(0));
        EXPECT_NO_THROW(data.set<uint16_t>(0));
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_NO_THROW(data.get<uint64_t>());
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int64_t>(), Data::BadCast);
    }

    TEST(embcom_Data, Uint64)
    {
        Data data(Data::Type::Uint64);
        uint64_t value;

        data.set(static_cast<uint64_t>(9223372036854775807u));
        value = data.get<uint64_t>();
        EXPECT_EQ(value, 9223372036854775807u);

        data = static_cast<uint64_t>(4611686018427387903u);
        value = data;
        EXPECT_EQ(value, 4611686018427387903u);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_NO_THROW(data.set<uint8_t>(0));
        EXPECT_NO_THROW(data.set<uint16_t>(0));
        EXPECT_NO_THROW(data.set<uint32_t>(0));
        EXPECT_THROW(data.set<int8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int64_t>(), Data::BadCast);
    }

    TEST(embcom_Data, Int8)
    {
        Data data(Data::Type::Int8);
        int8_t value;

        data.set(static_cast<int8_t>(127));
        value = data.get<int8_t>();
        EXPECT_EQ(value, 127);

        data = static_cast<int8_t>(-127);
        value = data;
        EXPECT_EQ(value, -127);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_THROW(data.set<uint8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint64_t>(), Data::BadCast);
        EXPECT_NO_THROW(data.get<int16_t>());
        EXPECT_NO_THROW(data.get<int32_t>());
        EXPECT_NO_THROW(data.get<int64_t>());
    }

    TEST(embcom_Data, Int16)
    {
        Data data(Data::Type::Int16);
        int16_t value;

        data.set(static_cast<int16_t>(32767));
        value = data.get<int16_t>();
        EXPECT_EQ(value, 32767);

        data = static_cast<int16_t>(-32768);
        value = data;
        EXPECT_EQ(value, -32768);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_THROW(data.set<uint8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_NO_THROW(data.set<int8_t>(0));
        EXPECT_THROW(data.set<int32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint64_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_NO_THROW(data.get<int32_t>());
        EXPECT_NO_THROW(data.get<int64_t>());
    }

    TEST(embcom_Data, Int32)
    {
        Data data(Data::Type::Int32);
        int32_t value;

        data.set(static_cast<int32_t>(2147483647));
        value = data.get<int32_t>();
        EXPECT_EQ(value, 2147483647);

        data = static_cast<int32_t>(-2147483648);
        value = data;
        EXPECT_EQ(value, -2147483648);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_THROW(data.set<uint8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_NO_THROW(data.set<int8_t>(0));
        EXPECT_NO_THROW(data.set<int16_t>(0));
        EXPECT_THROW(data.set<int64_t>(0), Data::BadCast);

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint64_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_NO_THROW(data.get<int64_t>());
    }

    TEST(embcom_Data, Int64)
    {
        Data data(Data::Type::Int64);
        int64_t value;

        data.set(static_cast<int64_t>(4611686018427387903));
        value = data.get<int64_t>();
        EXPECT_EQ(value, 4611686018427387903);

        data = static_cast<int64_t>(-4611686018427387904);
        value = data;
        EXPECT_EQ(value, -4611686018427387904);

        EXPECT_THROW(data.set<bool>(false), Data::BadCast);
        EXPECT_THROW(data.set<float>(0.f), Data::BadCast);
        EXPECT_THROW(data.set<uint8_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint16_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint32_t>(0), Data::BadCast);
        EXPECT_THROW(data.set<uint64_t>(0), Data::BadCast);
        EXPECT_NO_THROW(data.set<int8_t>(0));
        EXPECT_NO_THROW(data.set<int16_t>(0));
        EXPECT_NO_THROW(data.set<int32_t>(0));

        EXPECT_THROW(data.get<bool>(), Data::BadCast);
        EXPECT_THROW(data.get<float>(), Data::BadCast);
        EXPECT_THROW(data.get<uint8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint32_t>(), Data::BadCast);
        EXPECT_THROW(data.get<uint64_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int8_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int16_t>(), Data::BadCast);
        EXPECT_THROW(data.get<int32_t>(), Data::BadCast);
    }

    TEST(embcom_Data, BadType)
    {
        Data data(Data::Type::Bool);

        EXPECT_THROW(data.set<double>(0.0), Data::BadCast);
        EXPECT_THROW(data.get<double>(), Data::BadCast);
    }
}
