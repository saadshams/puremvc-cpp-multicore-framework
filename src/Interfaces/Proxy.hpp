#ifndef PUREMVC_PROXY_HPP
#define PUREMVC_PROXY_HPP

#include <iostream>
#include "Notifier.hpp"

using PureMVC::Patterns::Notifier;

namespace PureMVC::Patterns {
    class Proxy : public Notifier {
    protected:
        std::string _proxyName;
        const void *_data;
    public:
        explicit Proxy(const std::string &proxyName = NAME, const void *data = nullptr);

        virtual void onRegister();

        virtual void onRemove();

        [[nodiscard]] virtual const std::string &getProxyName() const;

        virtual void setData(const void *data);

        [[nodiscard]] virtual const void *getData() const;

        virtual ~Proxy();

        static constexpr const char *NAME = "Proxy";
    };
}

#endif //PUREMVC_PROXY_HPP
