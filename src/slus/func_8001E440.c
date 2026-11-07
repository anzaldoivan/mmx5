#include "types.h"

extern s8 D_8009A424;
extern u8 D_800D1C00[];
extern void func_8002CF20(void);
extern void func_80012E0C(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_80020904(void);

void func_8001E440(u8* a0) {
    u8 v;

    if (D_8009A424 == 0) {
        switch (((s8*)a0)[2]) {
        case 0:
            func_8002CF20();
            D_800D1C00[0] = 0;
            D_800D1C00[1] = 0;
            D_800D1C00[2] = 0;
            D_800D1C00[3] = 0;
            func_80012E0C(1, func_80020904);
            func_80012EAC();
            break;
        case 1:
            v = 7;
            goto store; // !FAKE: goto kept for the matching branch layout
        case 2:
            v = 8;
        store: // !FAKE: label kept for the matching branch layout
            a0[0] = v;
            a0[1] = 0;
            a0[2] = 0;
            a0[3] = 0;
            break;
        default:
            func_8002CF20();
            D_800D1C00[0] = 0;
            D_800D1C00[1] = 0;
            D_800D1C00[2] = 0;
            D_800D1C00[3] = 0;
            D_800D1C00[0x79] = 10;
            func_80012E0C(1, func_80020904);
            func_80012EAC();
            break;
        }
    }
}
