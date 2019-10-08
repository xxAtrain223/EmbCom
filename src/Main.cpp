#include "EmbCom/Device.hpp"

#include <iostream>
#include <cstdint>
#include <cassert>

using namespace emb::com;

int main(int argc, char** argv)
{
    // Read config for appendages and commands
    // Establish connection to the device
    Device device("path/to/config/folder");

    uint8_t send_one = 42;
    int16_t send_two = -83;

    // Send the commands with the parameters and wait for them
    std::shared_ptr<Command> command_alpha_set = device["command_alpha"]["set"](send_one, send_two);
    std::shared_ptr<Command> command_alpha_get = device["command_alpha"]["get"]();

    // Get the command return values 
    uint8_t receive_one = (*command_alpha_get)["one"];
    int16_t receive_two = command_alpha_get->getReturnValue("two");

    assert(send_one == receive_one);
    assert(send_two == receive_two);
}