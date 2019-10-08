#ifndef EMBCOM_COMMAND_HPP
#define EMBCOM_COMMAND_HPP

#include <EmbMessenger/Command.hpp>
#include <EmbMessenger/EmbMessenger.hpp>

#include "EmbCom/Data.hpp"

#include <memory>
#include <map>

namespace emb::com
{
    class Command : public host::Command
    {
        uint16_t m_appendageIndex;
        std::vector<Data> m_parameters;
        std::vector<std::shared_ptr<Data>> m_returnValuesVec;
        std::map<std::string, std::shared_ptr<Data>> m_returnValuesMap;

    public:
        Command(uint16_t appendageIndex, std::vector<Data> parameters, std::vector<std::tuple<std::string, Data::Type>> returnValues);

        void send(host::EmbMessenger* messenger) override;

        void receive(host::EmbMessenger* messenger) override;

        Data getReturnValue(std::string rvName);

        Data operator[](std::string rvName);
    };
}

#endif // EMBCOM_COMMAND_HPP