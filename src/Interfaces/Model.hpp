#ifndef PUREMVC_MODEL_HPP
#define PUREMVC_MODEL_HPP

#include <iostream>
#include <map>
#include "Proxy.hpp"

using PureMVC::Patterns::Proxy;

namespace PureMVC::Core {
    class Model {
    protected:
        std::string _multitonKey;
        std::map<std::string, Proxy *> _proxyMap;
        inline static std::map<std::string, Model *> _instanceMap;
    public:
        explicit Model(const std::string &key);

        static Model *getInstance(const std::string &key, const std::function<Model *(const std::string &k)> &factory);

        virtual void initializeModel();

        virtual void registerProxy(Proxy *proxy);

        virtual Proxy *retrieveProxy(const std::string &proxyName);

        virtual Proxy *removeProxy(const std::string &proxyName);

        virtual bool hasProxy(const std::string &proxyName);

        static void removeModel(const std::string &key);

        virtual ~Model();

        static constexpr const char *MULTITON_MSG = "Model instance for this Multiton key already constructed!";
    };
}

#endif //PUREMVC_MODEL_HPP
