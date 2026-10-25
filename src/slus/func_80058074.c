#include "types.h"

extern s16 D_8007DC74[][3];
extern u8 D_8009A197;
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80057EDC(u8* a0);
extern int func_8002D760();

void func_80058074(u8* a0) {
    if (func_8002D938(a0, D_8007DC74[((s8*)a0)[2]][1],
                      D_8007DC74[((s8*)a0)[2]][2]) == 0) {
        if (D_8009A197 == 0) {
            func_80057EDC(a0);
        }
    } else if (a0[0x15] == 0) {
        if (((s8*)a0)[2] == 8) {
            func_8002D760(a0);
        } else {
            func_8002D760(a0);
        }
    }
}
