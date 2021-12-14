#ifndef PUREMVC_PROXY_HPP
#define PUREMVC_PROXY_HPP

#include <iostream>

namespace PureMVC::Patterns {
    class Proxy {
    protected:
        std::string _proxyName;
        void const* _data;
    public:
        explicit Proxy(std::string const& proxyName = NAME, void const* data = nullptr);

        virtual void onRegister();

        virtual void onRemove();

        [[nodiscard]] std::string getProxyName() const;

        void setData(const void* data);

        [[nodiscard]] void const* getData() const;

        virtual ~Proxy();

        constexpr static char const* const NAME = "Proxy";
    };
}

#endif //PUREMVC_PROXY_HPP
