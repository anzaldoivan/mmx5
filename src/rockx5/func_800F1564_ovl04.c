#include "types.h"

typedef struct Ent1564 {
    u8 pad0[5];
    u8 state; /* 0x05 */
    u8 sub;   /* 0x06 */
    u8 pad7[0x16 - 7];
    u8 field16; /* 0x16 */
    u8 pad17[0x7C - 0x17];
    s16 timer; /* 0x7C */
} Ent1564;

extern void func_8002DF54(Ent1564*);

void func_800F1564_ovl04(Ent1564* self) {
    if (--self->timer == -1) {
        self->field16 = 3;
        self->state = 7;
        self->sub = 0;
        return;
    }
    func_8002DF54(self);
}
