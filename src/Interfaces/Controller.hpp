#ifndef PUREMVC_CONTROLLER_HPP
#define PUREMVC_CONTROLLER_HPP

#include <iostream>
#include <map>
#include "SimpleCommand.hpp"
#include "View.hpp"

using PureMVC::Patterns::SimpleCommand;

namespace PureMVC::Core {
    class Controller {
    protected:
        View *_view;
        std::string _multitonKey;
        std::map<std::string, std::function<SimpleCommand *()>> _commandMap;
        inline static std::map<std::string, Controller *> _instanceMap;
    public:
        explicit Controller(const std::string &key);

        static Controller *getInstance(const std::string &key, const std::function<Controller *(const std::string &k)> &factory);

        virtual void initializeController();

        virtual void executeCommand(Notification *notification);

        virtual void registerCommand(const std::string &notification, const std::function<SimpleCommand *()> &factory);

        [[nodiscard]] virtual bool hasCommand(const std::string &notificationName) const;

        virtual void removeCommand(const std::string &notificationName);

        static void removeController(const std::string &key);

        virtual ~Controller();

        static constexpr const char *MULTITON_MSG = "Controller instance for this Multiton key already constructed!";
    };
}

#endif //PUREMVC_CONTROLLER_HPP
