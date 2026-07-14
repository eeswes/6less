#define _GNU_SOURCE
#include <dlfcn.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

// 原始函数指针
static int (*real_getaddrinfo)(const char *node, const char *service,
                               const struct addrinfo *hints,
                               struct addrinfo **res);

int getaddrinfo(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res) {
    // 加载原始函数
    if (!real_getaddrinfo)
        real_getaddrinfo = dlsym(RTLD_NEXT, "getaddrinfo");

    // 复制 hints，强制只返回 IPv4 (AF_INET)
    struct addrinfo nov6_hints;
    if (hints)
        nov6_hints = *hints;
    else
        memset(&nov6_hints, 0, sizeof(nov6_hints));
    nov6_hints.ai_family = AF_INET;   // 只允许 IPv4
    nov6_hints.ai_flags |= AI_ADDRCONFIG;

    return real_getaddrinfo(node, service, &nov6_hints, res);
}
