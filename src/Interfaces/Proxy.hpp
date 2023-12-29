#ifndef PUREMVC_PROXY_HPP
#define PUREMVC_PROXY_HPP

#include <iostream>
#include "Notifier.hpp"

using PureMVC::Patterns::Notifier;

namespace PureMVC::Patterns {
    class Proxy : public Notifier {
    protected:
        std::string proxyName;
        const void *data;
    public:
        explicit Proxy(const std::string &proxyName = NAME, const void *data = nullptr);

        virtual void onRegister();

        virtual void onRemove();

      virtual const std::string &getProxyName() const;

        virtual void setData(const void *data);

        virtual const void *getData() const;

        ~Proxy() override;

        static constexpr const char *NAME = "Proxy";
    };
}

#endif //PUREMVC_PROXY_HPP
