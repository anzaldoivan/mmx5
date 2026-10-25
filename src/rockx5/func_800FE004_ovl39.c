#include "types.h"

extern void func_80017248(EntFE004*);
extern s32 func_800317B8(EntFE004*);
extern void func_8002DF54(EntFE004*);
extern s32 func_8002F8FC(EntFE004*);
extern void func_8002D89C(EntFE004*);

void func_800FE004_ovl39(EntFE004* obj) {
    func_80017248(obj);
    func_800317B8(obj);
    func_8002DF54(obj);
    func_8002F8FC(obj);
    if (obj->flags & 8) {
        obj->timer = 0x78;
        obj->state++;
    } else {
        func_8002D89C(obj);
    }
}
