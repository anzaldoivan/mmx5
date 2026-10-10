#include "types.h"

#define D_1F80004C (*(Obj0470**)0x1F80004C)

extern void func_800171E8(ObjFE130*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_800F08F8_ovl05(ObjFE130*, s32);

void func_800F0800_ovl05(ObjFE130* arg0) {
    if (arg0->unk45 == 1) {
        switch (D_1F80004C->unk86) {
        case 1:
            func_800171E8(arg0, 0xC);
            break;
        case 0:
        case 2:
            func_800171E8(arg0, 0xB);
            break;
        case 3:
            func_800171E8(arg0, 0xD);
            break;
        case 4:
            arg0->unk5 = 2;
            arg0->unk6 = 0;
            break;
        }
        D_1F80004C->unk86++;
    }
    if (arg0->unk45 == 2) {
        func_80016490(0, 0x23, 0);
        func_800F08F8_ovl05(arg0, 1);
    }
}
