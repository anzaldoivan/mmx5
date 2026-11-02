#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern u8 D_80076D80[];
extern u8 D_8009A0B4;
extern u8 D_800F9628_ovl26[];
extern u8 D_800F9658_ovl26[];
extern u8 D_800F965C_ovl26[];
extern u8 D_800F9664_ovl26[];

void func_800F35B8_ovl26(u8* obj) {
    s8 kind;

    kind = *(s8*)(obj + 2);
    obj[4] = 1;
    obj[6] = 0;
    obj[0x14] = D_8009A0B4;
    if (kind < 16) {
        obj[0x16] = 5;
        obj[0x60] = 6;
        *(u8**)(obj + 0x58) = D_80076D80;
        *(u8**)(obj + 0x54) = D_800F9658_ovl26;
        *(u8**)(obj + 0x50) = D_800F965C_ovl26;
        *(s32*)(obj + 0x68) = 0;
        if (*(s32*)(obj + 0x24) == 0) {
            obj[5] = 0;
            func_800171E8(obj, 1);
            func_80016490(2, 0x5E, obj);
        } else {
            obj[5] = 3;
            func_800171E8(obj, 3);
            (*(u8**)(obj + 0x7C))[0x97] = 1;
            *(s16*)(obj + 0x90) = (func_8002DF78() & 0xF) + 1;
        }
    } else if (kind == 16) {
        func_80016490(2, 0x62, obj);
        obj[0x16] = 4;
        obj[0x60] = 0xC;
        obj[5] = 2;
        func_800171E8(obj, 0xA);
        *(u8**)(obj + 0x58) = 0;
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_800F9664_ovl26;
        *(s32*)(obj + 0x68) = 0;
    } else if (kind == 17) {
        obj[0x16] = 7;
        obj[0x60] = 0x20;
        obj[5] = 4;
        func_800171E8(obj, 0xE);
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_800F9628_ovl26;
        *(s32*)(obj + 0x68) = 0;
    }
}
