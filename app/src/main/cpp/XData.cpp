//
// Created by Thinkad on 2019/9/4.
//

#include "XData.h"
extern "C"{
#include <libavcodec/avcodec.h>
}
void XData::drop() {
    if (!data) {
        return;
    }
    av_packet_free((AVPacket **) &data);
    data = nullptr;
    size = 0;
}