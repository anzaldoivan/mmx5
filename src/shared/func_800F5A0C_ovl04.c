#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F5A0C_ovl04(u8* arg0) {
    u8 t = arg0[0x8D];

    if (t == 0) {
        arg0[7]++;
        return;
    }
    arg0[0x8D] = t - 1;
}

void func_800F5A38_ovl04(u8* obj) {
    obj[0x8A] = 0x3C;
    set_animation(obj, 3);
    obj[4] = 1;
    obj[7] = 0;
    if (*(s8*)(obj + 5) != 2) {
        obj[0x91] = random_byte() & 0xF;
        if (obj[0x91] < 5) {
            obj[0x91] = 0;
        } else if (obj[0x91] < 8) {
            obj[0x91] = 1;
        } else if (obj[0x91] < 11) {
            obj[0x91] = 2;
        } else {
            obj[0x91] = 3;
        }
        *(s8*)(obj + 0x90) = -1;
        obj[0x92] = 0;
        obj[0x8D] = 0;
        obj[0x8F] = 0;
        *(s16*)(obj + 0x7E) = 0x250;
        obj[5] = 4;
        obj[6] = 0;
        return;
    }
    if (*(s8*)(obj + 6) >= 4) {
        obj[6] = 3;
    }
}

extern u8 D_80074EE0[];
extern u8 D_8009A11A;
extern void* D_80101C0C_ovl04[];

void func_800F5B20_ovl04(u8* arg0) {
    s32 res;

    res = func_80031DD0(arg0);
    if (*(s8*)(arg0 + 0x45) == 0x40) {
        play_sound(2, 0x81, arg0);
    }
    *(u8**)(arg0 + 0x58) = D_80074EE0;
    if (res < 0) {
        arg0[4] = 2;
        arg0[5] = 0;
        *(u16*)(arg0 + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        return;
    }
    animate_object(arg0);
    ((void (*)(u8*))D_80101C0C_ovl04[*(s8*)(arg0 + 7)])(arg0);
    func_800317B8(arg0);
    func_8002D9EC(arg0, 0x80, 0x80);
}

void func_800F5BEC_ovl04(u8* arg0) {
    arg0[5] = 0;
    arg0[6] = 0;
}

extern u8 D_8009A0B5;

void func_800F5BF8_ovl04(u8* obj) {
    func_8003D29C(0x14, D_8009A0B5);
    obj[5]++;
    set_animation(obj, 0x1C);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x89] = 0x19;
    animate_object(obj);
    func_8002D89C(obj);
}

extern u8* alloc_class3_slot(void);

void func_800F5C64_ovl04(u8* obj) {
    u8* p;

    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5]++;
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1A;
            *(s16*)(p + 0xA) = *(s16*)(obj + 0xA);
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE);
            *(u8**)(obj + 0x80) = p;
        }
    }
    ((s32(*)())func_8002D89C)(obj);
    if (--*(s16*)(obj + 0x7E) == -1) {
        *(u16*)(obj + 0x42) ^= 0x8000;
        *(s8*)(obj + 0x89) -= 5;
        *(s16*)(obj + 0x7E) = (*(s8*)(obj + 0x89) < 6) ? 5 : *(s8*)(obj + 0x89);
    }
}

void func_800F5D48_ovl04(u8* obj) {
    s8* child;
    u8* base;

    animate_object(obj);
    child = *(s8**)(obj + 0x80);
    obj[3] = 0;
    if (child[0] != 0) {
        if (child[7] == 0) {
            if (--*(s16*)(obj + 0x7E) == -1) {
                *(u16*)(obj + 0x7E) = 5;
                *(u16*)(obj + 0x42) ^= 0x8000;
            }
            func_8002D89C(obj);
        }
    } else {
        base = g_playthrough_state.u;
        if (((s8*)base)[0xC] != 0xC) {
            base[0xF] = 0x10;
        } else {
            ((s8*)base)[0xF] = -0x80;
            base[((s8*)base)[0x1D] + 0x2C] = 1;
            base[0x1D] += 9;
        }
        clear_object_slot(obj);
    }
}
