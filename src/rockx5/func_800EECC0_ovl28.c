#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_8003CE64(u8* obj);
extern void func_8003EC00(u8* obj);
extern void func_8003ED10(u8* obj);
extern void func_80017248(u8* obj);
extern s8 D_800D1C0F;

void func_800EECC0_ovl28(u8* obj) {
    s8 state = ((s8*)obj)[6];

    if (state == 0) {
        func_8003B33C(obj, 0x51);
        func_8003CE64(obj);
        func_8003EC00(obj);
        func_8003ED10(obj);
        goto next; // !FAKE: goto kept for the matching branch layout
    } else if (state == 1) {
        func_80017248(obj);
        if (D_800D1C0F != 0) {
        next:
            obj[6]++;
        }
    } else {
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
    }
}
