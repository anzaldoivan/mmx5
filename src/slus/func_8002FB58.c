#include "types.h"

extern void func_80030D88(u8* a0);
extern void func_8002FFCC(u8* arg0);
extern void func_8002FEAC(u8* arg0);
extern void func_800300F0(u8* arg0);
extern void func_80030FA4(u8* arg0);
extern void func_80030E1C(u8* arg0);
extern void func_80030E60(u8* arg0);
extern void func_800311CC(u8* arg0);
extern void func_8003049C(u8* arg0);
extern void func_8002FCC8(u8* arg0);
extern u8 D_800E9308;
extern u8 D_800E9309;
extern u16 D_800E931C;

void func_8002FB58(u8* arg0) {
    s32 d;

    arg0[0x70] = 0;
    arg0[0x79] = 0;
    if (*(s32*)(arg0 + 0x68) == 0) {
        return;
    }
    func_80030D88(arg0);
    D_800E9308 = 0;
    D_800E9309 = 0;
    d = *(s32*)(arg0 + 0x8) - *(s32*)(arg0 + 0x18);
    if (d != 0) {
        if (d > 0) {
            func_8002FFCC(arg0);
        } else {
            func_8002FEAC(arg0);
        }
    }
    if (*(s32*)(arg0 + 0xC) - *(s32*)(arg0 + 0x1C) >= 0) {
        func_800300F0(arg0);
        if (D_800E9308 != 0) {
            return;
        }
    } else {
        func_80030FA4(arg0);
    }
    if (D_800E9309 & 0xC) {
        if (D_800E9309 & 4) {
            D_800E9309 |= 4;
        }
        if (D_800E9309 & 3) {
            if ((D_800E9309 & 4) || ((s16)D_800E931C >= -8)) {
                func_80030E1C(arg0);
            } else {
                func_80030E60(arg0);
            }
        } else {
            func_800311CC(arg0);
        }
    } else if (D_800E9309 & 3) {
        func_8003049C(arg0);
    }
    func_8002FCC8(arg0);
}
