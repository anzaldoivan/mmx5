#include "types.h"

extern u8* func_8002D078();
extern void func_80017248(u8* obj);
extern s32 func_80044730(u8* arg0);
extern void func_8003A670(u8* arg0);

void func_80043F10(u8* obj) {
    s8 state = ((s8*)obj)[6];
    u8* p;

    if (state == 0) {
        p = func_8002D078();
        if (p != 0) {
            p[0] = 0x11;
            p[1] = 0x1D;
        }
        obj[6]++;
    } else if (state == 1) {
        func_80017248(obj);
        func_80044730(obj);
    } else if (state == 2) {
        func_8003A670(obj);
    }
}
