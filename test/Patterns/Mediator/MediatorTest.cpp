#include "MediatorTest.h"
#include "Interfaces/Mediator.h"

using PureMVC::Patterns::Mediator;

int main() {
    testNameAccessor();
    testViewAccessor();
    testListNotificationInterests();
}

void testNameAccessor() {
    Mediator mediator = Mediator();
    assert(mediator.getMediatorName() == Mediator::NAME);
    mediator.onRegister();
    mediator.onRemove();
}

void testViewAccessor() {
    struct View {} view;
    Mediator mediator = Mediator(Mediator::NAME, &view);
    assert(mediator.getViewComponent() == &view);

    struct View2 {} view2;
    mediator.setViewComponent(&view2);
    assert(mediator.getViewComponent() == &view2);
}

void testListNotificationInterests() {
    struct View {} view;
    auto mediator = Mediator(Mediator::NAME, &view);

    const char * const *interests = mediator.listNotificationInterests();

    int i = 0;
    for (const char * const *cursor = interests; *cursor != nullptr; cursor++) {
        i++;
    }

    // test assertions
    assert(i == 0);
}
