/* Shared body (DK-5), from the banked draft of func_800F0BCC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern u8 D_800F5374_ovl05[];
extern void (*D_800F538C_ovl05[])(u8*);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800F538C_ovl05[*(signed char*)(obj + 5)](obj);
        func_80017248(obj);
    }
    if (func_800317B8(obj) != 0) {
        if (*(signed char*)(obj + 2) != 0) {
            obj[3] = 0;
            func_8004D4F4(3, D_800F5374_ovl05, obj);
            func_8004FD24(obj);
            obj[4] = 2;
            return;
        }
    } else if (*(signed char*)(obj + 2) != 0 && func_80031DD0(obj) < 0) {
        obj[3] = 0;
        func_8004D4F4(3, D_800F5374_ovl05, obj);
        func_8004FD24(obj);
        obj[4] = 2;
        return;
    }
    if (func_8002D938(obj, 0x20, 0x20) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4] = 2;
    }
}
