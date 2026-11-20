#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FE250_ovl39(EntFE250* obj) {
    animate_object(obj);
    func_800317B8(obj);
    move_object(obj);
    ((s32(*)())func_8002F8FC)(obj);
    if (obj->flags != 0) {
        obj->unk58 = 0;
        obj->timer = 0x3C;
        obj->state++;
    }
}
