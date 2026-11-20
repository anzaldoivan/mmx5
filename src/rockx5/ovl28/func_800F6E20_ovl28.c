#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6E20_ovl28(u8* obj) {
    u8 n;

    animate_object(obj);
    func_800317B8(obj);
    n = obj[0x8D];
    if (n != 0) {
        if (n == 1) {
            set_animation(obj, 0x1D);
        }
        obj[0x8D]--;
    }
    if (func_80031DD0(obj) < 0 || ((s8*)obj)[0x45] == 1) {
        obj[4]++;
        (*(u8**)(obj + 0x7C))[0x8D] = 0;
    }
    if (((s8*)*(u8**)(obj + 0x7C))[4] == 2) {
        obj[4] = 2;
    }
}
