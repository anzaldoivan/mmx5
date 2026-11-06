#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern s16 D_8009A220[];
extern s8 D_800D1C1C;
extern s8 D_800D1C1D;
extern s8 D_800D1C27;
extern s32 D_800E92F8;

void func_80054E84(u8* obj) {
    s8 kind;
    u8* p;

    if (((s8*)obj)[0x45] < 2) {
        func_80017248(obj);
        if (((s8*)obj)[0x45] == 1) {
            func_80016490(0, 0x10, obj);
            obj[0x45] = 0;
        }
    } else {
        kind = ((s8*)obj)[2];
        obj[4] = 2;
        obj[5] = 0;
        if (kind == 1) {
            D_800D1C1D = 3;
        } else if (kind == 3) {
            D_800E92F8 = 1;
            D_8009A220[0] = 0;
        } else if (kind == 8) {
            D_800D1C27 = 1;
        }
        p = D_8009A0A0;
        if (((s8*)p)[0xD0] == 0 && ((s8*)p)[0xD4] == 0) {
            D_800D1C1C = 0;
        }
    }
}
