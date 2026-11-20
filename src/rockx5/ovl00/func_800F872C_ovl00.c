#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

extern u8 D_800FB448_ovl00[][6];

void func_800F872C_ovl00(u8* obj) {
    u32 r;
    u8 t;

    r = random_byte() & 0xF;
    obj[0x8E] = 0;
    if (D_800D1CA2 / 2 < (s8)obj[0x5C]) {
        if (r < 8) {
            obj[0x8D] = 0;
        } else {
            obj[0x8D] = 1;
        }
    } else {
        if (r < 8) {
            obj[0x8D] = 2;
        } else {
            obj[0x8D] = 3;
        }
    }
    t = D_800FB448_ovl00[obj[0x8D]][obj[0x8E]++];
    obj[0x6] = 0;
    obj[0x5] = t;
    animate_object(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
