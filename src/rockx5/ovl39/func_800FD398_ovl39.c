#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FEC18_ovl39[];
extern u8 D_800FEC14_ovl39[];

void func_800FD398_ovl39(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x54) = D_800FEC18_ovl39;
        *(s32*)(obj + 0x50) = 0;
        *(u8**)(obj + 0x68) = D_800FEC14_ovl39;
        obj[0x8A] = 0;
        set_animation(obj, 3);
        obj[6]++;
    }
}
