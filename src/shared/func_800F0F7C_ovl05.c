#include "types.h"
#include "mmx5/ovl05.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void func_800F0F7C_ovl05(u8* arg0) {
    if (arg0[0x15] != 0) {
        *(s32*)(arg0 + 0x20) = 0x10000;
        *(s32*)(arg0 + 0x28) = 0x800;
    } else {
        *(s32*)(arg0 + 0x20) = 0xFFFF0000;
        *(s32*)(arg0 + 0x28) = 0x800;
    }
    arg0[6]++;
}

extern s32 func_800F0FFC_ovl05(u8* obj);

void func_800F0FB0_ovl05(u8* obj) {
    func_800F103C_ovl05(obj);
    apply_object_motion(obj);
    if (func_800F0FFC_ovl05(obj) != 0) {
        obj[3] = 0;
        ((s32(*)())func_8004FD24)(obj);
        obj[4] = 2;
    }
}

s32 func_800F0FFC_ovl05(u8* a0) {
    if (a0[0x70] == 0) {
        func_8002F8FC(a0);
    }
    return a0[0x70] != 0;
}

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void func_800F103C_ovl05(Obj800F103C* p) {
    if (--p->unk8C == 0) {
        p->unk8C = 7;
        if (p->unk15 == 0) {
            p->unkA += 0x10;
            func_8005019C(2, 0, p, 1, 1);
            p->unkA -= 0x10;
        } else {
            p->unkA -= 0x10;
            func_8005019C(2, 0, p, 1, 1);
            p->unkA += 0x10;
        }
    }
}
