#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F57FC_ovl28(u8* obj) {
    if (D_800FE198_ovl28[G[0x89]][G[0x8A] + 1] == 5) {
        *(s16*)(obj + 0x7E) = 100;
    } else {
        *(s16*)(obj + 0x7E) = 0;
    }
    set_animation(obj, 1);
    animate_object(obj);
    obj[6]++;
}
