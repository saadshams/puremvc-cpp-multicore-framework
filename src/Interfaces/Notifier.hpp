#ifndef PUREMVC_NOTIFIER_HPP
#define PUREMVC_NOTIFIER_HPP

#include <iostream>

namespace PureMVC::Patterns {

    class Facade; // forward declaration

    class Notifier {
    protected:
        std::string _multitonKey;
    public:
        void initializeNotifier(const std::string &key);

        void
        sendNotification(const std::string &notificationName, const void *body = nullptr, const std::string &type = "");

        Facade *getFacade();
    };
}

#endif //PUREMVC_NOTIFIER_HPP