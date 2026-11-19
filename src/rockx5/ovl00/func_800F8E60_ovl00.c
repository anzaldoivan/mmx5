#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FB3DC_ovl00[];
extern u8 D_800FB3E8_ovl00[];

void func_800F8E60_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        set_animation(obj, 0);
        *(u8**)(obj + 0x50) = D_800FB3DC_ovl00;
        *(u8**)(obj + 0x54) = D_800FB3E8_ovl00;
        *(s16*)(obj + 0x7C) = 10;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
