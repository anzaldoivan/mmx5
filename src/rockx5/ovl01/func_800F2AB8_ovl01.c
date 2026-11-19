#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_800F2F8C_ovl01(u8* obj);
extern s32 func_800F3040_ovl01(u8* obj);
extern s32 func_800F2FEC_ovl01(u8* obj);

void func_800F2AB8_ovl01(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (func_800F2F8C_ovl01(obj) == 0 && func_800F3040_ovl01(obj) == 0) {
        func_800F2FEC_ovl01(obj);
    }
}
