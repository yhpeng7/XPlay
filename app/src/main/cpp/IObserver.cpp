//
// Created by Thinkad on 2019/9/4.
//

#include "IObserver.h"

void IObserver::addObs(IObserver *obs) {
    if (!obs) return;
    mutex.lock();
    obss.push_back(obs);
    mutex.unlock();
}

void IObserver::notify(XData data) {
    mutex.lock();
    int size = obss.size();
    for (int i = 0; i < size; ++i) {
        obss[i]->update(data);
    }
    mutex.unlock();
}
