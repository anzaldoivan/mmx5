#include "types.h"

extern u8 D_80074CA8[];
extern void func_8003B33C(u8*, s32);

void func_8004076C(u8* obj) {
    u8 id;

    id = D_80074CA8[*(s8*)(obj + 0x97)];
    func_8003B33C(obj, id);
    if (id == 0x5D) {
        obj[0x44] = obj[0x91] - 8;
    }
}
