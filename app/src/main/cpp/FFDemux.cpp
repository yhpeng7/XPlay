//
// Created by Thinkad on 2019/9/4.
//

#include "FFDemux.h"
#include "XLog.h"
extern "C"{
#include <libavformat/avformat.h>
}

bool FFDemux::open(const char *url){
    int re = avformat_open_input(&ic, url, nullptr, nullptr);
    if (re != 0) {
        char buff[1024] = {0};
        av_strerror(re,buff, sizeof(buff));
        LOGE("avformat_open_input failed: %s",buff)
        return false;
    }

    //读取文件信息
    re = avformat_find_stream_info(ic, nullptr);
    if (re != 0) {
        char buff[1024] = {0};
        av_strerror(re,buff, sizeof(buff));
        LOGE("avformat_find_stream_info: %s",buff)
        return false;
    }

    this->totalMs = static_cast<int>(ic->duration / (AV_TIME_BASE / 1000));

    return true;
}

XData FFDemux::read(){
    XData d;
    if (!ic) {
        return {};
    }
    AVPacket *pkt = av_packet_alloc();
    int re = av_read_frame(ic, pkt);
    if (re != 0) {
        //读到结尾时释放内存
        av_packet_free(&pkt);
        return {};
    }
    d.data = (unsigned char *) pkt;
    d.size = pkt->size;

    return d;
}

FFDemux::FFDemux(){
    static bool isFirst = true;
    if (isFirst) {
        //注册所有的解封装器
        av_register_all();

        //注册所有的解码器
        avcodec_register_all();

        //初始化网络
        avformat_network_init();
        isFirst = false;
    }
}