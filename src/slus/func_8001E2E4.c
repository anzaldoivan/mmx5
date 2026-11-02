#include "types.h"

extern void func_800132F8(s32);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_80017D88(void);
extern s8 D_8009A424;
extern u16 D_800C931C[];

void func_8001E2E4(u8* obj) {
    if (D_8009A424 == 0) {
        if (D_800C931C[2] & 0x1000) {
            func_80016490(0, 0xC, 0);
            if (((s8*)obj)[2] == 0) {
                obj[2] = 3;
            } else {
                obj[2] = obj[2] - 1;
            }
        }
        if (D_800C931C[2] & 0x4000) {
            func_80016490(0, 0xC, 0);
            if (((s8*)obj)[2] == 3) {
                obj[2] = 0;
            } else {
                obj[2] = obj[2] + 1;
            }
        }
        if (D_800C931C[2] & 0x840) {
            func_80016490(0, 0x22, 0);
            func_800132F8(8);
            func_80017D88();
            obj[1]++;
        }
        if (D_800C931C[2] == 0) {
            *(u16*)(obj + 4) += 1;
            if (*(s16*)(obj + 4) > 0x4650) {
                func_80017D88();
                func_800132F8(8);
                *(u16*)(obj + 4) = 0;
                obj[1] += 2;
            }
        } else {
            *(u16*)(obj + 4) = 0;
        }
    }
}
