#include "types.h"
#include "mmx5/globals.h"

extern u16 D_800D50DE;

void func_800F50A8_ovl28(u8* obj) {
    animate_object(obj);
    func_8002D9EC(obj, 0x60, 0x60);
    if (*(s8*)(obj + 0x45) == 1 && D_800D50DE == 0) {
        func_8002385C(0x43, 0xFF, 0);
        obj[5] = 5;
    }
}
