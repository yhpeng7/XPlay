//
// Created by Thinkad on 2019/9/4.
//

#ifndef FFMPEG_FFDEMUX_H
#define FFMPEG_FFDEMUX_H
#include "IDemux.h"
struct AVFormatContext;
class FFDemux : public IDemux{
public:
    //表示重载了IDemux的函数
    virtual bool open(const char *url);

    virtual XData read();

    FFDemux();

private:
    AVFormatContext *ic = 0;
};


#endif //FFMPEG_FFDEMUX_H
