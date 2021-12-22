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

        static Controller *getInstance(const std::string &key, Controller *(*factory)(const std::string &k));

        virtual void initializeController();

        virtual void executeCommand(Notification *notification);

        virtual void registerCommand(const std::string &notificationName, SimpleCommand *(*factory)());

        virtual bool hasCommand(const std::string &notificationName) const;

        virtual void removeCommand(const std::string &notificationName);

        static void removeController(const std::string &key);

        virtual ~Controller();

        static constexpr const char *MULTITON_MSG = "Controller instance for this Multiton key already constructed!";
    };
}

#endif //PUREMVC_CONTROLLER_HPP
