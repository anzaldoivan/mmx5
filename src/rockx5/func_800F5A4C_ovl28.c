#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F5A4C_ovl28(u8* obj) {
    s32 m;

    func_80017248(obj);
    m = 2;
    if (obj[0x15]) {
        m = 1;
    }
    if (obj[0x70] & m) {
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s32*)(obj + 0x20) != 0) {
        func_8002DED4(obj);
        if (obj[0x15]) {
            if (*(s32*)(obj + 0x20) < 0) {
                *(s32*)(obj + 0x20) = 0;
            }
        } else if (*(s32*)(obj + 0x20) > 0) {
            *(s32*)(obj + 0x20) = 0;
        }
        if (*(s32*)(obj + 0x20) != 0) {
            return;
        }
    }
    if ((signed char)obj[0x45] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
    }
}
