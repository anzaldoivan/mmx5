#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FE004_ovl39(EntFE004* obj) {
    animate_object(obj);
    func_800317B8(obj);
    move_object(obj);
    ((s32(*)())func_8002F8FC)(obj);
    if (obj->flags & 8) {
        obj->timer = 0x78;
        obj->state++;
    } else {
        func_8002D89C(obj);
    }
}
