#ifndef PUREMVC_FACADE_HPP
#define PUREMVC_FACADE_HPP

#include <iostream>
#include <map>
#include "Controller.hpp"
#include "Model.hpp"
#include "View.hpp"
#include "SimpleCommand.hpp"
#include "Proxy.hpp"

using PureMVC::Core::Controller;
using PureMVC::Core::Model;
using PureMVC::Core::View;

namespace PureMVC::Patterns {
    class Facade {
    protected:
        std::string _multitonKey;
        Controller *_controller = nullptr;
        Model *_model = nullptr;
        View *_view = nullptr;
        inline static std::map<std::string, Facade *> _instanceMap;
    public:
        explicit Facade(const std::string &key);

        static Facade *
        getInstance(const std::string &key, const std::function<Facade *(const std::string &k)> &factory);

        void initializeFacade();

        void initializeModel();

        void initializeController();

        void initializeView();

        void registerCommand(const std::string &key, const std::function<SimpleCommand *()> &factory);

        void removeCommand(const std::string &notificationName);

        bool hasCommand(const std::string &notificationName);

        void registerProxy(Proxy *proxy);

        Proxy *retrieveProxy(const std::string &proxyName);

        Proxy *removeProxy(const std::string &proxyName);

        bool hasProxy(const std::string &proxyName);

        void registerMediator(Mediator *mediator);

        Mediator *retrieveMediator(const std::string &mediatorName);

        Mediator *removeMediator(const std::string &mediatorName);

        bool hasMediator(const std::string &mediatorName);

        void sendNotification(const std::string &name, const void *body = nullptr, const std::string &type = "");

        void notifyObservers(Notification *notification);

        void initializeNotifier(const std::string &key);

        static bool hasCore(const std::string &key);

        static void removeCore(const std::string &key);

        static constexpr const char *MULTITON_MSG = "Facade instance for this Multiton key already constructed!";
    };
}

#endif //PUREMVC_FACADE_HPP
