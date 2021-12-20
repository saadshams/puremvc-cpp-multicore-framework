#include "ModelTestProxy.hpp"

ModelTestProxy::ModelTestProxy(): Proxy(NAME, "") {

}

void ModelTestProxy::onRegister() {
    setData(ON_REGISTER_CALLED);
}

void ModelTestProxy::onRemove() {
    setData(ON_REMOVE_CALLED);
}
