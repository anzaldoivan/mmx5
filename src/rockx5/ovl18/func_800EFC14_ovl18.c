#include "types.h"
#include "mmx5/globals.h"

extern s8 D_8009A424;

void func_800EFC14_ovl18(u8* obj) {
    if (D_8009A424 == 0) {
        animate_object(obj);
        if (*(s8*)(obj + 0x46) == 0) {
            obj[4]++;
        }
    }
}
