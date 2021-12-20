#ifndef PUREMVC_MODELTESTPROXY_HPP
#define PUREMVC_MODELTESTPROXY_HPP

#include <iostream>
#include "Interfaces/Proxy.hpp"

using PureMVC::Patterns::Proxy;

class ModelTestProxy: public Proxy {
public:
    explicit ModelTestProxy();

    void onRegister() override;

    void onRemove() override;

    constexpr static char const *const NAME = "ModelTestProxy";

    constexpr static char const *const ON_REGISTER_CALLED = "onRegister Called";

    constexpr static char const *const ON_REMOVE_CALLED = "onRemove Called";
};

#endif //PUREMVC_MODELTESTPROXY_HPP
