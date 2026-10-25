#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern int func_80045D44();
extern u8 D_8009A0A0[];
extern s32 D_80077144[];

void func_8004A0D4(u8* obj) {
    u8* p = D_8009A0A0;

    if (*(s8*)(p + 0x8E) == 0) {
        func_800171E8(obj, 1);
        *(s32*)(obj + 0x50) = 0;
        obj[4] = 2;
    } else {
        func_80017248(obj);
        func_80045D44(obj, p, ((s8*)obj)[1]);
        if (obj[0x15] != 0) {
            *(u16*)(obj + 0xA) += 0x84;
        } else {
            *(u16*)(obj + 0xA) -= 0x84;
        }
        *(s32**)(obj + 0x50) = &D_80077144[((s8*)obj)[0x45]];
    }
}
