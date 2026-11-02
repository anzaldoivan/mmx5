#include "types.h"

extern u8 D_8009A0A0[];
extern s8 D_800D1C00[];
extern u8 D_8009A1F8[];
extern void* D_800F3DC8_ovl02[];
extern s32 D_8009A420;
extern u8 D_800F4918_ovl02[];
extern u8 D_800F3DA8_ovl02[];
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);

void func_800EE988_ovl02(u8* obj) {
    u8* g = D_8009A0A0;
    u8* s;

    if (*(s16*)(g + 0xA) > 0x1520) {
        if (D_800D1C00[0xF] == 0) {
            D_800D1C00[0xF] = 1;
        }
    }
    if (D_8009A0A0[0xF7] != 0) {
        u8* t = D_8009A1F8;
        *(s16*)(t + 0xB6) = 0x2F0;
        t[0xF4] = 1;
        return;
    }
    s = D_8009A1F8;
    *(s16*)(s + 0xB6) = 0x1E0;
    s[0xF4] = 1;
    ((void (*)(u8*))D_800F3DC8_ovl02[(s8)obj[4]])(obj);
    if (D_8009A420 % 5 == 0) {
        *(s16*)(s + 0xB2) += 0x160;
        if (*(s16*)(s + 0xB2) >= 0x840) {
            *(s16*)(s + 0xB2) = 0;
        }
        s[0xF4] = 1;
    }
    if ((s8)obj[0x16] != D_800D1C00[0x27]) {
        func_8002C3CC(D_800F4918_ovl02, D_800F3DA8_ovl02, 0x100,
                      0x1F - D_800D1C00[0x27], 0x1F);
        func_8002C338(0x4A, D_800F4918_ovl02, 1);
        obj[0x16] = D_800D1C00[0x27];
    }
}
