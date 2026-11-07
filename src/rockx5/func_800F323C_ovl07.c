#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern int func_8002D7A0();
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002E804(u8*, u8*);
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern u8 D_800D1DC0[];

void func_800F323C_ovl07(u8* arg0) {
    u8* p;

    p = D_8009A0A0;
    if (((s8*)p)[0xD5] != 0) {
        p = D_800D1DC0;
        if (((s8*)p)[5] == 0) {
            p += 0xB0;
        }
    }
    if (func_8002E804(arg0, p) != 0) {
        func_80016490(5, 0x23, 0);
        D_800D1C00[0x26]++;
        arg0[4]++;
    }
    func_80017248(arg0);
    if (func_8002D938(arg0, 0x40, 0x40) == 0) {
        func_8002D9EC(arg0, 0x20, 0x20);
        return;
    }
    func_8002D7A0(arg0);
}
