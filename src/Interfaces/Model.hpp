#ifndef PUREMVC_MODEL_HPP
#define PUREMVC_MODEL_HPP

#include "Interfaces/Proxy.hpp"
#include <iostream>
#include <map>

using PureMVC::Patterns::Proxy;

namespace PureMVC::Core {
    class Model {
    protected:
        std::string _multitonKey;
        std::map<std::string, Proxy *> _proxyMap;
        inline static std::map<std::string, Model *> _instanceMap;
    public:
        explicit Model(const std::string &key);

        void initializeModel();

        static Model *getInstance(const std::string &key, Model *(*factory)(std::string k));

        void registerProxy(Proxy *proxy);

        Proxy *retrieveProxy(const std::string &proxyName);

        Proxy *removeProxy(const std::string &proxyName);

        bool hasProxy(const std::string &proxyName);

        constexpr static char const *const MULTITON_MSG = "Model instance for this Multiton key already constructed!";

        ~Model();
    };
}

#endif //PUREMVC_MODEL_HPP
