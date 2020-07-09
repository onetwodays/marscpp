/* SDS (Simple Dynamic Strings), A C dynamic strings library.
 *
 * Copyright (c) 2006-2014, Salvatore Sanfilippo <antirez at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __SDS_H
#define __SDS_H

#define SDS_MAX_PREALLOC (1024*1024)

#include <sys/types.h>
#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
#endif

// https://cloud.tencent.com/developer/article/1441547

typedef char *sds;    //sds指向sdshdr结构体里的 char buf[]

//简单的动态字符串，跟string差不多的，它采用预分配冗余空间的方式来减少内存的频繁分配
//  1.相比C语言字符串，使获取字符串长度时间复杂度降为O(1)
// 2. 杜绝缓冲区溢出
// 3.减少修改字符串时带来的内存重分配次数
// 4.空间预分配:  用于字符串增长操作，当字符串增长时，
// 程序会先检查需不需要对SDS空间进行扩展，如果需要扩展，
// 程序不仅会为SDS分配修改所必要的空间，还会为SDS分配额外的未使用空间，额外分配的未使用空间公式如下：
//① 如果对SDS修改之后，SDS的长度（修改之后len属性的值）小于1MB，
// 那么则分配和len属性同样大小的未使用空间，这时SDS的len属性和free属性的值相同。
// 如：如果修改之后SDS的len将变为10字节，那么程序也会分配10字节的未使用空间，
// SDS的buf数组实际长度变为10 + 10 + 1 = 21（额外一个字节用于保存结束符\n）
// 惰性空间释放:用于优化SDS的字符串收缩操作，
// 当字符串收缩时，程序不会立即执行内存重分配来回收收缩后内存多出来的空间，而是使用free属性记录下来，以备将来使用
struct sdshdr {
    int len;//len表示存储的字符串实际长度,free表示buf中剩余的存储空间,len<1M时，len=free| len>=1M len=10M free=1M
    int free;//剩余
    char buf[]; //buf长度是len+free+1,最后的1字节保存\n;这个数组没有大小，是所谓的柔性数组，是不占据内存大小的
};


static inline size_t sdslen(const sds s) {
    struct sdshdr *sh = (struct sdshdr *)(s-sizeof *sh);//struct sdshdr *sh = (void*) (s-(sizeof(struct sdshdr)))
    return sh->len;
}

static inline size_t sdsavail(const sds s) {
    struct sdshdr *sh = (struct sdshdr *)(s-sizeof *sh);
    return sh->free;
}

sds sdsnewlen(const void *init, size_t initlen);

sds sdsnew(const char *init);

sds sdsempty(void);

size_t sdslen(const sds s);

sds sdsdup(const sds s);

void sdsfree(sds s);

size_t sdsavail(const sds s);

sds sdsgrowzero(sds s, size_t len);

sds sdscatlen(sds s, const void *t, size_t len);

sds sdscat(sds s, const char *t);

sds sdscatsds(sds s, const sds t);

sds sdscpylen(sds s, const char *t, size_t len);

sds sdscpy(sds s, const char *t);

sds sdscatvprintf(sds s, const char *fmt, va_list ap);

#ifdef __GNUC__
sds sdscatprintf(sds s, const char *fmt, ...)
    __attribute__((format(printf, 2, 3)));
#else
sds sdscatprintf(sds s, const char *fmt, ...);
#endif

sds sdscatfmt(sds s, char const *fmt, ...);

void sdstrim(sds s, const char *cset);

void sdsrange(sds s, int start, int end);

void sdsupdatelen(sds s);

void sdsclear(sds s);

int sdscmp(const sds s1, const sds s2);

sds *sdssplitlen(const char *s, int len, const char *sep, int seplen, int *count);

void sdsfreesplitres(sds *tokens, int count);

void sdstolower(sds s);

void sdstoupper(sds s);

sds sdsfromlonglong(long long value);

sds sdscatrepr(sds s, const char *p, size_t len);

sds *sdssplitargs(const char *line, int *argc);

sds sdsmapchars(sds s, const char *from, const char *to, size_t setlen);

sds sdsjoin(char **argv, int argc, char *sep, size_t seplen);

sds sdsjoinsds(sds *argv, int argc, const char *sep, size_t seplen);


/* Low level functions exposed to the user API */
sds sdsMakeRoomFor(sds s, size_t addlen);

void sdsIncrLen(sds s, int incr);

sds sdsRemoveFreeSpace(sds s);

size_t sdsAllocSize(sds s);
#ifdef __cplusplus
}
#endif

#endif
