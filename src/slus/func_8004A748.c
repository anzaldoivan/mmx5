#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8007718C[];
extern u8 D_80077194[];
extern void* D_80077198[];

void func_8004A748(u8* obj) {
    s32 t;
    u16 c;

    if (*(s8*)(obj + 0x98) != 0) {
        *(s8*)(obj + 0x98) = 0;
        t = *(u16*)(obj + 0x8E) + 1;
        *(s16*)(obj + 0x8E) = t;
        if ((s16)t >= 4) {
            *(void**)(obj + 0x50) = 0;
            *(void**)(obj + 0x68) = 0;
            obj[4] = 2;
            set_animation(obj, 1);
            return;
        }
        *(void**)(obj + 0x50) = 0;
        *(void**)(obj + 0x68) = 0;
        *(s16*)(obj + 0x90) = 4;
    }
    animate_object(obj);
    c = *(u16*)(obj + 0x90);
    if (*(s16*)(obj + 0x90) != 0) {
        t = c - 1;
        *(s16*)(obj + 0x90) = t;
        if ((t << 16) == 0) {
            *(void**)(obj + 0x50) = D_8007718C;
            *(void**)(obj + 0x68) = D_80077194;
        }
    }
    ((void (*)(u8*))D_80077198[*(s8*)(obj + 5)])(obj);
    func_8002D9EC(obj, 0x20, 0x20);
}
