LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

# This is the target being built.
LOCAL_MODULE:= libled_ndkjni

# All of the source files that we will compile.
LOCAL_SRC_FILES:= \
    com_example_lowlevel_LedNative.cpp

# All of the shared libraries we link against.
LOCAL_LDLIBS := -llog

# No static libraries.
LOCAL_STATIC_LIBRARIES :=

LOCAL_CFLAGS := -Wall -Werror


include $(BUILD_SHARED_LIBRARY)