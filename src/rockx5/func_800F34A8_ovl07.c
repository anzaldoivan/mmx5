#include "types.h"

extern u8 D_8009A197;
extern void (*D_8010112C_ovl07[])(u8*);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F34A8_ovl07(u8* obj) {
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_8010112C_ovl07[*(signed char*)(obj + 5)](obj);
        func_80017248(obj);
    }
    func_800317B8(obj);
    func_80031DD0(obj);
    if (func_8002D938(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 3;
}
