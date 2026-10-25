/* control: nothing here may be refused */
#define CTL_COUNT 4
#define CTL_ACC(p) ((p)->a)
#define DEDUP_NAME func_00001000

void DEDUP_NAME(void) {
}

int ControlMain(int *p) {
    // !FAKE: pin kept to steer register allocation
    register int r asm("$s0") = 0;
    int *z = (int *)0; /* (int *)0x00002000 in a comment is not a cast */
    return r + CTL_COUNT + (z == 0);
}

void func_00001100(void) {
}
