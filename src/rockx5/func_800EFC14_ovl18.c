#include "types.h"

extern void func_80017248(u8* obj);
extern s8 D_8009A424;

void func_800EFC14_ovl18(u8* obj) {
    if (D_8009A424 == 0) {
        func_80017248(obj);
        if (*(s8*)(obj + 0x46) == 0) {
            obj[4]++;
        }
    }
}
