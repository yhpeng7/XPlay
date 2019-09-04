#include <jni.h>
#include <string>

#include "FFDemux.h"
#include "XLog.h"

class Obser : IObserver{
public:
    void update(XData data){
        LOGI("test")
    }
};

extern "C" JNIEXPORT void JNICALL Java_com_yhklsdf_ffmpeg_MainActivity_jni(
        JNIEnv *env,
        jobject obj) {

    Obser *obser = new Obser();
    IDemux *de = new FFDemux();
    de->addObs(obser);
    de->open("/storage/0403-0201/input.flv");
    de->start();
    xSleep(3000);
    de->stop();
}
