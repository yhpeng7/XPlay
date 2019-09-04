//
// Created by Thinkad on 2019/9/4.
//

#ifndef FFMPEG_XLOG_H
#define FFMPEG_XLOG_H

class XLog {

};


#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"XPlay",##__VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"XPlay",##__VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"XPlay",##__VA_ARGS__);


#endif //FFMPEG_XLOG_H
