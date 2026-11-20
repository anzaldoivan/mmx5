#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_8002A600(s32, s32, s32);
extern s8 D_800D1C0C;

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
    if (D_800D1C0C == 0xC) {
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
