/* Headers to support extendeded attributes
 *
 * This is currently a dirty macro hack, and supports only a single namespace
 * at a time, configurable only at compile time
 *
 */

#ifndef NAMESPACE
#define NAMESPACE   EXTATTR_NAMESPACE_USER
#endif

#include <sys/extattr.h>
#include <errno.h>

#define canonicalize_file_name(orig)                realpath(orig, NULL)
#define listxattr(path, list, size)                 extattr_list_file(path, NAMESPACE, NULL, 0)
#define lremovexattr(path, name)                    extattr_delete_link(path, NAMESPACE, name)
#define getxattr(path, name, value, size)           extattr_get_file(path, NAMESPACE, name, value, 0)
#define lsetxattr(path, name, value, size, options) extattr_set_link(path, NAMESPACE, name, value, size)
