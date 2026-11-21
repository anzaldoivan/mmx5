#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl00.h"
#include "addr.h"

void func_800F2B28_ovl00(u8* obj) {
    set_animation(obj, 10);
    obj[6]++;
}

void func_800F2B5C_ovl00(u8* obj) {
    if (*(s8*)(obj + 0x45) == 2) {
        func_800F2EA4_ovl00(obj, 1);
        obj[6]++;
    }
}

void func_800F2BA4_ovl00(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 3) {
        arg0[6]++;
    }
}

void func_800F2BCC_ovl00(u8* obj) {
    if ((s8)obj[0x45] == 1) {
        func_800F2EA4_ovl00(obj, 0);
        set_animation(obj, 8);
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x8A] = 0;
        obj[5] = 2;
        obj[6] = 0;
    }
}
