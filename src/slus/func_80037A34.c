#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C0F;

void func_80037A34(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        animate_object(obj);
        if (D_800D1C0F != 0) {
            obj[6]++;
        }
    } else {
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
    }
}
