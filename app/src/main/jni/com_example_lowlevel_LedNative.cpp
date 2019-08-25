//
// Created by soengtung.朱 on 2019-08-26.
//

#include <jni.h>
#define LOG_TAG "ledNative.cpp"
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "com_example_lowlevel_LedNative.h"

#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define ALOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define ALOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static const char *ledDevNode = "/sys/devices/platform/leds/leds/user_led3/brightness";
static int fd;

/*
 * Class:     com_example_lowlevel_LedNative
 * Method:    openDev
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_lowlevel_LedNative_openDev
  (JNIEnv *, jobject)
{
    ALOGD("------%s", __FUNCTION__);

    fd = open(ledDevNode, O_RDWR);
    if (fd < 0) {
        ALOGE("open: %s", strerror(errno));
        return -1;
    }
    ALOGD("------%s() return", __FUNCTION__);
    return 0;
}

/*
 * Class:     com_example_lowlevel_LedNative
 * Method:    closeDev
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_lowlevel_LedNative_closeDev
  (JNIEnv *, jobject)
{
    ALOGD("------%s", __FUNCTION__);

    close(fd);
    return 0;
}

/*
 * Class:     com_example_lowlevel_LedNative
 * Method:    devOn
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_lowlevel_LedNative_devOn
  (JNIEnv *, jobject)
{
    jint ret;
    ALOGD("------%s, fd=%d", __FUNCTION__, fd);

    ret = write(fd, "255", 4);
    if (ret < 0) {
        ALOGE("write: %s", strerror(errno));
        return -1;
    }
    return 0;
}

/*
 * Class:     com_example_lowlevel_LedNative
 * Method:    devOff
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_lowlevel_LedNative_devOff
  (JNIEnv *, jobject)
{
    jint ret;
    ALOGD("------%s, fd=%d", __FUNCTION__, fd);

    ret = write(fd, "0", 2);
    if (ret < 0) {
        ALOGE("write: %s", strerror(errno));
        return -1;
    }
    return 0;
}

#ifdef __cplusplus
}
#endif