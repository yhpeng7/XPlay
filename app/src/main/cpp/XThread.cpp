//
// Created by Thinkad on 2019/9/4.
//
#include <thread>
#include "XThread.h"
#include "XLog.h"
using namespace std;

void xSleep(int mis){
    chrono::milliseconds du(mis);
    this_thread::sleep_for(du);
}

void XThread::start() {
    isExit = false;
    thread th(&XThread::threadMain, this);
    th.detach();
}

void XThread::threadMain() {
    isRunning = true;
    main();
    isRunning = false;
}

void XThread::stop() {
    isExit = true;
    for (int i = 0; i < 200; ++i) {
        if (!isRunning) {
            return;
        }
        xSleep(1);
    }
    LOGI("停止线程超时。")
}

