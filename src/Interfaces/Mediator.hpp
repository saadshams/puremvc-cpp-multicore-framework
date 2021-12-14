#ifndef PUREMVC_MEDIATOR_HPP
#define PUREMVC_MEDIATOR_HPP

#include <iostream>

namespace PureMVC::Patterns {
    class Mediator {
    protected:
        std::string _mediatorName;
        void const* _viewComponent;
    public:
        explicit Mediator(std::string const& mediatorName = NAME, void const* viewComponent = nullptr);

        virtual void onRegister();

        virtual void onRemove();

        virtual const char * const *listNotificationInterests();

        std::string getMediatorName() const;

        void setViewComponent(const void* viewComponent);

        const void* getViewComponent() const;

        virtual ~Mediator();

        constexpr static char const* const NAME = "Mediator";
    };
}

#endif //PUREMVC_MEDIATOR_HPP
