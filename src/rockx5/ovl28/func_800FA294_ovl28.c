#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u16 D_800D50DE;
extern u8 D_8009A0B5;

void func_800FA294_ovl28(u8* obj) {
    animate_object(obj);
    func_8002D9EC(obj, 0x48, 0x48);
    if (D_800D50DE == 0x1F) {
        func_8003D29C(0x48, D_8009A0B5);
        set_animation(obj, 9);
        obj[5] = 4;
    }
}
