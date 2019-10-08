#include "EmbCom/CommandBuilder.hpp"

namespace emb::com
{
    CommandBuilder::CommandBuilder(
        std::shared_ptr<host::EmbMessenger> messenger,
        std::shared_ptr<gen::parser::Command> genCommand,
        uint16_t commandIndex, uint16_t appendageIndex) :
        m_messenger(m_messenger), 
        m_commandIndex(commandIndex),
        m_appendageIndex(appendageIndex)
    {
        for (gen::parser::Parameter& parameter : genCommand->getParameters())
        {
            m_parameterVector.emplace_back(Data::StringToType(parameter.getType()));
        }
        for (gen::parser::ReturnValue& returnValue : genCommand->getReturnValues())
        {
            m_returnValueVector.emplace_back(std::make_tuple(returnValue.getName(), Data::StringToType(returnValue.getType())));
        }
    }
}