#include "types.h"
#include "mmx5/globals.h"

extern void func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern void func_800326BC(u8* a0);
extern s32 func_80032F70(u8* a0);
extern u8 D_800767E0[];
extern u8 D_80076BA0[];
extern u8 D_8009A198;

void func_800F3000_ovl03(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    animate_object(obj);
    *(u8**)(obj + 0x58) = D_800767E0;
    if ((s8)func_80032F70(obj) == 0) {
        *(u8**)(obj + 0x58) = D_80076BA0;
        if ((s8)func_80031DD0(obj) < 0) {
            *(s32*)(obj + 0x20) = 0;
            *(u16*)(obj + 0x42) &= 0x7FFF;
            ((s32(*)())func_8004FD90)(obj, 1, 0x1F, 0x3F);
            ((s32(*)())func_8004FD90)(obj, 1, 0x1F, 0x3F);
            ((s32(*)())func_8004FD90)(obj, 1, 0x1F, 0x3F);
            ((s32(*)())func_8004FD90)(obj, 1, 0x1F, 0x3F);
            obj[4] = 3;
            return;
        }
    }
    ((void (*)())func_80033024)(obj);
    if (D_8009A198 == 0) {
        func_8003240C(obj);
    }
    func_800326BC(obj);
    func_8003258C(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
