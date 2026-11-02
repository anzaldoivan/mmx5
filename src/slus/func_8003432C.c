#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8 D_8009A0A0[];
extern s32 D_8009A420;
extern u8 D_800D1C00[];

void func_8003432C(u8* obj) {
    u8* b;
    s16* p;
    u32 i;
    s32 flag;
    s32 v;
    s32 t;

    if (!(D_8009A420 & 1)) {
        flag = 0;
        if (*(s32*)(obj + 0x34) != 0) {
            for (i = 0; i < 9; i++) {
                b = D_8009A0A0;
                p = (s16*)(b + 0xA8) + i;
                if (*p >= *(s16*)(b + 0x148)) {
                    *p = *(s16*)(b + 0x148);
                } else {
                    *p += 6;
                    if (*(s16*)(b + 0x148) < *p) {
                        *p = *(s16*)(b + 0x148);
                    } else {
                        flag = 1;
                    }
                }
            }
            if (flag) {
                goto tail; // !FAKE: goto kept for the matching branch layout
            }
            t = D_800D1C00[0x78] & 0x7F;
            v = t - 1;
            if (t != 0) {
                D_800D1C00[0x78] = v;
                return;
            }
            obj[5] = 1;
            *(s32*)(obj + 0x34) = 0;
            return;
        }
        i = 0;
        if (D_800D1C00[0x78] & 0x7F) {
            b = D_8009A0A0;
            for (p = (s16*)(b + 0xA8); i < 9; i++, p++) {
                if (!(*p < *(s16*)(b + 0x148))) {
                    *p = *(s16*)(b + 0x148);
                } else {
                    *p += 6;
                    if (!(*p < *(s16*)(b + 0x148))) {
                        *p = *(s16*)(b + 0x148);
                    } else {
                        flag = 1;
                    }
                }
            }
            if (flag) {
            tail:
                v = D_800D1C00[0x78] & 0x7F;
                if (v != 0) {
                    v--;
                }
                D_800D1C00[0x78] = v;
                if (!(D_8009A420 & 3)) {
                    func_80016490(0, 0x17, 0);
                }
                return;
            }
            t = D_800D1C00[0x78] & 0x7F;
            v = t - 1;
            if (t != 0) {
                D_800D1C00[0x78] = v;
                return;
            }
        }
        obj[5] = 1;
    }
}
