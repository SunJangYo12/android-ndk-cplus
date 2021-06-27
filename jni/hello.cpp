#include <string.h>
#include <jni.h>

#include "tinyxml2.h"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if defined( _MSC_VER ) || defined (WIN32)
	#include <crtdbg.h>
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	_CrtMemState startMemState;
	_CrtMemState endMemState;
#else
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

using namespace tinyxml2;
using namespace std;
int gPass = 0;
int gFail = 0;


#ifdef __cplusplus
extern "C" {
#endif

class Test {
  public:
    Test(){};
    ~Test(){};

    int SomeFunc() { 
       return 5; 
    }

    const char *example_3()
    {
	static const char* xml =
		"<?xml version=\"1.0\"?>"
		"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
		"<PLAY>"
		"<TITLE>A Midsummer Night's Dream</TITLE>"
		"</PLAY>";

	XMLDocument doc;
	doc.Parse( xml );

	XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
	const char* title = titleElement->GetText();
	printf( "Name of play (1): %s\n", title );

	XMLText* textNode = titleElement->FirstChild()->ToText();
	title = textNode->Value();
	printf( "Name of play (2): %s\n", title );

	//return doc.ErrorID();
        return title;
    }
};

jint Java_com_game_MainActivity_cplus(JNIEnv *env, jobject thiz)
{
    Test *test = new Test();
    return test->SomeFunc();
}

#ifdef __cplusplus
}
#endif

extern "C" jstring Java_com_game_MainActivity_str( JNIEnv* env, jobject thiz )
{
#if defined(__arm__)
    #if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a/NEON (hard-float)"
      #else
        #define ABI "armeabi-v7a/NEON"
      #endif
    #else
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a (hard-float)"
      #else
        #define ABI "armeabi-v7a"
      #endif
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
#define ABI "x86"
#elif defined(__x86_64__)
#define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
#define ABI "mips64"
#elif defined(__mips__)
#define ABI "mips"
#elif defined(__aarch64__)
#define ABI "arm64-v8a"
#else
#define ABI "unknown"
#endif

    Test *test = new Test();

    return env->NewStringUTF(test->example_3());;
}


