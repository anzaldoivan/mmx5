#include "types.h"

extern void func_80030D88(u8* a0);
extern u8 func_80030AE4(u8*, s16, s16);
extern s16 D_800E930A;
extern s16 D_800E930C;
extern s16 D_800E9316;
extern s16 D_800E9318;

static inline s32 func_8002F8FC_hit(u8 code) {
    switch (code) {
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0xA:
    case 0xB:
    case 0x10:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        return 1;
    }
    return 0;
}

void func_8002F8FC(u8* arg0) {
    if (arg0[0x70] != 0) {
        return;
    }
    if (*(s32*)(arg0 + 0x68) == 0) {
        return;
    }
    func_80030D88(arg0);
    if (func_8002F8FC_hit(func_80030AE4(arg0, D_800E9316 - D_800E930A,
                                        D_800E9318 - D_800E930C))) {
        arg0[0x70] |= 6;
        return;
    }
    if (func_8002F8FC_hit(func_80030AE4(arg0, D_800E9316 - D_800E930A,
                                        D_800E9318 + D_800E930C))) {
        arg0[0x70] |= 0xA;
        return;
    }
    if (func_8002F8FC_hit(func_80030AE4(arg0, D_800E9316 + D_800E930A,
                                        D_800E9318 - D_800E930C))) {
        arg0[0x70] |= 5;
        return;
    }
    if (func_8002F8FC_hit(func_80030AE4(arg0, D_800E9316 + D_800E930A,
                                        D_800E9318 + D_800E930C))) {
        arg0[0x70] |= 9;
    }
}
