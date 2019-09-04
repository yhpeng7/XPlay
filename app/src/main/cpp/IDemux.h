//
// Created by Thinkad on 2019/9/4.
//

#ifndef FFMPEG_IDEMUX_H
#define FFMPEG_IDEMUX_H

#include "XData.h"
#include "XThread.h"
#include "IObserver.h"

//解封装接口
class IDemux : public IObserver{
public:
    //打开文件，或者流媒体 rmtp http rtsp
    virtual bool open(const char *url) = 0;

    //读取一帧数据，数据由调用者清理
    virtual XData read() = 0;

    //总时长（毫秒）
    int totalMs = 0;
protected:
    virtual void main();
};

#endif //FFMPEG_IDEMUX_H
