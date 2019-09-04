//
// Created by Thinkad on 2019/9/4.
//

#include "IDemux.h"

void IDemux::main() {
    while (!isExit) {
        XData data = read();
        if (data.size > 0) {
            notify(data);
        }
    }
}