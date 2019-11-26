#include "EmbCom/Appendage.hpp"

#include <EmbGen/Parser/Appendage.hpp>

namespace emb::com
{
    Appendage::Appendage(std::shared_ptr<host::EmbMessenger> messenger, std::shared_ptr<gen::parser::Appendage> genAppendage, uint16_t appendageIndex, std::map<std::string, uint16_t> commandIds)
    {
        for (auto& command : genAppendage->getCommands())
        {
            m_commands.emplace(command.first, CommandBuilder(
                messenger,
                command.second,
                commandIds[command.first],
                appendageIndex
            ));
        }
    }

    const CommandBuilder& Appendage::operator[](std::string commandName) const
    {
        return m_commands.at(commandName);
    }

    void Appendage::stop()
    {
        try
        {
            m_commands.at("stop")();
        }
        catch (std::out_of_range)
        { }
    }

    const std::map<std::string, CommandBuilder> Appendage::getCommands() const
    {
        return m_commands;
    }
}