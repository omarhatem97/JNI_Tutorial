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

	//get class person
	jclass personClass = jvm->FindClass("Test2/Person");

	//methods to be invoked
	jmethodID getAge = jvm->GetMethodID(personClass, "getAge", "()I");
	jmethodID getName = jvm->GetMethodID(personClass, "getName", "()Ljava/lang/String;");
	
	//loop over the array
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


//function will instanciate Person objects , fill them with names and ages Then append these 
//objects to list that is a prop in EventArgs class , then returns eventargs object back to java

jobject Java_Test2_Tester_retrieve(JNIEnv* jvm, jobject obj)
{	
	//find class list
	jclass listClass = jvm->FindClass("Ljava/util/List;");
	//get list class necessary methods
	jmethodID add = jvm->GetMethodID(listClass, "add", "(Ljava/lang/Object;)Z");

	//find class person with its methods
	jclass personClass = jvm->FindClass("Test2/Person");

	jmethodID constructorId = jvm->GetMethodID(personClass, "<init>", "()V");
	jmethodID setAgeId = jvm->GetMethodID(personClass, "setAge", "(I)V");
	jmethodID setNameId = jvm->GetMethodID(personClass, "setName", "(Ljava/lang/String;)V");

	//inistaciating new objects with the constructor
	jobject personObject1 = jvm->NewObject(personClass, constructorId);
	jobject personObject2 = jvm->NewObject(personClass, constructorId);
	jobject personObject3 = jvm->NewObject(personClass, constructorId);

	//Setting ages
	jvm->CallObjectMethod(personObject1, setAgeId, 10);
	jvm->CallObjectMethod(personObject2, setAgeId, 20);
	jvm->CallObjectMethod(personObject3, setAgeId, 30);

	//setting names
	jstring name = jvm->NewStringUTF("omar");
	jvm->CallObjectMethod(personObject1, setNameId, name);

	name = jvm->NewStringUTF("hatem");
	jvm->CallObjectMethod(personObject2, setNameId, name);

	name = jvm->NewStringUTF("Hassan");
	jvm->CallObjectMethod(personObject3, setNameId, name);

	
	//find class EventArgs
	jclass EventArgs = jvm->FindClass("Test2/EventArgs");

	//create object from class EventArgs
	jmethodID eventArgsconstructorId = jvm->GetMethodID(EventArgs, "<init>", "()V");
	jobject eventArgsObj = jvm->NewObject(EventArgs, eventArgsconstructorId);

	jfieldID personsListId = jvm->GetFieldID(EventArgs, "list", "Ljava/util/List;");
	jobject personsList = jvm->GetObjectField(eventArgsObj, personsListId);

	jvm->CallBooleanMethod(personsList, add, personObject1);
	jvm->CallBooleanMethod(personsList, add, personObject2);
	jvm->CallBooleanMethod(personsList, add, personObject3);
	
	return eventArgsObj;
}


//return list of persons 
jobject JNICALL Java_Test2_Tester_retrieveAll(JNIEnv* jvm, jobject obj)
{

	//find class person with its methods
	jclass personClass = jvm->FindClass("Test2/Person");

	jmethodID constructorId = jvm->GetMethodID(personClass, "<init>", "()V");
	jmethodID setAgeId = jvm->GetMethodID(personClass, "setAge", "(I)V");
	jmethodID setNameId = jvm->GetMethodID(personClass, "setName", "(Ljava/lang/String;)V");

	//inistaciating new objects with the constructor
	jobject personObject1 = jvm->NewObject(personClass, constructorId);
	jobject personObject2 = jvm->NewObject(personClass, constructorId);
	jobject personObject3 = jvm->NewObject(personClass, constructorId);

	//Setting ages
	jvm->CallObjectMethod(personObject1, setAgeId, 10);
	jvm->CallObjectMethod(personObject2, setAgeId, 20);
	jvm->CallObjectMethod(personObject3, setAgeId, 30);

	//setting names
	jstring name = jvm->NewStringUTF("Omar");
	jvm->CallObjectMethod(personObject1, setNameId, name);

	name = jvm->NewStringUTF("Hatem");
	jvm->CallObjectMethod(personObject2, setNameId, name);

	name = jvm->NewStringUTF("Hassan");
	jvm->CallObjectMethod(personObject3, setNameId, name);

	

	//find class ArrayList and get add function methodd id
	jclass arrayList = jvm->FindClass("java/util/ArrayList");
	jmethodID add = jvm->GetMethodID(arrayList, "add", "(Ljava/lang/Object;)Z");

	//create object from array list
	jmethodID arrayListConstructorId = jvm->GetMethodID(arrayList, "<init>", "()V");
	jobject arrayListObject = jvm->NewObject(arrayList, arrayListConstructorId);

	
	jvm->CallBooleanMethod(arrayListObject, add, personObject1);
	jvm->CallBooleanMethod(arrayListObject, add, personObject2);
	jvm->CallBooleanMethod(arrayListObject, add, personObject3);

	return arrayListObject;
}


