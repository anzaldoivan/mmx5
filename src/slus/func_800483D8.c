#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void* D_80077094[];

void func_800483D8(u8* obj) {
    if (is_off_screen(obj, 0x20, 0x20) == 0) {
        animate_object(obj);
        ((void (*)(u8*))D_80077094[(s8)obj[5]])(obj);
    } else {
        obj[3] = 0;
        obj[4] = 2;
    }
}
