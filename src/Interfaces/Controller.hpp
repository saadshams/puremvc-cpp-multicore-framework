#ifndef PUREMVC_CONTROLLER_HPP
#define PUREMVC_CONTROLLER_HPP

#include <iostream>
#include <map>
#include "Interfaces/SimpleCommand.hpp"

using PureMVC::Patterns::Command::SimpleCommand;

namespace PureMVC::Core {
    class Controller {
    protected:
        std::string _multitonKey;
        std::map<std::string, SimpleCommand *(*)()> _commandMap;
        inline static std::map<std::string, Controller *> _instanceMap;
    public:
        explicit Controller(const std::string &key);

        static Controller *getInstance(const std::string &key, Controller *(*factory)(std::string k));

        void initializeController();

        void executeCommand(Notification *notification);

        void registerCommand(const std::string &notificationName, SimpleCommand *(*factory)());

        bool hasCommand(const std::string &notificationName);

        void removeCommand(const std::string &notificationName);

        static void removeController(const std::string &key);

        ~Controller();

        constexpr static char const *const MULTITON_MSG = "Controller instance for this Multiton key already constructed!";
    };
}

#endif //PUREMVC_CONTROLLER_HPP
