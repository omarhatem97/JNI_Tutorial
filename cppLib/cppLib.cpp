#include "cppLib.h"
#include <iostream>
#include <string>
#include <cstdio>


void JNICALL Java_TestPackage_Test_sayHello
(JNIEnv* env, jobject obj)
{
	std::cout << "hello from lib!\n";
}


jdouble JNICALL Java_TestPackage_Test_multiply
	(JNIEnv* env, jobject obj, jdouble param1, jdouble param2)
{
	return param1 * param2;
}


jstring JNICALL Java_TestPackage_Test_concat_1string(JNIEnv* env, jobject ob, jstring a, jstring b)
{
	const char* str = env->GetStringUTFChars(a, 0);
	const char* str1 = env->GetStringUTFChars(b, 0);

	std::string s(str) , s1(str1);
	std::string res = s + s1;

	env->ReleaseStringUTFChars(a, str);
	env->ReleaseStringUTFChars(b, str1);

	return env->NewStringUTF(res.c_str());
}


void JNICALL Java_TestPackage_Test_printObjectContents
(JNIEnv* env, jobject obj, jobject myObject)
{
	jclass person_class = env->FindClass("TestPackage/Person");

	jfieldID fieldId = env->GetFieldID(person_class, "age", "I");

	jint objectField = env->GetIntField(myObject, fieldId);

	int age = (int)objectField;
	std::cout << "you age is : " << age << std::endl;
}
