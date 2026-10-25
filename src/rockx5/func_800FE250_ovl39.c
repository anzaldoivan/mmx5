#include "types.h"

extern void func_80017248(EntFE250*);
extern s32 func_800317B8(EntFE250*);
extern void func_8002DF54(EntFE250*);
extern s32 func_8002F8FC(EntFE250*);

void func_800FE250_ovl39(EntFE250* obj) {
    func_80017248(obj);
    func_800317B8(obj);
    func_8002DF54(obj);
    func_8002F8FC(obj);
    if (obj->flags != 0) {
        obj->unk58 = 0;
        obj->timer = 0x3C;
        obj->state++;
    }
}
