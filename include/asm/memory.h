/*
 *  NOTE!!! memcpy(dest,src,n) assumes ds=es=normal data segment. This
 *  goes for all kernel functions (ds=es=kernel space, fs=local data,
 *  gs=null), as well as for all well-behaving user programs (ds=es=
 *  user data space). This is NOT a bug, as any user program that changes
 *  es deserves to die if it isn't careful.
 */
#define memcpy(dest,src,n) ({ \
void * _res = dest; \
__asm__ ("pushl %%edi\n\t"\
         "pushl %%esi\n\t"\
         "cld;rep;movsb\n\t"\
         "popl %%esi\n\t"\
         "popl %%edi"\
         ::"D" ((long)(_res)),"S" ((long)(src)),"c" ((long) (n)));\
_res; \
})
