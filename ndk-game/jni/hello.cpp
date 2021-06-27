#include <string.h>
#include <jni.h>


#ifdef __cplusplus
extern "C" {
#endif

class Test {
  public:
    Test(){};
    ~Test(){};
    int SomeFunc() { return 5; }
};

jint Java_com_game_MainActivity_cplus(JNIEnv *env, jobject thiz)
{
    Test *test = new Test();
    return test->SomeFunc();
}

#ifdef __cplusplus
}
#endif


