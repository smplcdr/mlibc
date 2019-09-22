
#ifndef _STDARG_H
#define _STDARG_H 1

#ifdef __GNUC__

/* GCC compatible definition of va_list.  */
typedef struct {
    unsigned int gp_offset;
    unsigned int fp_offset;
    union {
        unsigned int overflow_offset;
        char *overflow_arg_area;
    };
    char *reg_save_area;
} __va_list_struct, va_list[1];

void __va_start(__va_list_struct *ap, void *fp);
void *__va_arg(__va_list_struct *ap, int arg_type, int size, int align);

#define va_start(ap, param) __va_start(ap, __builtin_frame_address(0))
#define va_arg(ap, type)  (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), sizeof(type), __alignof__(type))))
#define va_copy(dest, src)  (*(dest) = *(src))
#define va_end(ap)    ((void)ap)

/* Avoid conflicting definition for va_list on Macs.  */
#define _VA_LIST_T

#else /* __GNUC__ */

typedef unsigned char *va_list;

#define va_start(ap, param) (ap = (va_list)&param + sizeof(param))
#define va_arg(ap, type)  (*(type *)((ap += sizeof(type)) - sizeof(type)))
#define va_end(ap)    ((void)ap)

#endif /* __GNUC__ */

#ifdef __GNUC__
/* Fix a buggy dependency on GCC in libio.h */
typedef va_list __gnuc_va_list;
#define _VA_LIST_DEFINED
#endif /* __GNUC__ */

#endif /* _STDARG_H */
