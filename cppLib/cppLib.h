/* DO NOT EDIT THIS FILE - it is machine generated */
#include "include/jni.h"
/* Header for class TestPackage_Test */

#ifndef _Included_TestPackage_Test
#define _Included_TestPackage_Test
#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * Class:     TestPackage_Test
	 * Method:    sayHello
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_TestPackage_Test_sayHello
	(JNIEnv*, jobject);

	/*
	 * Class:     TestPackage_Test
	 * Method:    multiply
	 * Signature: (DD)D
	 */
	JNIEXPORT jdouble JNICALL Java_TestPackage_Test_multiply
	(JNIEnv*, jobject, jdouble, jdouble);

	/*
	 * Class:     TestPackage_Test
	 * Method:    concat_string
	 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_TestPackage_Test_concat_1string
	(JNIEnv*, jobject, jstring, jstring);

	/*
	 * Class:     TestPackage_Test
	 * Method:    printObjectContents
	 * Signature: (LTestPackage/Person;)V
	 */
	JNIEXPORT void JNICALL Java_TestPackage_Test_printObjectContents
	(JNIEnv*, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
