#pragma once

#include "cocos2d.h"

/** @def INIT_CHECKER(__CC_TYPE__, __CC_ID__)
 * Define a auto check valid function for a specific type such as Sprite
 *
 * @pragma __CC_TYPE__ a cocos class type to check valid __CC_ID__
 * @pragma __CC_ID__ a variable need to be checked if it existed or cocos class can create a variable with it
 */ 
#define INIT_CHECKER(__CC_TYPE__, __CC_ID__) \
{\
	__CC_TYPE__ *pElement = __CC_TYPE__::create(__CC_ID__); \
	if(!pElement) \
	{ \
		CC_SAFE_DELETE(pElement); \
		return false; \
	} \
}\

#define FILE_CHECKER(__FILE_ADDRESS__) \
{ \
	if (cocos2d::FileUtils::getInstance()->isFileExist(__FILE_ADDRESS__)) \
		return true; \
	else return false; \
}

#define FILE_CHECKER_ZYFUNC(__TYPE__) \
bool isValidFile(std::string sFileName) \
{ \
	FILE_CHECKER(sFileName); \
}                                     \

/** @def BEGIN_CREATE_REFCLASS(__NAME__, __REF_CLASS__)\n
 *  Define a new class inherits other class
 *
 *  @pragma __NAME__ this is the new class's name
 *  @pragma __REF_CLASS__ this is the name of class which this class will inherit
 *
 *  @warning Must call END_CREATE_REFCLASS after call this
 */
#define BEGIN_CREATE_REFCLASS(__NAME__, __REF_CLASS__) \
class __NAME__ : public __REF_CLASS__                  \
{                                                    \
public:                                              \
    CREATE_FUNC(__NAME__);                           \
protected:                                           \
    bool init();                                     \
private:                                             \
    __NAME__();                                      \


#define END_CREATE_REFCLASS };

/** @def BEGIN_CREATE_INSTANCE_REFCLASS(__NAME__,__REF_CLASS__)\n
 * 	Define a new class have an instance pointer
 *
 * 	@pragma __NAME__ this is the new class's name
 * 	@praama __REF_CLASS__ this is the name of class which tis class will inherit
 *
 * 	@warning Must call END_CREATE_INSTANCE_REFCLASS after call this \n
 * 			 Make sp_pInstance = nullptr att cpp file
 */
#define BEGIN_CREATE_INSTANCE_REFCLASS(__NAME__, __REF_CLASS__)                          \
class __NAME__ : public __REF_CLASS__                                                    \
{                                                                                        \
public:                                                                                  \
	inline static __NAME__* getInstance()                                              	 \
    {                                                                                  	 \
        return sp_pInstance = (sp_pInstance != nullptr) ? sp_pInstance : new __NAME__();  \
	}                                                                                    \
private:                                                                                 \
	__NAME__();                                                                          \
	static __NAME__* sp_pInstance;                                                       \

#define END_CREATE_INSTANCE_REFCLASS };


/** @def CLEANER(__TYPE__)
* Define a cleaner function for a specific class
* 
* @pragma __TYPE__ class type to add cleaner() function
*/
#define CLEANER_ZYFUNC(__TYPE__)\
inline static void cleaner(__TYPE__ *pElement) \
{ \
	CC_SAFE_DELETE(pElement); \
} 	

#define GET_CLASS_ADDRESS(__TYPE__, __VARIABLE__)\
{ \
std::stringstream ss; \
ss << __VARIABLE__; \
std::string address = ss.str(); \
CCLOG("Address: %s", address.c_str()); \
} \

#define SET_UNIFORM(ps, name, value)  do {   \
decltype(value) __v = value;                           \
auto __loc = (ps)->getUniformLocation(name);  \
(ps)->setUniform(__loc, &__v, sizeof(__v));  \
} while(false) 

#define SET_TEXTURE(ps, name, idx, value)  do {   \
auto * __v = value;                           \
auto __loc = (ps)->getUniformLocation(name);  \
(ps)->setTexture(__loc, idx, __v);  \
} while(false) 


/* Generic macros 
* @namespace nova
* @{
*/
#ifdef __cplusplus
	#define NS_ZY_BEGIN namespace zy { 
	#define NS_ZY_END }
	#define USING_NS_ZY using namespace zy
	#define USING_NS_JSON using namespace nlohmann

	#define USING_NS_ALL  \
        USING_NS_JSON;     \
		USING_NS_ZY;        \
		USING_NS_CC;         \

	#define NS_ZY ::zy
#endif

