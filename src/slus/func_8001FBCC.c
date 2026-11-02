#include "types.h"

extern void func_80012E0C(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_8001CC34(u8*, u8*);
extern u8 D_80070C54;
extern u8 D_8009A1F8[];
extern u8 D_8009A420[];
extern u8 D_800C9310;
extern u8 D_800D1C00[];
extern void func_80020904(void);

void func_8001FBCC(u8* arg0) {
    u8* p;

    if ((s8)D_8009A420[4] == 0) {
        if (D_8009A420[7] != 1) {
            D_800C9310 |= 1;
        }
        switch (*(s16*)(arg0 + 0xA)) {
        case 0:
            func_8001CC34(&D_80070C54, arg0);
            if (D_800D1C00[0x194] == 0xFF) {
                D_800D1C00[0] = 3;
                D_800D1C00[1] = 0;
                D_800D1C00[2] = 0;
                D_800D1C00[3] = 0;
            } else {
                D_800D1C00[0] = 0x13;
                D_800D1C00[1] = 0;
                D_800D1C00[2] = 0;
                D_800D1C00[3] = 0;
                D_800D1C00[0x1D] = D_800D1C00[0x194];
            }
            func_80012E0C(1, func_80020904);
            func_80012EAC();
            return;
        case 1:
            arg0[0] = 9;
            D_800D1C00[1] = 0;
            D_800D1C00[2] = 0;
            D_800D1C00[3] = 0;
            return;
        case 2: // !FAKE: rebalances the case tree
        default:
            p = D_8009A1F8;
            *(s16*)(p + 0xA) = 0;
            *(s16*)(p + 0xE) = 0;
            p[0x4C] = 1;
            p[3] = 1;
            arg0[0] = 6;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            break;
        }
    }
}
