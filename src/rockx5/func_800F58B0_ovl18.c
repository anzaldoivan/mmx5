#include "types.h"

extern void func_80032F70(u8*);
extern void func_80033024(u8*);
extern s32 func_800326BC(u8*);
extern void func_8002D89C(u8*);
extern s32 func_8003240C(u8*);
extern void func_8003258C(u8*);
extern s32 func_8002FB58(u8*);
extern void (*D_800F7F88_ovl18[])(u8*);

void func_800F58B0_ovl18(u8* arg0) {
    func_80032F70(arg0);
    func_80033024(arg0);
    func_800326BC(arg0);
    D_800F7F88_ovl18[*(s8*)(arg0 + 6)](arg0);
    if (*(s8*)(arg0 + 6) >= 2) {
        func_8002D89C(arg0);
    }
    func_8003240C(arg0);
    func_8003258C(arg0);
    if (arg0[0x70] & 8) {
        arg0[0x67] = 0;
    } else {
        s32 v = *(s32*)(arg0 + 0x24);
        if (v < 0) {
            v = -1;
        } else {
            v = 1;
        }
        arg0[0x67] = v;
    }
    func_8002FB58(arg0);
}
