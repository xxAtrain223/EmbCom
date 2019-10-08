#ifndef EMBCOM_COMMANDBUILDER_HPP
#define EMBCOM_COMMANDBUILDER_HPP

#include <memory>
#include <map>
#include <cstdint>

#include <EmbMessenger/IBuffer.hpp>
#include <EmbMessenger/EmbMessenger.hpp>

#include <EmbGen/Parser/Command.hpp>

#include "EmbCom/Data.hpp"
#include "EmbCom/Command.hpp"

namespace emb::com
{
    class CommandBuilder
    {
        uint16_t m_appendageIndex;
        uint16_t m_commandIndex;
        std::shared_ptr<host::EmbMessenger> m_messenger;

        std::vector<Data::Type> m_parameterVector;
        std::vector<std::tuple<std::string, Data::Type>> m_returnValueVector;

    public:
        CommandBuilder(
            std::shared_ptr<host::EmbMessenger> messenger, 
            std::shared_ptr<gen::parser::Command> genCommand, 
            uint16_t commandIndex, 
            uint16_t appendageIndex
        );

        template <typename ...Ts>
        std::shared_ptr<Command> makeCommand(Ts... parameters) const
        {
            std::vector<Data::Type> reversedParameters = m_parameterVector;
            std::reverse(reversedParameters.begin(), reversedParameters.end());
            std::vector<Data> parameterVector = makeParameters(reversedParameters, std::forward<Ts>(parameters)...);
            std::reverse(parameterVector.begin(), parameterVector.end());
            
            std::shared_ptr<Command> command = std::make_shared<Command>(m_appendageIndex, parameterVector, m_returnValueVector);

            return command;
        }

        template <typename ...Ts>
        std::shared_ptr<Command> operator()(Ts... parameters) const
        {
            std::shared_ptr<Command> command = makeCommand(std::forward<Ts>(parameters)...);

            m_messenger->send(command, m_commandIndex)->wait();

            return command;
        }
        
    private:
        inline std::vector<Data> makeParameters(std::vector<Data::Type> types) const
        {
            if (!types.empty())
            {
                throw std::exception("Not enough c++ parameters");
            }
            return std::vector<Data>();
        }

        template <typename T, typename ...Ts>
        std::vector<Data> makeParameters(std::vector<Data::Type> types, T param, Ts... parameters) const
        {
            if (types.empty())
            {
                throw std::exception("Too many c++ parameters");
            }

            Data::Type type = types.back();
            types.pop_back();

            Data data(type);
            data = param;

            std::vector<Data> dataVector = makeParameters(types, std::forward<Ts>(parameters)...);
            dataVector.emplace_back(data);

            return dataVector;
        }
    };
}

#endif // EMBCOM_COMMANDBUILDER_HPP