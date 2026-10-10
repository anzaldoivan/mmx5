#include "types.h"

extern u8 D_8009A0A0[];
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8002E274(u8* a0, u8* a1);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F0370_ovl10(u8* obj) {
    u8* g = D_8009A0A0;

    if (g[0xF7] == 0) {
        func_80017248(obj);
        func_8002DF54(obj);
    }
    if (func_800317B8(obj) == 0) {
        if (func_80031DD0(obj) < 0) {
            goto dead;
        }
        if (func_8002E274(obj, g) == 0) {
            if (obj[0x70] != 0) {
            dead:
                func_8004FD24(obj);
                obj[4]++;
                return;
            }
            if (func_8002D938(obj, 0x20, 0x20) == 0) {
                func_8002D9EC(obj, 0x10, 0x10);
                return;
            }
        }
    }
    obj[4]++;
}
