#include "MediatorTest.hpp"
#include "Interfaces/Mediator.hpp"

using PureMVC::Patterns::Mediator;

int main() {
    testNameAccessor();
    testViewAccessor();
    testListNotificationInterests();
    std::cout << "Mediator Tests Passed";
    return 0;
}

void testNameAccessor() {
    auto *mediator = new Mediator();
    assert(mediator->getMediatorName() == Mediator::NAME);
    mediator->onRegister();
    mediator->onRemove();

    delete mediator;
}

void testViewAccessor() {
    struct View {} view;
    auto *mediator = new Mediator(Mediator::NAME, &view);
    assert(mediator->getViewComponent() == &view);

    struct View2 {} view2;
    mediator->setViewComponent(&view2);
    assert(mediator->getViewComponent() == &view2);

    delete mediator;
}

void testListNotificationInterests() {
    struct View {} view;
    auto *mediator = new Mediator(Mediator::NAME, &view);

    const char * const *interests = mediator->listNotificationInterests();

    int i = 0;
    for (const char * const *cursor = interests; *cursor != nullptr; cursor++) {
        i++;
    }

    // test assertions
    assert(i == 0);

    delete mediator;
}
