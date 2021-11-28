#include "testObjects.h"
#include <iostream>
#include <string>

/* Class:     Test2_Tester
* Method:    initObject
* Signature: ()LTest2/Person;
*/

JNIEXPORT jobject JNICALL Java_Test2_Tester_initObject(JNIEnv* jvm, jobject obj)
{
	jclass personClass = jvm->FindClass("Test2/Person");

	jmethodID constructorId = jvm->GetMethodID(personClass, "<init>", "()V");
	jmethodID setAgeId = jvm->GetMethodID(personClass, "setAge", "(I)V");
	jmethodID setNameId = jvm->GetMethodID(personClass, "setName", "(Ljava/lang/String;)V");

	//inistaciating new object with the constructor
	jobject personObject = jvm->NewObject(personClass, constructorId);

	
	jvm->CallObjectMethod(personObject, setAgeId ,90);

	jstring name = jvm->NewStringUTF("omar");
	jvm->CallObjectMethod(personObject, setNameId, name);
	

	return personObject;
}

void JNICALL Java_Test2_Tester_printObjects(JNIEnv* jvm, jobject obj, jobjectArray arr)
{
	jint len = jvm->GetArrayLength(arr);

	//methods to be invoked
	jclass personClass = jvm->FindClass("Test2/Person");

	
	jmethodID getAge = jvm->GetMethodID(personClass, "getAge", "()I");
	jmethodID getName = jvm->GetMethodID(personClass, "getName", "()Ljava/lang/String;");
	

	for (int i = 0; i < len; i++)
	{
		jobject person = jvm->GetObjectArrayElement(arr, i);
		//std::cout << jvm->CallObjectMethod(person, getName) << std::endl;
		jobject nameobj = jvm->CallObjectMethod(person, getName);
		std::string name = jvm->GetStringUTFChars((jstring)nameobj, 0);
		std::cout << "person's name is : " << name << std::endl;
		jint age = jvm->CallIntMethod(person, getAge);
		std::cout << "person's age is: " << age << std::endl;
	}
	//jobject persons = jvm->GetObjectArrayElement(arr, 0);
}
