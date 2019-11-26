#ifndef EMBCOM_DEVICE_HPP
#define EMBCOM_DEVICE_HPP

#include <string>
#include <memory>
#include <map>

#if __has_include(<filesystem>)
#include <filesystem>
#elif __has_include(<experimental/filesystem>)
#include <experimental/filesystem>
#endif

#include <EmbMessenger/IBuffer.hpp>
#include <EmbMessenger/EmbMessenger.hpp>

#include "EmbCom/Appendage.hpp"

namespace emb::com
{
    class Device
    {
        std::shared_ptr<host::EmbMessenger> m_messenger;
        std::map<std::string, Appendage> m_appendages;

        uint16_t m_stopId;

    public:
#if __has_include(<filesystem>)
        Device(std::filesystem::path configFolder, std::shared_ptr<shared::IBuffer> buffer);
#elif __has_include(<experimental/filesystem>)
        Device(std::experimental::filesystem::path configFolder, std::shared_ptr<shared::IBuffer> buffer);
#endif
        
        const Appendage& operator[](std::string appendageName) const;

        void stop();

        const std::map<std::string, Appendage> getAppendages() const;
    };
}

#endif // EMBCOM_DEVICE_HPP
