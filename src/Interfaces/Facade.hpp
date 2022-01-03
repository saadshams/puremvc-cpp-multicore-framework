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

        static Facade *getInstance(const std::string &key, const std::function<Facade *(const std::string &k)> &factory);

        virtual void initializeFacade();

        virtual void initializeModel();

        virtual void initializeController();

        virtual void initializeView();

        virtual void registerCommand(const std::string &key, const std::function<SimpleCommand *()> &factory);

        virtual void removeCommand(const std::string &notificationName);

        virtual bool hasCommand(const std::string &notificationName);

        virtual void registerProxy(Proxy *proxy);

        virtual Proxy *retrieveProxy(const std::string &proxyName);

        virtual Proxy *removeProxy(const std::string &proxyName);

        virtual bool hasProxy(const std::string &proxyName);

        virtual void registerMediator(Mediator *mediator);

        virtual Mediator *retrieveMediator(const std::string &mediatorName);

        virtual Mediator *removeMediator(const std::string &mediatorName);

        virtual bool hasMediator(const std::string &mediatorName);

        virtual void sendNotification(const std::string &name, const void *body, const std::string &type);

        virtual void sendNotification(const std::string &name, const void *body);

        virtual void sendNotification(const std::string &name);

        virtual void notifyObservers(Notification *notification);

        virtual void initializeNotifier(const std::string &key);

        static bool hasCore(const std::string &key);

        static void removeCore(const std::string &key);

        virtual ~Facade();

        static constexpr const char *MULTITON_MSG = "Facade instance for this Multiton key already constructed!";
    };
}

#endif //PUREMVC_FACADE_HPP
