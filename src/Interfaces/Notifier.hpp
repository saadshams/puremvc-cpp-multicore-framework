#ifndef PUREMVC_NOTIFIER_HPP
#define PUREMVC_NOTIFIER_HPP

#include <iostream>

namespace PureMVC::Patterns {

    class Facade; // forward declaration

    class Notifier {
    protected:
        std::string _multitonKey;
    public:
        virtual void initializeNotifier(const std::string &key);

        virtual void sendNotification(const std::string &name, const void *body = nullptr, const std::string &type = "");

        virtual Facade *getFacade();

        virtual ~Notifier();
    };
}

#endif //PUREMVC_NOTIFIER_HPP
