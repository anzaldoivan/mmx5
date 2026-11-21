#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F864C_ovl11(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        set_animation(obj, 0xB);
        obj[5] = 2;
    }
}

extern u8 D_8009A197;
extern void (*D_800FA02C_ovl11[])(u8*);

void func_800F869C_ovl11(u8* obj) {
    if (*(signed char*)(obj + 2) == 0) {
        func_80031DD0(obj);
    }
    ((void (*)())func_800317B8)(obj);
    if (D_8009A197 == 0) {
        D_800FA02C_ovl11[*(signed char*)(obj + 5)](obj);
    }
    func_8002D9EC(obj, 0x60, 0x60);
}
