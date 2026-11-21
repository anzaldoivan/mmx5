#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

extern void func_80032F70(Obj5C30*);
extern s32 func_800326BC(Obj5C30*);
extern s32 func_8003240C(Obj5C30*);
extern void func_8003258C(Obj5C30*);

extern u8 D_8009A198;
extern void (*D_800FB29C_ovl00[])(Obj5C30*);

void func_800F5C30_ovl00(Obj5C30* obj) {
    func_80032F70(obj);
    func_80033024(obj);
    func_800326BC(obj);
    D_800FB29C_ovl00[obj->state](obj);
    func_8002D9EC(obj, 0xFF, 0x20);
    func_8002FB58(obj);
    if (D_8009A198 == 0) {
        func_8003240C(obj);
    }
    func_8003258C(obj);
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern s32 D_800FB2A4_ovl00[];

void func_800F5CC4_ovl00(u8* a0) {
    if (--*(s32*)(a0 + 0x7C) != 0) {
        if ((D_8009A420_as_s32 & 7) == 0) {
            func_8004FD90(a0, 1, 0x1F, 0x1F);
        }
        if ((D_8009A420_as_s32 & 0xF) == 0) {
            play_sound(0, D_800FB2A4_ovl00[random_byte() & 3], a0);
        }
    } else {
        a0[4] = 3;
        a0[6] = 0;
    }
}
#undef D_8009A420_as_s32

#define D_800EEBA0_ovl00 func_800F5D70_ovl00
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
