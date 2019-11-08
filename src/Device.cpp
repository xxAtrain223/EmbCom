#include "EmbCom/Device.hpp"

#include "EmbCom/Exceptions.hpp"

#include "EmbGen/Parser/Appendage.hpp"

#include "EmbMessenger/DebugBuffer.hpp"

#include <fstream>
#include <tinyxml2.h>

#include <nlohmann/json.hpp>

#if __has_include(<filesystem>)
namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
namespace fs = std::experimental::filesystem;
#endif

namespace emb::com
{
    Device::Device(fs::path configFolder, std::shared_ptr<shared::IBuffer> buffer)
    {
        if (!fs::is_directory(configFolder))
        {
            throw FileException("The device config directory does not exist or is not a directory.");
        }

        fs::path coreConfigFilePath = configFolder / "core_config.json";
        if (!fs::is_regular_file(coreConfigFilePath))
        {
            throw FileException("The device 'core_config.json' file does not exist or is not a file.");
        }

        fs::path appendagesFolder = configFolder / "appendages";
        if (!fs::is_directory(appendagesFolder))
        {
            throw FileException("The device 'appendages' directory does not exist or is not a folder.");
        }

        std::ifstream coreConfigStream(coreConfigFilePath.string());
        nlohmann::json coreConfig = nlohmann::json::parse(coreConfigStream);

        m_messenger = std::make_shared<emb::host::EmbMessenger>(buffer, [=](std::exception_ptr eptr) {
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (emb::host::BaseException e)
            {
                std::shared_ptr<emb::com::Command> command = std::static_pointer_cast<emb::com::Command>(e.getCommand());

                if (command != nullptr)
                {
                    command->m_exceptionPtr = eptr;
                }
            }
            catch (...) {}

            return false;
        });

        for (auto& appendageType : coreConfig["appendages"].items())
        {
            fs::path appendageFilePath = appendagesFolder / (appendageType.key() + ".xml");
            if (!fs::is_regular_file(appendageFilePath))
            {
                throw FileException("The appendage " + appendageType.key() + " does not exist or is a not a file.");
            }
            tinyxml2::XMLDocument tinyDocument;
            if (tinyDocument.LoadFile(appendageFilePath.string().c_str()) != tinyxml2::XMLError::XML_SUCCESS)
            {
                throw XmlParseException(tinyDocument.ErrorStr());
            }
            std::shared_ptr<gen::parser::Appendage> parserAppendage = std::make_shared<gen::parser::Appendage>(tinyDocument.FirstChildElement("appendage"));
            std::map<std::string, uint16_t> appendageCommandIds;

            for (auto& command : parserAppendage->getCommands())
            {
                appendageCommandIds.emplace(command.first, coreConfig["commands"][appendageType.key() + "_" + command.first + "_adaptor"]);
            }

            for (auto& appendageJson : appendageType.value().items())
            {
                m_appendages.emplace(appendageJson.key(), Appendage(
                    m_messenger,
                    parserAppendage,
                    appendageJson.value()["typeIndex"],
                    appendageCommandIds
                ));
            }
        }
    }

    const Appendage& Device::operator[](std::string appendageName) const
    {
        return m_appendages.at(appendageName);
    }
}
