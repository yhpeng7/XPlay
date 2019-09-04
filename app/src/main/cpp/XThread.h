//
// Created by Thinkad on 2019/9/4.
//

#ifndef FFMPEG_XTHREAD_H
#define FFMPEG_XTHREAD_H

void xSleep(int mis);

class XThread {
public:
    //启动线程
    virtual void start();
    //通过控制isExit安全停止线程（不一定成功）
    virtual void stop();
    //入口函数
    virtual void main(){};
protected:
    bool isExit = false;
    bool isRunning = false;
private:
    void threadMain();
};


#endif //FFMPEG_XTHREAD_H
