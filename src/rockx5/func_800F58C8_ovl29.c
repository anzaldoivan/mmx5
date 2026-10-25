#include "types.h"

extern void func_8002D9EC(u8* obj, s32 a, s32 b);
extern int func_8002D6FC();
extern s8 D_800D1C0F;

void func_800F58C8_ovl29(u8* obj) {
    s8* child = *(s8**)(obj + 0x80);

    if (child[0] != 0) {
        if (child[7] == 0) {
            if (--*(s16*)(obj + 0x7E) == -1) {
                *(s16*)(obj + 0x7E) = 5;
                *(u16*)(obj + 0x42) ^= 0x8000;
            }
            func_8002D9EC(obj, 0x40, 0x40);
        }
    } else {
        D_800D1C0F = 0x10;
        func_8002D6FC();
    }
}
