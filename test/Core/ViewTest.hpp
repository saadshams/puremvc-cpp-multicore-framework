#ifndef PUREMVC_VIEWTEST_HPP
#define PUREMVC_VIEWTEST_HPP

int main();

void testGetInstance();

void testRegisterAndNotifyObserver();

void testRegisterAndRetrieveMediator();

void testHasMediator();

void testRegisterAndRemoveMediator();

void testOnRegisterAndOnRemove();

void testSuccessiveRegisterAndRemoveMediator();

void testRemoveMediatorAndSubsequentNotify();

void testRemoveOneOfTwoMediatorsAndSubsequentNotify();

void testMediatorReregistration();

void testModifyObserverListDuringNotification();

#endif //PUREMVC_VIEWTEST_HPP
