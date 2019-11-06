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

    std::shared_ptr<Command> CommandBuilder::execute(const std::vector<Data>& parameters) const
    {
        if (m_parameterTypes.size() != parameters.size())
        {
            throw ParameterException("Value count is not the same as the Type count");
        }

        std::shared_ptr<Command> command = std::make_shared<Command>(m_appendageIndex, parameters, m_returnValueTypes);

        m_messenger->send(command, m_commandIndex)->wait();

        return command;
    }

    std::vector<Data::Type> CommandBuilder::getParametersTypes() const
    {
        return m_parameterTypes;
    }
}