#include "EmbCom/CommandBuilder.hpp"

namespace emb::com
{
    CommandBuilder::CommandBuilder(
        std::shared_ptr<host::EmbMessenger> messenger,
        std::shared_ptr<gen::parser::Command> genCommand,
        uint16_t commandIndex, uint16_t appendageIndex) :
        m_messenger(messenger), 
        m_commandIndex(commandIndex),
        m_appendageIndex(appendageIndex)
    {
        for (gen::parser::Parameter& parameter : genCommand->getParameters())
        {
            m_parameters.emplace_back(Data::StringToType(parameter.getType()), parameter.getName());
        }
        for (gen::parser::ReturnValue& returnValue : genCommand->getReturnValues())
        {
            m_returnValueTypes.emplace_back(std::make_tuple(returnValue.getName(), Data::StringToType(returnValue.getType())));
        }
    }

    std::shared_ptr<Command> CommandBuilder::execute(const std::vector<Data>& parameters) const
    {
        if (m_parameters.size() != parameters.size())
        {
            throw ParameterException("Value count is not the same as the Type count");
        }

        std::shared_ptr<Command> command = std::make_shared<Command>(m_appendageIndex, parameters, m_returnValueTypes);

        m_messenger->send(command, m_commandIndex)->wait();

        return command;
    }

    std::vector<Data::Type> CommandBuilder::getParametersTypes() const
    {
        std::vector<Data::Type> parameterTypes;

        for (const std::tuple<Data::Type, std::string>& parameter : m_parameters)
        {
            parameterTypes.emplace_back(std::get<0>(parameter));
        }

        return parameterTypes;
    }

    std::vector<std::tuple<std::string, std::string>> CommandBuilder::getParameters() const
    {
        std::vector<std::tuple<std::string, std::string>> parameters;

        for (const std::tuple<Data::Type, std::string>& parameter : m_parameters)
        {
            parameters.emplace_back(Data::TypeToString(std::get<0>(parameter)), std::get<1>(parameter));
        }

        return parameters;
    }
}