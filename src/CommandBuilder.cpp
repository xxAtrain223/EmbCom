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
            m_parameterTypes.emplace_back(Data::StringToType(parameter.getType()));
        }
        for (gen::parser::ReturnValue& returnValue : genCommand->getReturnValues())
        {
            m_returnValueTypes.emplace_back(std::make_tuple(returnValue.getName(), Data::StringToType(returnValue.getType())));
        }
    }

    std::shared_ptr<Command> CommandBuilder::makeCommand(const std::vector<Data::Value>& parameterValues) const
    {
        if (m_parameterTypes.size() != parameterValues.size())
        {
            throw ParameterException("Value count is not the same as the Type count");
        }

        std::vector<Data> data;

        for (size_t i = 0; i < m_parameterTypes.size(); ++i)
        {
            data.emplace_back(m_parameterTypes[i], parameterValues[i]);
        }

        return std::make_shared<Command>(m_appendageIndex, data, m_returnValueTypes);
    }

    std::shared_ptr<Command> CommandBuilder::operator()(const std::vector<Data::Value>& parameters) const
    {
        std::shared_ptr<Command> command = makeCommand(parameters);

        m_messenger->send(command, m_commandIndex)->wait();

        return command;
    }
}