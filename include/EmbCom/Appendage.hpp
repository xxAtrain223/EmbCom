#ifndef EMBCOM_APPENDAGE_HPP
#define EMBCOM_APPENDAGE_HPP

#include <memory>
#include <map>
#include <cstdint>

#include <EmbMessenger/IBuffer.hpp>
#include <EmbMessenger/EmbMessenger.hpp>

#include "EmbCom/CommandBuilder.hpp"

namespace emb::com
{
    class Appendage
    {
        //uint16_t m_appendageIndex;
        //std::shared_ptr<host::EmbMessenger> m_messenger;
        std::map<std::string, CommandBuilder> m_commands;

    public:
        Appendage(
            std::shared_ptr<host::EmbMessenger> messenger, 
            std::shared_ptr<gen::parser::Appendage> genAppendage, 
            uint16_t appendageIndex, 
            std::map<std::string, uint16_t> commandIds
        );

        const CommandBuilder& operator[](std::string commandName) const;

        const std::map<std::string, CommandBuilder> getCommands() const;
    };
}

#endif // EMBCOM_APPENDAGE_HPP