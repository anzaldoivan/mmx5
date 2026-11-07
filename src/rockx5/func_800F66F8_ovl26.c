#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern u8 D_8009A0B4;
extern s32 D_800FA2AC_ovl26[];
extern s32 D_800FA2CC_ovl26[];

void func_800F66F8_ovl26(u8* obj) {
    obj[0x14] = D_8009A0B4;
    if (((s8*)obj)[2] == 0) {
        func_80016490(2, 0x64, obj);
        obj[0x16] = 4;
        func_800171E8(obj, 0x18);
    } else {
        obj[0x16] = 4;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x5000;
        *(s32*)(obj + 0x20) = D_800FA2AC_ovl26[func_8002DF78() & 7];
        *(s32*)(obj + 0x24) = D_800FA2CC_ovl26[func_8002DF78() & 7];
        func_800171E8(obj, 0);
    }
    obj[4] = 1;
    obj[6] = 0;
}
