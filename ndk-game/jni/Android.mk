LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := hello-jni
LOCAL_SRC_FILES := hello.cpp \
                   tinyxml2.cpp

include $(BUILD_SHARED_LIBRARY)




