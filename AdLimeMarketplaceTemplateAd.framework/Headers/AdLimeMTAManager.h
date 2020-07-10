//
//  AdLimeMTAManager.h
//  AdLimeMarketplaceTemplateAd
//
//  Created by nathads on 2020/4/7.
//  Copyright © 2020 nathads. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdLimeMTAExpressAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AdLimeMTAManagerDelegate  <NSObject>

@optional
- (void)trackCustomEvent: (NSDictionary *)message;

@end

@interface AdLimeMTAManager : NSObject

@property (nonatomic) BOOL             testMode;
@property (nonatomic, readonly) NSString *appId;

@property (nonatomic, weak) id<AdLimeMTAManagerDelegate> delegate;

+ (instancetype)getManager;

+ (void) initWithAppId: (NSString *)appId;

+ (BOOL)templateHasReady;


- (void) setLogEnable:(BOOL)enable;
- (BOOL) isLogEnable;

- (void) setMediaCacheFolder: (NSString *)mediaCacheFolder;
- (NSString *) getMediaCacheFolder;

- (void) setMaxMediaCacheSize: (NSUInteger)size;
- (NSUInteger) getMaxMediaCacheSize;

- (int)getSdkVersion;

- (BOOL)hasTemplateInfo:(NSString *)adunitId;

@end

NS_ASSUME_NONNULL_END
