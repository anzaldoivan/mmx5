#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void func_8003A9AC(u8* obj);
extern void func_8003D344(void* arg0);

void func_8003797C(u8* obj) {
    func_80043B88(obj);
    if (obj[0x89] & 8) {
        func_8003A9AC(obj);
    } else {
        animate_object(obj);
        apply_object_motion(obj);
        func_8003D344(obj);
    }
}
