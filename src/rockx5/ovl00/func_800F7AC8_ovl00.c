#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FB5A4_ovl00[];

void func_800F7AC8_ovl00(u8* obj) {
    u8* child;

    switch (*(s8*)(obj + 5)) {
    case 0:
        if (*(s8*)(obj + 0x46) == 0) {
            child = func_8002D1A4();
            if (child != 0) {
                child[0] = 0x61;
                child[1] = 3;
                child[2] = 4;
                *(u8**)(child + 0x7C) = *(u8**)(obj + 0x7C);
            }
            set_animation(obj, 1);
            *(u8**)(obj + 0x50) = D_800FB5A4_ovl00;
            *(u16*)(obj + 0x8C) = 0xB4;
            (*(u8**)(obj + 0x7C))[7] = 1;
            obj[5]++;
        }
        break;
    case 1:
        if (--*(u16*)(obj + 0x8C) == 0 ||
            *(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
            set_animation(obj, 2);
            *(u8**)(obj + 0x50) = 0;
            (*(u8**)(obj + 0x7C))[7] = 2;
            obj[5]++;
        }
        break;
    case 2:
        if (*(s8*)(obj + 0x46) == 0) {
            (*(u8**)(obj + 0x7C))[7] = 3;
            obj[4]++;
        }
        break;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_800317B8(obj);
    if (is_off_screen(obj, 0x20, 0x20) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4]++;
    }
}
