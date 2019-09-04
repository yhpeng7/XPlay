//
// Created by Thinkad on 2019/9/4.
//

#ifndef FFMPEG_IOBSERVER_H
#define FFMPEG_IOBSERVER_H

#include "XData.h"
#include "XThread.h"
#include <vector>
#include <mutex>

class IObserver : public XThread{
public:
    //观察者接收数据函数
    virtual void update(XData data){}

    //主体函数 添加观察者
    void addObs(IObserver *obs);

    //通知所有观察者
    void notify(XData data);

protected:
    std::vector<IObserver *>obss;
    std::mutex mutex;
};


#endif //FFMPEG_IOBSERVER_H
