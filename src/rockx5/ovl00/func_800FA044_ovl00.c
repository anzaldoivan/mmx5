#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

extern s32 func_8002D800(u8* a0);
extern void start_pad_vibration(s32);
extern s32 D_800FB694_ovl00;

void func_800FA044_ovl00(u8* obj) {
    obj[3] = 0;
    if (func_8002D800(obj) == 0) {
        switch ((s8)obj[5]) {
        case 0:
            if (D_800FB694_ovl00 == (s8)obj[2]) {
                obj[6] = 0;
                obj[5]++;
                obj[0x16] = 3;
                start_pad_vibration(4);
            }
            func_8002D89C(obj);
            break;
        case 1:
            apply_object_motion(obj);
            obj[6]++;
            if ((s8)obj[6] < 0x1F || (obj[6] & 1)) {
                func_8002D89C(obj);
            }
            break;
        }
    } else {
        clear_object_slot(obj);
    }
}
