#ifndef PUREMVC_VIEW_HPP
#define PUREMVC_VIEW_HPP

#include <iostream>
#include <map>
#include "Mediator.hpp"
#include "Notification.hpp"
#include "Observer.hpp"

using PureMVC::Patterns::Mediator;
using PureMVC::Patterns::Notification;
using PureMVC::Patterns::Observer;

namespace PureMVC::Core {
    class View {
    protected:
        std::string multitonKey;
        std::map<std::string, Mediator *> mediatorMap{};
        std::map<std::string, std::vector<Observer *>> observerMap{};
        inline static std::map<std::string, View *> instanceMap;
    public:
        explicit View(const std::string &key);

        static View *getInstance(const std::string &key, const std::function<View *(const std::string &k)> &factory);

        virtual void initializeView();

        void registerObserver(const std::string &notificationName, Observer *observer);

        void notifyObservers(Notification *notification);

        void removeObserver(const std::string &notificationName, const void *notifyContext);

        virtual void registerMediator(Mediator *mediator);

        virtual Mediator *retrieveMediator(const std::string &mediatorName);

        virtual Mediator *removeMediator(const std::string &mediatorName);

        virtual bool hasMediator(const std::string &mediatorName);

        static void removeView(const std::string &key);

        virtual ~View();

        static constexpr const char *MULTITON_MSG = "View instance for this Multiton key already constructed!";
    };
}

#endif //PUREMVC_VIEW_HPP
