LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := tinyxml2
LOCAL_SRC_FILES := tinyxml2.cpp

include $(BUILD_STATIC_LIBRARY)


include $(CLEAR_VARS)

LOCAL_MODULE    := hello-jni
LOCAL_SRC_FILES := hello.cpp
LOCAL_STATIC_LIBRARIES := tinyxml2

include $(BUILD_SHARED_LIBRARY)






