//
//  AdLimeMTAError.h
//  AdLimeMarketplaceTemplateAd
//
//  Created by nathads on 2020/4/23.
//  Copyright © 2020 nathads. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ADLIMEMARKETPLACE_TEMPLATEAD_ERROR) {
    ADLIMEMARKETPLACE_TEMPLATEAD_ERROR_CUSTOM =0, // custom错误
    ADLIMEMARKETPLACE_TEMPLATEAD_ERROR_RENDER = 1, // 渲染错误
    ADLIMEMARKETPLACE_TEMPLATEAD_ERROR_READY  = 2, // 准备错误
    ADLIMEMARKETPLACE_TEMPLATEAD_ERROR_PLAY = 3,     // 播放错误
    ADLIMEMARKETPLACE_TEMPLATEAD_ERROR_INIT = 4     // 初始化错误
};

@interface AdLimeMTAError : NSObject

@property (readonly, copy) NSString   *message;
@property (readonly)       NSInteger  errorCode;
@property (readonly)       ADLIMEMARKETPLACE_TEMPLATEAD_ERROR  errorType;

+ (instancetype)renderError: (NSInteger)code message:(NSString *)message;
+ (instancetype)readyError: (NSInteger)code message:(NSString *)message;
+ (instancetype)playError: (NSInteger)code message:(NSString *)message;
+ (instancetype)customError: (NSInteger)code message:(NSString *)message;
+ (instancetype)initError;

@end

NS_ASSUME_NONNULL_END
