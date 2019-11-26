#include "EmbCom/Command.hpp"

namespace emb::com
{
    Command::Command(const uint16_t& appendageIndex, const std::vector<Data>& parameters, const std::vector<std::tuple<std::string, Data::Type>>& returnValues) :
        m_appendageIndex(appendageIndex), m_parameters(parameters)
    {
        for (std::tuple<std::string, Data::Type> rv : returnValues)
        {
            std::shared_ptr<Data> rvData = std::make_shared<Data>(std::get<1>(rv));
            m_returnValuesVec.emplace_back(rvData);
            m_returnValuesMap.emplace(std::get<0>(rv), rvData);
        }
    }

    void writeData(host::EmbMessenger* messenger, Data data)
    {
        switch (data.getType())
        {
        case Data::Type::Bool: {
            messenger->write(static_cast<bool>(data));
        } break;
        case Data::Type::Float: {
            messenger->write(static_cast<float>(data));
        } break;
        case Data::Type::Uint8: {
            messenger->write(static_cast<uint8_t>(data));
        } break;
        case Data::Type::Uint16: {
            messenger->write(static_cast<uint16_t>(data));
        } break;
        case Data::Type::Uint32: {
            messenger->write(static_cast<uint32_t>(data));
        } break;
        case Data::Type::Uint64: {
            messenger->write(static_cast<uint64_t>(data));
        } break;
        case Data::Type::Int8: {
            messenger->write(static_cast<int8_t>(data));
        } break;
        case Data::Type::Int16: {
            messenger->write(static_cast<int16_t>(data));
        } break;
        case Data::Type::Int32: {
            messenger->write(static_cast<int32_t>(data));
        } break;
        case Data::Type::Int64: {
            messenger->write(static_cast<int64_t>(data));
        } break;
        }
    }

    void Command::send(host::EmbMessenger* messenger)
    {
        messenger->write(m_appendageIndex);
        for (Data parameter : m_parameters)
        {
            writeData(messenger, parameter);
        }
    }

    void readData(host::EmbMessenger* messenger, std::shared_ptr<Data> data)
    {
        switch (data->getType())
        {
        case Data::Type::Bool: {
            bool value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Float: {
            float value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Uint8: {
            uint8_t value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Uint16: {
            uint16_t value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Uint32: {
            uint32_t value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Uint64: {
            uint64_t value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Int8: {
            int8_t value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Int16: {
            int16_t value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Int32: {
            int32_t value;
            messenger->read(value);
            *data = value;
        } break;
        case Data::Type::Int64: {
            int64_t value;
            messenger->read(value);
            *data = value;
        } break;
        }
    }

    void Command::receive(host::EmbMessenger* messenger)
    {
        for (std::shared_ptr<Data> rv : m_returnValuesVec)
        {
            readData(messenger, rv);
        }
    }

    const Data& Command::getReturnValue(std::string rvName) const
    {
        return *m_returnValuesMap.at(rvName);
    }

    const std::map<std::string, std::shared_ptr<Data>> Command::getReturnValues() const
    {
        return m_returnValuesMap;
    }

    const Data& Command::operator[](std::string rvName) const
    {
        return getReturnValue(rvName);
    }

    const std::exception_ptr& Command::getException() const
    {
        return m_exceptionPtr;
    }
}