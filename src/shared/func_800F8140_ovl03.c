#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

extern void (*D_800FA1C4_ovl03[])(Obj8140*);

void func_800F8140_ovl03(Obj8140* e) {
    if (e->unk90 < 0x50) {
        e->unk90 = 0x64;
    }
    D_800FA1C4_ovl03[e->unk6](e);
    func_8002D9EC(e, 0x64, 0x64);
}

extern u16 D_8009A42E;
extern u8 D_800C9310;
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u8 D_800F9E68_ovl03[];
extern u8 D_800F9E6C_ovl03[];

void func_800F81AC_ovl03(u8* p) {
    u8* g = g_Player;

    if (((signed char*)g)[0xCA] != 0) {
        g[0xCA] = 0;
    }
    set_animation(p, 0xB);
    p[0x62] = 0;
    *(u8**)(p + 0x50) = D_800F9E68_ovl03;
    func_8002C218();
    D_800D50DE = 0;
    D_800C9310 |= 1;
    D_8009A42E = 0;
    D_80093E68 = 0;
    *(u8**)(p + 0x54) = D_800F9E6C_ovl03;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0x20000;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(s16*)(p + 0x7C) = 0;
    p[0x6]++;
    animate_object(p);
    apply_object_motion(p);
}

void func_800F826C_ovl03(u8* obj) {
    *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    if (++*(s16*)(obj + 0x7C) == 0x78) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x8000;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
