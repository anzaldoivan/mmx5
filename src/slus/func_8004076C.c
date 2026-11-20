#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80074CA8[];

void func_8004076C(u8* obj) {
    u8 id;

    id = D_80074CA8[*(s8*)(obj + 0x97)];
    func_8003B33C(obj, id);
    if (id == 0x5D) {
        obj[0x44] = obj[0x91] - 8;
    }
}
