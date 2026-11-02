#include "types.h"
#include "addr.h"

void func_80017248(u8* obj);
void func_8002DF54(u8* a0);
void func_80050880(u8 flags, s16 x0, s16 y0, s16 x1, s16 y1, s16 count);

void func_800F25BC_ovl01(u8* obj) {
    u8* p;

    func_80017248(obj);
    func_8002DF54(obj);
    *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    p = D_1F80004C.bytes;
    if (--p[0x80] == 0xFF) {
        D_1F80004C.bytes[0x81] = 1;
        *(s32*)(obj + 0xC) = *(s32*)(D_1F80004C.bytes + 0x88);
        obj[5] = 3;
        obj[6] = 0;
        if (obj[0x15] != 0) {
            u16 x = *(u16*)(obj + 0xA);
            func_80050880(2, x - 0x20, *(s16*)(obj + 0xE), x,
                          *(u16*)(obj + 0xE) + 0x20, 3);
            return;
        }
        func_80050880(1, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE),
                      *(u16*)(obj + 0xA) + 0x20, *(u16*)(obj + 0xE) + 0x20, 3);
    }
}
