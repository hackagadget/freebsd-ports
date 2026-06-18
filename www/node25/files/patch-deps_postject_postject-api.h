--- deps/postject/postject-api.h.orig	2025-10-19 00:00:00 UTC
+++ deps/postject/postject-api.h
@@ -9,7 +9,7 @@
 #if defined(__APPLE__) && defined(__MACH__)
 #include <mach-o/dyld.h>
 #include <mach-o/getsect.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <elf.h>
 #include <link.h>
 #include <sys/param.h>
@@ -43,7 +43,7 @@
   return sentinel[sizeof(POSTJECT_SENTINEL_FUSE)] == '1';
 }
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 static int postject__dl_iterate_phdr_callback(struct dl_phdr_info* info,
                                               size_t size,
                                               void* data) {
@@ -117,7 +117,7 @@
   }
 
   return ptr;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
   if (options != NULL && options->elf_section_name != NULL) {
     name = options->elf_section_name;
