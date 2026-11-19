/* Shared body (DK-5), from the banked draft of func_800F1958_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A197;
extern s32 D_800F9934_ovl11[];

void DEDUP_NAME(u8* obj) {
    s32 flag;
    s32 v;
    s32 x;
    s32 st;

    if (D_8009A197 == 0) {
        animate_object(obj);
        apply_object_motion(obj);
        if (--*(s32*)(obj + 0x84) == 0 && obj[0x17] != 4) {
            flag = obj[0x15] & 0x40;
            v = D_800F9934_ovl11[flag != 0];
            x = *(s16*)(obj + 0xA);
            *(s32*)(obj + 0x28) = 0x600;
            *(s32*)(obj + 0x20) = v;
            if (flag != 0) {
                *(s16*)(obj + 0xA) = x + 0x10;
            } else {
                *(s16*)(obj + 0xA) = x - 0x10;
            }
            set_animation(obj, 4);
        }
    }
    if (__builtin_abs(*(s32*)(obj + 0x20)) > 0x30000) {
        *(s32*)(obj + 0x28) = 0;
    }
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        *(s32*)(obj + 0x8C) = 1;
        st = obj[4] + 1;
        obj[4] = st;
        return;
    } else {
        func_800317B8(obj);
        if ((st = obj[0x70]) != 0 ||
            (func_8002F8FC(obj), (st = obj[0x70]) != 0)) {
            func_8004FD24(obj);
            st = 2;
            obj[4] = st;
            return;
        } else {
            if (is_off_screen(obj, 0x20, 0x20) == 0) {
                func_8002D9EC(obj, 0x20, 0x20);
                return;
            }
            obj[4]++;
            *(s32*)(obj + 0x8C) = 1;
            return;
        }
    }
}
