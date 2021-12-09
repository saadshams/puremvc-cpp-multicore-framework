#ifndef PUREMVC_PROXY_H
#define PUREMVC_PROXY_H

#include <iostream>

using std::string;

namespace PureMVC::Patterns {
    class Proxy {
    protected:
        string _proxyName;
        void const* _data;
    public:
        explicit Proxy(string const& proxyName = NAME, void const* data = nullptr);

        virtual void onRegister();

        virtual void onRemove();

        string proxyName();

        void setData(const void* data);

        void const* getData();

        virtual ~Proxy();

        constexpr static char const* const NAME = "Proxy";
    };
}

#endif //PUREMVC_PROXY_H
