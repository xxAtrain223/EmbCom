#ifndef EMBCOM_DEVICE_HPP
#define EMBCOM_DEVICE_HPP

#include <string>
#include <memory>
#include <map>
#include <experimental/filesystem>

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
        Device(std::experimental::filesystem::path configFolder);

        const Appendage& operator[](std::string appendageName) const;

        //void allStop(); // Call allStop command
    };
}

#endif // EMBCOM_DEVICE_HPP