//
//  DLSingletion.h
//  单例宏定义
//
//  Created by Aaron on 16/4/13.

//用法：1. 创建单例类，导入此头文件。
//     2. .h文件中写入singleton_h(name)
//     3. .m文件中写入singleton_m(name)
//     4. 重写init
//
//- (instancetype)init {
//    
//    if (self = [super init]) {
//        static dispatch_once_t onceToken;
//        dispatch_once(&onceToken, ^{
//            //加载资源
//        });
//    }
//    
//    return self;
//}
//
//

#define singleton_h(name) + (instancetype)shared##name;

#if __has_feature(objc_arc) //ARC

#define singleton_m(name)\
static id _instance = nil;\
\
+ (instancetype)shared##name {\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [[self alloc] init];\
    });\
    return _instance;\
}\
\
+ (id)allocWithZone:(struct _NSZone *)zone {\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [super allocWithZone:zone];\
    });\
    return _instance;\
}\
\
- (id)copyWithZone:(nullable NSZone *)zone {\
    return _instance;\
}\
\
- (id)mutableCopyWithZone:(nullable NSZone *)zone {\
    return _instance;\
}

#else //NO ARC

#define singleton_m(name)\
static id _instance = nil;\
\
+ (instancetype)sharedNetTool {\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [[self alloc] init];\
    });\
    return _instance;\
}\
\
+ (id)allocWithZone:(struct _NSZone *)zone {\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [super allocWithZone:zone];\
    });\
    return _instance;\
}\
\
- (id)copyWithZone:(nullable NSZone *)zone {\
    return _instance;\
}\
\
- (id)mutableCopyWithZone:(nullable NSZone *)zone {\
    return _instance;\
}\
\
- (id)retain {\
    return _instance;\
}\
\
- (oneway void)release {\
    \
}\
\
- (id)autorelease {\
    return _instance;\
}\
\
- (NSUInteger)retainCount {\
    return 1;\
}

#endif
