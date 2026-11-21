#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"

extern s32 func_8002E024(void*, void*);
extern u8 D_80074E40[];
extern u8 D_800FB58C_ovl00[];
extern u8 D_800FB590_ovl00[];
extern u8 D_800FB594_ovl00[];
extern u8 D_800FB63C_ovl00[];

void func_800F7620_ovl00(u8* obj) {
    u8* p;
    s32 t;
    s32 v;
    s32 w;
    s32 r;

    p = *(u8**)(obj + 0x7C);
    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    w = *(u16*)(p + 0x42) & 0x7FFF;
    *(u16*)(obj + 0x42) = w;
    *(u8**)(obj + 0x30) = D_800FB63C_ovl00;
    t = *(s32*)(p + 0x3C);
    v = 0x10;
    obj[0x16] = v;
    v = (s32)D_800FB58C_ovl00;
    w = (s32)D_800FB590_ovl00;
    *(s32*)(obj + 0x68) = v;
    *(s32*)(obj + 0x50) = w;
    obj[0x14] = 0;
    obj[0x15] = 0;
    obj[0x67] = 0;
    obj[3] = 1;
    *(u8**)(obj + 0x54) = D_800FB594_ovl00;
    *(u8**)(obj + 0x58) = D_80074E40;
    *(s32*)(obj + 0x3C) = t;
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) - 0x30;
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE) - 2;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x5C] = 1;
    obj[0x60] = 4;
    obj[0x8C] = func_8002E024(obj, g_Player);
    r = random_byte() % 5 - 2;
    *(u16*)(obj + 0x8E) = 0x400;
    *(u16*)(obj + 0x90) = 0x20;
    obj[0x8C] = (obj[0x8C] + r) & 0x1F;
    if (((s8*)obj)[2] != 0) {
        *(u16*)(obj + 0x90) = 0x18;
    }
    set_animation(obj, 0);
    obj[5] = 0;
    obj[4]++;
}

extern void func_8002E0F8(s32* a0, s32* a1, s32 a2);
extern s32 func_8002E024(void*, void*);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002E274(u8* a0, u8* a1);

s32 func_800F777C_ovl00(u8* obj) {
    u16 k;
    s32 r;
    s32 y;
    s32 x;
    s32 v;

    v = ((s8*)obj)[5];
    if (v != 1) {
        if (v < 2) {
            if (v == 0) {
                *(u16*)(obj + 0x8E) -= *(u16*)(obj + 0x90);
                k = *(u16*)(obj + 0x8E) >> 8;
                func_8002E0F8((s32*)(obj + 0x20), (s32*)(obj + 0x24),
                              obj[0x8C]);
                *(s32*)(obj + 0x20) *= k;
                *(s32*)(obj + 0x24) *= k;
                if (k == 0) {
                    *(u16*)(obj + 0x92) = 0x3C;
                    obj[5]++;
                }
            }
        }
    } else {
        if (--*(u16*)(obj + 0x92) == 0) {
            func_8002E0F8((s32*)(obj + 0x20), (s32*)(obj + 0x24),
                          func_8002E024(obj, g_Player));
            x = *(s32*)(obj + 0x20);
            y = *(s32*)(obj + 0x24);
            x <<= 2;
            do {
                *(s32*)(obj + 0x20) = x;
            } while (0); // !FAKE: fences the sched1 hoist of the state load
            x = obj[5];
            y <<= 2;
            do {
                *(s32*)(obj + 0x24) = y;
            } while (0); // !FAKE: keeps the state increment below the store
            x++;
            obj[5] = x;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        r = func_8004FC64(obj);
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (func_8002E274(obj, g_Player) == 0) {
        if (obj[0x70] != 0) {
            r = ((s32(*)())func_8004FD24)(obj);
        inc:
            obj[4]++;
            return r;
        }
        if (is_off_screen(obj, 0x20, 0x20) == 0) {
            func_8002D9EC(obj, 0x10, 0x10);
            return;
        }
    }
    obj[4]++;
}
