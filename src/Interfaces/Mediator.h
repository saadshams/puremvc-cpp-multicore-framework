#ifndef PUREMVC_MEDIATOR_H
#define PUREMVC_MEDIATOR_H

#include <iostream>

using std::string;

namespace PureMVC::Patterns {
    class Mediator {
    protected:
        string _mediatorName;
        void const* _viewComponent;
    public:
        explicit Mediator(string const& mediatorName = NAME, void const* viewComponent = nullptr);

        virtual void onRegister();

        virtual void onRemove();

        virtual const char * const *listNotificationInterests();

        string getMediatorName();

        void setViewComponent(const void* viewComponent);

        const void* getViewComponent();

        virtual ~Mediator();

        constexpr static char const* const NAME = "Mediator";
    };
}

#endif //PUREMVC_MEDIATOR_H
