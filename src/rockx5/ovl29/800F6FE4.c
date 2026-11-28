#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FA4DC_ovl29[];
extern u16 D_800FA504_ovl29[];

void func_800F6FE4_ovl29(u8* obj) {
    u8* sub;
    s8 idx;
    s32 r;
    u8* g;

    sub = *(u8**)(obj + 0x7C);
    func_800317B8(obj);
    move_object(obj);
    animate_object(obj);
    if (*(s8*)(obj + 3) == 0) {
        if (*(s8*)(sub + 4) != 1) {
            obj[5] = 0;
            obj[4]++;
            return;
        }
        set_animation(obj, 0x1E);
        *(u8**)(obj + 0x54) = D_800FA4DC_ovl29;
        r = random_byte() & 0x1F;
        g = D_8009A1F8.u;
        idx = obj[7];
        *(s16*)(obj + 0xA) = *(u16*)(g + 0xA) + D_800FA504_ovl29[idx] + r;
        *(s16*)(obj + 0xE) = *(u16*)(g + 0xE) - 0x20;
        *(s32*)(obj + 0x20) = 0xFFFA0000;
        *(s32*)(obj + 0x24) = 0xFFFA0000;
        *(s16*)(obj + 0x88) = idx * 8 + 0x64;
        *(s16*)(obj + 0x8A) = 4;
        obj[6]++;
    }
}

extern void func_8002A600(s32, s32, s32);

void func_800F70E0_ovl29(u8* arg0) {
    u16 u;
    s16 t;

    t = *(s16*)(arg0 + 0x88);
    u = *(u16*)(arg0 + 0x88);

    if (t >= 2) {
        *(s16*)(arg0 + 0x88) = u - 1;
        return;
    }
    if (t == 1) {
        *(s16*)(arg0 + 0x88) = u - 1;
        func_8002A600(0x78, 4, 2);
    }
    func_800317B8(arg0);
    move_object(arg0);
    animate_object(arg0);
    if (D_800D1C0C.s == 0xC) {
        if (*(s16*)(arg0 + 0xE) >= 0x6C9) {
            set_animation(arg0, 0x20);
            *(s16*)(arg0 + 0xE) = 0x6C8;
            arg0[6]++;
        }
    } else if (*(s16*)(arg0 + 0xE) >= 0x2B9) {
        set_animation(arg0, 0x20);
        *(s16*)(arg0 + 0xE) = 0x2B8;
        arg0[6]++;
    }
}

void func_800F71C0_ovl29(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        func_8002D9EC(obj, 0x30, 0x30);
    } else if (--*(s16*)(obj + 0x8A) == 0) {
        obj[6] -= 2;
    } else {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}
