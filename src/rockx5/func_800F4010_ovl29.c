#include "types.h"

extern void (*D_800FA3EC_ovl29[])(X4_Obj*);
s32 func_8002FB58(X4_Obj*);

void func_800F4010_ovl29(X4_Obj* arg0) {
    arg0->on_screen = 0;
    arg0->unk18.val = arg0->x_pos.val;
    arg0->unk1C.val = arg0->y_pos.val;
    func_8002FB58(arg0);
    D_800FA3EC_ovl29[arg0->state](arg0);
}
