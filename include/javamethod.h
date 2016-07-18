/*
The MIT License (MIT) 
Copyright (c) 2009,2010,2016 Andreas Heck <aheck@gmx.de>

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/*
 * Representation of a single method of a Java class
 */

#ifndef __JAVAMETHOD_H__
#define __JAVAMETHOD_H__

#include <glib.h>

typedef struct _JavaMethod
{
    guint16 access_flags;
    gchar *name;
    gchar *descriptor;
    gchar *signature;
    gchar **exceptions;
    guchar *code;
    guint32 codelen;
} JavaMethod;

/*
 * Create a new JavaMethod instance
 */
JavaMethod* javamethod_new(guint16 access_flags, const gchar *name,
        const gchar *descriptor, const gchar *signature,
        const gchar **exceptions);

/*
 * Get the name of a method of a Java class
 */
const gchar* javamethod_get_name(JavaMethod *method);

/*
 * Get the descriptor of a method of a Java class
 */
const gchar* javamethod_get_descriptor(JavaMethod *method);

/*
 * Get the signature of a method of a Java class
 */
const gchar* javamethod_get_signature(JavaMethod *method);

/*
 * Get the exceptions a method of a Java class declares to throw
 */
gchar** javamethod_get_exceptions(JavaMethod *method);

/*
 * Is this method declared public?
 */
gboolean javamethod_is_public(JavaMethod *method);

/*
 * Is this method declared protected?
 */
gboolean javamethod_is_protected(JavaMethod *method);

/*
 * Is this method declared private?
 */
gboolean javamethod_is_private(JavaMethod *method);

/*
 * Is this method declared static?
 */
gboolean javamethod_is_static(JavaMethod *method);

/*
 * Is this method declared final?
 */
gboolean javamethod_is_final(JavaMethod *method);

/*
 * Is this method declared synchronized?
 */
gboolean javamethod_is_synchronized(JavaMethod *method);

/*
 * Is this method bridge method, that was generated by the compiler?
 */
gboolean javamethod_is_bridge_method(JavaMethod *method);

/*
 * Does this method has a variable parameter list?
 */
gboolean javamethod_has_varargs(JavaMethod *method);

/*
 * Is this method declared abstract?
 */
gboolean javamethod_is_abstract(JavaMethod *method);

/*
 * Convert a JavaMethod to its Java declaration
 */
void javamethod_to_string(JavaMethod *method, GString *buffer);

/*
 * Set the public flag of the method
 */
void javamethod_set_is_public(JavaMethod *method, gboolean value);

/*
 * Set the protected flag of the method
 */
void javamethod_set_is_protected(JavaMethod *method, gboolean value);

/*
 * Set the protected flag of the method
 */
void javamethod_set_is_private(JavaMethod *method, gboolean value);

/*
 * Set the abstract flag of the method
 */
void javamethod_set_is_abstract(JavaMethod *method, gboolean value);

/*
 * Set the static flag of the method
 */
void javamethod_set_is_static(JavaMethod *method, gboolean value);

/*
 * Set the final flag of the method
 */
void javamethod_set_is_final(JavaMethod *method, gboolean value);

/*
 * Set the Java bytecode of the method
 */
void javamethod_set_code(JavaMethod *method, guchar *code, guint32 codelen);

/*
 * Set the synchronized flag of the method
 */
void javamethod_set_is_synchronized(JavaMethod *method,
        gboolean value);

/*
 * Free a JavaMethod instance
 */
void javamethod_free(JavaMethod *method);

#endif /* __JAVAMETHOD_H__ */
