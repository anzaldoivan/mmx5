#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern void func_80044F78(void* arg0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];

void func_800457DC(u8* arg0) {
    s32 d;
    s32 lim;
    u8* g;

    if (func_8002D938(arg0, *(s16*)(arg0 + 0x8E), *(s16*)(arg0 + 0x90)) == 0) {
        func_80017248(arg0);
        if (*(s8*)(arg0 + 0x98) == 0) {
            func_8002DF54(arg0);
            if (arg0[0x70] != 0 || (func_8002F8FC(arg0), arg0[0x70] != 0)) {
                func_80044F78(arg0);
            } else {
                lim = *(s16*)(arg0 + 0x92);
                d = *(s16*)(arg0 + 0x8C) - *(s16*)(arg0 + 0xA);
                if ((d >= 0)
                        ? (lim < d)
                        : (lim < *(s16*)(arg0 + 0xA) - *(s16*)(arg0 + 0x8C))) {
                    g = D_8009A0A0;
                    arg0[3] = 0;
                    arg0[4] = 3;
                    *(s32*)(arg0 + 0x50) = 0;
                    *(s32*)(arg0 + 0x68) = 0;
                    g[0x98]--;
                    arg0[4] = 2;
                    if (*(s8*)(arg0 + 1) == 0x2D) {
                        func_800171E8(arg0, 1);
                    } else {
                        func_800171E8(arg0, 2);
                    }
                }
                func_8002D9EC(arg0, *(s16*)(arg0 + 0x8E), *(s16*)(arg0 + 0x90));
                return;
            }
        }
    }
    arg0[3] = 0;
    arg0[4] = 3;
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x68) = 0;
}
