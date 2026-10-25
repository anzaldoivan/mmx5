#include "types.h"

extern void (*D_800FB28C_ovl09[])(Obj6BD4*);
extern s32 func_8003240C(Obj6BD4*);
extern void func_80032F70(Obj6BD4*);
extern s32 func_800326BC(Obj6BD4*);
extern void func_8003258C(Obj6BD4*);
extern void func_80033024(Obj6BD4*);

void func_800F74EC_ovl09(Obj6BD4* self) {
    self->prevX = self->x;
    self->prevY = self->y;
    D_800FB28C_ovl09[self->state](self);
    func_8003240C(self);
    func_80032F70(self);
    func_800326BC(self);
    func_8003258C(self);
    func_80033024(self);
}
