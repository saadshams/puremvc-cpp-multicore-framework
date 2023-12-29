#ifndef PUREMVC_NOTIFIER_HPP
#define PUREMVC_NOTIFIER_HPP

#include <iostream>

namespace PureMVC::Patterns {

    class Facade; // forward declaration

    class Notifier {
    protected:
        std::string multitonKey;
    public:
        virtual void initializeNotifier(const std::string &key);

        virtual void sendNotification(const std::string &name, const void *body, const std::string &type);

        virtual void sendNotification(const std::string &name, const void *body);

        virtual void sendNotification(const std::string &name);

        virtual Facade *getFacade();

        virtual ~Notifier();
    };
}

#endif //PUREMVC_NOTIFIER_HPP
