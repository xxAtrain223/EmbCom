#ifndef EMBCOM_COMMANDBUILDER_HPP
#define EMBCOM_COMMANDBUILDER_HPP

#include <memory>
#include <map>
#include <cstdint>
#include <tuple>

#include <EmbMessenger/IBuffer.hpp>
#include <EmbMessenger/EmbMessenger.hpp>

#include <EmbGen/Parser/Command.hpp>

#include "EmbCom/Data.hpp"
#include "EmbCom/Command.hpp"
#include "EmbCom/Exceptions.hpp"

namespace emb::com
{
    class CommandBuilder
    {
        uint16_t m_appendageIndex;
        uint16_t m_commandIndex;
        std::shared_ptr<host::EmbMessenger> m_messenger;

        std::vector<std::tuple<Data::Type, std::string>> m_parameters;
        std::vector<std::tuple<std::string, Data::Type>> m_returnValueTypes;

    public:
        CommandBuilder(
            std::shared_ptr<host::EmbMessenger> messenger, 
            std::shared_ptr<gen::parser::Command> genCommand, 
            uint16_t commandIndex, 
            uint16_t appendageIndex
        );

        template <typename ...Ts>
        std::shared_ptr<Command> makeCommand(Ts&&... parameters) const
        {
            std::vector<Data> parameterVector = makeParameters(std::forward<Ts>(parameters)...);
            
            return std::make_shared<Command>(m_appendageIndex, parameterVector, m_returnValueTypes);
        }

        std::shared_ptr<Command> execute(const std::vector<Data>& parameters) const;

        template <typename ...Ts>
        std::shared_ptr<Command> operator()(Ts&&... parameters) const
        {
            std::shared_ptr<Command> command = makeCommand(std::forward<Ts>(parameters)...);

            m_messenger->send(command, m_commandIndex)->wait();

            return command;
        }

        std::vector<Data::Type> getParametersTypes() const;

        std::vector<std::tuple<std::string, std::string>> getParameters() const;

        std::vector<std::tuple<std::string, std::string>> getReturnValues() const;

    private:
        template <typename ...Ts, std::size_t ...Is>
        std::vector<Data> pushParameters(std::index_sequence<Is...>, Ts&& ... values) const
        {
            std::vector<Data> data;
            data.reserve(sizeof...(values));

            // Fold Expression: https://en.cppreference.com/w/cpp/language/fold
            // Comma Operator:  https://en.cppreference.com/w/cpp/language/operator_other
            (data.emplace_back(std::get<0>(m_parameters[Is]), std::forward<Ts>(values)), ...);

            return data;
        }

        template <typename ...Ts>
        std::vector<Data> makeParameters(Ts&& ... parameterValues) const
        {
            if (sizeof...(parameterValues) != m_parameters.size())
            {
                throw ParameterException("Value count is not the same as the Type count");
            }

            return pushParameters(std::make_index_sequence<sizeof...(parameterValues)>{}, std::forward<Ts>(parameterValues)...);
        }
    };
}

#endif // EMBCOM_COMMANDBUILDER_HPP