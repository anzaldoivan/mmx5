#include "types.h"

extern void func_80043B88(Ent371CC*);
extern s32 func_80039DB8(Ent371CC*);
extern s32 func_8003F094(Ent371CC*);
extern s32 func_80043A80(Ent371CC*);
extern void func_8003B4CC(Ent371CC*, s32, s32);
extern void func_8003B0EC(Ent371CC*);
extern void func_80017248(Ent371CC*);
extern void func_8002DF54(Ent371CC*);

void func_800371CC(Ent371CC* arg0) {
    s8 temp_s0;
    u16 flags;

    func_80043B88(arg0);
    if (func_80039DB8(arg0) == 0 && func_8003F094(arg0) == 0 &&
        func_80043A80(arg0) == 0) {
        if (arg0->unk80 & 2) {
            arg0->unk15 = 0;
        }
        if (arg0->unk80 & 1) {
            arg0->unk15 = 0x40;
        }
        flags = arg0->unk7C;
        if (flags & 4) {
            temp_s0 = arg0->unk44;
            func_8003B4CC(arg0, 0x1F, arg0->unk45);
            arg0->unk44 = temp_s0;
            func_8003B0EC(arg0);
        } else if (flags & 8) {
            func_80017248(arg0);
            func_8002DF54(arg0);
        }
    }
}
