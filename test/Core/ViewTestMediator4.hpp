#ifndef PUREMVC_VIEWTESTMEDIATOR4_HPP
#define PUREMVC_VIEWTESTMEDIATOR4_HPP

#include "Interfaces/Mediator.hpp"
#include "ViewTestObject.hpp"

using PureMVC::Patterns::Mediator;

class ViewTestMediator4 : public Mediator {
public:
    explicit ViewTestMediator4(const ViewTestObject *object);

    void onRegister() override;

    void onRemove() override;

    [[nodiscard]] const ViewTestObject *viewTestObject() const;

    static constexpr const char *NAME = "ViewTestMediator4";
};

#endif //PUREMVC_VIEWTESTMEDIATOR4_HPP
