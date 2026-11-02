#include "types.h"

extern s8 D_800D1C00[];
extern void* D_8007486C[];

void func_8003C0EC(u8* obj) {
    s8* d;
    s32 idx;
    u8 v;

    if (((s8*)obj)[0xF0] == 0) {
        d = D_800D1C00;
        if (d[0x1E] != 0) {
            obj[3] = 1;
            d[0x1F] = 1;
            idx = 0;
            switch (d[0xC]) {
            case 6:
                if (d[0x1E] != -1 || d[0x1D] == 0) {
                    break;
                }
            case 9:
            case 10:
                idx = 1;
                break;
            case 5:
                idx = (d[0x1D] == 0) << 1;
                break;
            case 12:
                if (d[0xD] == 0) {
                    v = d[0x1D];
                    if (v >= 2 && v <= 18) {
                        idx = (s8)v != 10;
                    }
                }
                break;
            }
            obj[4]++;
            ((void (*)(u8*))D_8007486C[idx])(obj);
        }
    }
}
