#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FA218_ovl03[];
extern u8 D_800FA21C_ovl03[];

void func_800F7374_ovl03(u8* a0) {
    u8* p;

    func_800317B8(a0);
    func_80031DD0(a0);
    switch (((s8*)a0)[5]) {
    case 0:
        if (--*(s32*)(a0 + 0x84) == 0) {
            set_animation(a0, 0xE);
            play_sound(2, 0xF, a0);
            if (a0[0x15] == 0) {
                *(s32*)(a0 + 0x20) = -0x10000;
            } else {
                *(s32*)(a0 + 0x20) = 0x10000;
            }
            *(s32*)(a0 + 0x84) = 0;
            a0[5]++;
            func_8002D9EC(a0, 0x10, 0x10);
        }
        break;
    case 1:
        if (((s8*)a0)[0x45] != 0) {
            if (((s8*)a0)[2] == 1 || ((s8*)a0)[2] == 4) {
                *(u8**)(a0 + 0x50) = D_800FA218_ovl03;
                *(u8**)(a0 + 0x54) = D_800FA21C_ovl03;
            }
        }
        if (++*(s32*)(a0 + 0x84) == 700) {
            a0[4] = 2;
        }
        func_8002D9EC(a0, 0x10, 0x10);
        break;
    }
    p = *(u8**)(a0 + 0x7C);
    if (((s8*)p)[4] == 2 || ((s8*)p)[5] == 10) {
        a0[4] = 2;
    }
    animate_object(a0);
    apply_object_motion(a0);
}

extern void (*D_800FA0EC_ovl03[])(u8*);
extern void func_800F866C_ovl03(u8* obj);

void func_800F74D8_ovl03(u8* arg0) {
    if (((signed char*)arg0)[2] != 0) {
        func_800F866C_ovl03(arg0);
        return;
    }
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    arg0[3] = 0;
    D_800FA0EC_ovl03[((signed char*)arg0)[4]](arg0);
    func_8002FB58(arg0);
}
