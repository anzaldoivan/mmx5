#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern s8 D_8009A0FC;

static inline s32 func_800F0B1C_ovl06_test(u8* obj) {
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            return 1;
        }
    } else if (D_8009A0FC == -0x80) {
        return 1;
    }
    return 0;
}

void func_800F0B1C_ovl06(u8* obj) {
    s32 flag;
    s32 mask;

    if (!(D_8009A420_as_s32 & 3) && (random_byte() & 1)) {
        random_byte();
    }
    flag = func_800F0B1C_ovl06_test(obj);
    if (flag) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        mask = 1;
        if (!(obj[0xA8] & 8)) {
            obj[5] = 0xC;
            obj[6] = 0;
        } else {
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
            if (obj[0x15] != 0) {
                mask = 2;
            }
            if ((*(u16*)(obj + 0x88) & mask) || --*(s8*)(obj + 0x90) == 0) {
                obj[6] = 3;
                set_animation(obj, 0x10);
                if (obj[0x8D] == 0) {
                    g_Player[0xD8] = 0x29;
                    g_Player[6] = 0;
                }
            }
        }
        animate_object(obj);
    } else {
        animate_object(obj);
    }
}
