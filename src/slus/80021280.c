#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_8002002C(s32);
extern void func_80013288(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F40[];
extern u8 D_80070F4C[];

void func_80021280(Obj80021650* arg0) {
    func_8001E668();
    D_8009A427 = 0;
    arg0->unk1F = 0;
    arg0->unk24 = 0;
    func_8002002C(0);
    *(s16*)((u8*)arg0 + 4) = 0x78;
    func_80013288(8);
    if (*(s8*)((u8*)arg0 + 0xC) == 0) {
        arg0->unk8 = func_8001FF18(D_80070F40, 1);
        arg0->unk1 += 3;
    } else {
        arg0->unk8 = func_8001FF18(D_80070F4C, 1);
        arg0->unk1 += 1;
    }
}

#include "shared/func_80021318.c"

extern u16 D_800D1C7E;
extern u8 D_800D1C27;

void func_80021434(u8* arg0) {
    u8* p = D_8009A420;
    s32 v;

    if (((signed char*)p)[4] == 0) {
        v = p[7];
        if (v != 1) {
            if (v < 2) {
                if (v == 0) {
                    arg0[0x1E] = 0;
                    if (D_800D1C7E & 0x8000) {
                        arg0[0x45] = 4;
                    } else {
                        arg0[0x45] = 2;
                    }
                    arg0[0] = 9;
                    arg0[1] = 0;
                    arg0[2] = 0;
                    arg0[3] = 0;
                    return;
                }
            }
        } else {
            D_800D1C27 = 1;
            arg0[0] = 0xB;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            return;
        }
        arg0[1] = 5;
    }
}

#define func_80021318 func_800214C4
#include "shared/func_80021318.c"
#undef func_80021318

extern u16 D_800D1C7E;

void func_800215E0(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            arg0[0x1E] = 0;
            if (D_800D1C7E & 0x8000) {
                arg0[0x45] = 4;
            } else {
                arg0[0x45] = 2;
            }
            arg0[0] = 9;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            return;
        }
        arg0[1] = 5;
    }
}

extern void func_80013288(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F5C[];

void func_80021650(Obj80021650* arg0) {
    func_8001E668();
    D_8009A427 = 1;
    arg0->unk1F = 0;
    arg0->unk24 = 0;
    func_80013288(8);
    arg0->unk8 = func_8001FF18(D_80070F5C, 1);
    arg0->unk1++;
}

#define func_80021318 func_800216B0
#include "shared/func_80021318.c"
#undef func_80021318

void func_8001E6AC(void);
void func_80012EAC(void);

void func_800217CC(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            func_8001E6AC();
            func_80012EAC();
        } else {
            arg0[1] = 0;
        }
    }
}