// Takes a hashamp and prints it to the console
void JNICALL Java_Test2_Tester_printHashMap(JNIEnv* jvm, jobject obj, jobject map)
{
	jclass hashMapClass = jvm->FindClass("java/util/HashMap");
	jclass setClass = jvm->FindClass("java/util/Set");
	jclass iteratorClass = jvm->FindClass("java/util/Iterator");
	jclass IntClass = jvm->FindClass("java/lang/Integer");

	//get get method id
	jmethodID getId = jvm->GetMethodID(hashMapClass, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
	//get keyset method id
	jmethodID keysetId = jvm->GetMethodID(hashMapClass, "keySet", "()Ljava/util/Set;");

	//find methodid of iterator in setClass
	jmethodID setIterId = jvm->GetMethodID(setClass, "iterator", "()Ljava/util/Iterator;");

	//find method next and hasnext from iterator class
	jmethodID hasNextId = jvm->GetMethodID(iteratorClass, "hasNext", "()Z");
	jmethodID nextId = jvm->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");

	//find size methodId for hashmapClass
	jmethodID mapSize = jvm->GetMethodID(hashMapClass, "size", "()I");
	jmethodID intValue = jvm->GetMethodID(IntClass, "intValue", "()I");

	jint len = jvm->CallIntMethod(map, mapSize);
	std::cout << "size is : " << len << std::endl;


	//get key set
	jobject keyset = jvm->CallObjectMethod(map, keysetId);
	//get iterator
	jobject iter = jvm->CallObjectMethod(keyset, setIterId);


	while (jvm->CallBooleanMethod(iter, hasNextId))
	{
		jobject currentObj = jvm->CallObjectMethod(iter, nextId);
		jint current = jvm->CallIntMethod(currentObj, intValue);
		jobject personObject = jvm->CallObjectMethod(map, getId, currentObj);
		std::cout << "key: " << current << std::endl;
	}



	////find class ArrayList and get add function method id
	//jclass arrayList = jvm->FindClass("java/util/ArrayList");
	//jmethodID get = jvm->GetMethodID(arrayList, "get", "(I)Ljava/lang/Object;");
	//jmethodID sizemethodId = jvm->GetMethodID(arrayList, "size", "()I");
	//

	////create object from array list
	//jmethodID arrayListConstructorId = jvm->GetMethodID(arrayList, "<init>", "(Ljava/util/Collection;)V");
	//jobject arrayListObject = jvm->NewObject(arrayList, arrayListConstructorId, keyset);

	////get length of arraylist (which contains all keys)
	//jclass hashSetClass = jvm->FindClass("java/util/HashSet");
	//jmethodID getSizeId = jvm->GetMethodID(hashSetClass, "size", "()I");
	//int len = jvm->CallIntMethod(keyset, getSizeId);

	//for (int i = 0; i < len; i++)
	//{
	//	//get key as a string
	//	jint key = jvm->CallIntMethod(arrayListObject, get, i);
	//	//std::string key = jvm->GetStringUTFChars((jstring)keyObject, 0);

	//	std::cout << key << std::endl;
	//	//access the value and print it
	//	jobject empolyeeObject = jvm->CallObjectMethod(map, getId, key);

	//}

}


