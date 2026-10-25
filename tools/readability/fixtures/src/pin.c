/* planted: register pin without a !FAKE marker */
int func_00001200(void) {
    register int r asm("$s1") = 1;
    return r;
}
