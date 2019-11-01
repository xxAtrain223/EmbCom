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
        std::unique_ptr<shared::IBuffer> m_buffer;
        std::shared_ptr<host::EmbMessenger> m_messenger;
        std::map<std::string, Appendage> m_appendages;

    public:
#if __has_include(<filesystem>)
        Device(std::filesystem::path configFolder);
#elif __has_include(<experimental/filesystem>)
        Device(std::experimental::filesystem::path configFolder);
#endif
        

        const Appendage& operator[](std::string appendageName) const;

        //void allStop(); // Call allStop command
    };
}

#endif // EMBCOM_DEVICE_HPP