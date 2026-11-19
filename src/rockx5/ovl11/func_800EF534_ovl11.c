#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800EF534_ovl11(u8* obj) {
    animate_object(obj);
    if ((*(s16*)(obj + 0x54))++ >= 0x97 && *(s8*)(obj + 0x45) == 1) {
        clear_object_slot(obj);
    } else {
        func_8002D89C(obj);
    }
}
