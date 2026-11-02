#include "types.h"

extern u8 D_8009A197;
extern void (*D_800F96D8_ovl29[])(u8*);
extern u8 D_800F96B8_ovl29[];
extern void func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8005446C(u8* a0, s32 a1, s16 a2, s16 a3);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F2144_ovl29(u8* obj) {
    s32 r;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800F96D8_ovl29[((s8*)obj)[5]](obj);
    }
    if (*(s32*)(obj + 0x90) != 0) {
        func_800317B8(obj);
        *(s32*)(obj + 0x94) = ((s8*)obj)[5];
        if (func_80031DD0(obj) < 0) {
            func_8004FD24(obj);
            func_8004D4F4(5, D_800F96B8_ovl29, obj);
            if (!(obj[2] & 1)) {
                func_8005446C(obj, 0xE, *(s16*)(obj + 0xA) - 10,
                              *(s16*)(obj + 0xE));
            } else {
                func_8005446C(obj, 0xE, *(s16*)(obj + 0xA) + 10,
                              *(s16*)(obj + 0xE));
            }
            r = 2;
            goto store; // !FAKE: goto kept for the matching branch layout
        }
    }
    if (func_8002D938(obj, 0x40, 0x40) == 0) {
        if ((*(s32*)(obj + 4) & 0xFFFF00) != 0x200) {
            func_8002D9EC(obj, 0x20, 0x20);
        }
        return;
    }
    r = 3;
store:
    obj[4] = r;
}
