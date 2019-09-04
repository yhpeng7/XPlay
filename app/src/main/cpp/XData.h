//
// Created by Thinkad on 2019/9/4.
//

#ifndef FFMPEG_XDATA_H
#define FFMPEG_XDATA_H

class XData {
public:
    unsigned char *data = 0;
    int size = 0;

    void drop();
};


#endif //FFMPEG_XDATA_H
