//
//  AdLimeMTAExpressAd.h
//  AdLimeMarketplaceTemplateAd
//
//  Created by nathads on 2020/4/23.
//  Copyright © 2020 nathads. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdLimeMTAError.h"
#import "AdLimeMTAAdCreative.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AdLimeMTA_CUSTOM_EVENT) {
    AdLimeMTA_CUSTOM_EVENT_VIDEO_PAUSE         = 2001, // 'videoStart';
    AdLimeMTA_CUSTOM_EVENT_VIDEO_RESUME      = 2002, // 'videoComplete';
//    AdLimeMTA_CUSTOM_EVENT_VIDEO_FIRST_QUARTILE = 2003,// 'videoFirstQuartile';
//    AdLimeMTA_CUSTOM_EVENT_VIDEO_MIDDLE        = 2004, // 'videoMid';
//    AdLimeMTA_CUSTOM_EVENT_VIDEO_THIRD_QUARTILE = 2005,//  'videoThirdQuartile';
//    AdLimeMTA_CUSTOM_EVENT_VIDEO_SKIP          = 2006, // 'videoSkip'; // 1006
//    AdLimeMTA_CUSTOM_EVENT_VIDEO_ERROR         = 2007, // 'videoError'; // 1007
//    AdLimeMTA_CUSTOM_EVENT_AUDIO_MUTE          = 2008, // 'audioMute'; // 1008
//    AdLimeMTA_CUSTOM_EVENT_AUDIO_UNMUTE        = 2009, // 'audioUnmute'; // 1009
    AdLimeMTA_CUSTOM_EVENT_ERROR_REPORT        = 2010, // 'errorReport'; // 2010
    AdLimeMTA_CUSTOM_EVENT_REPORT              = 2011, // 'eventReport'; // 2011
    AdLimeMTA_CUSTOM_EVENT_REQUEST             = 2012, // 'sendRequest'; // 2012
};

typedef NS_ENUM(NSInteger, AdLimeMTA_CLICK_EVENT_TYPE) {
    //自定义
    AdLimeMTA_CLICK_EVENT_TYPE_OPEN, // '点击'
    AdLimeMTA_CLICK_EVENT_TYPE_CLOSE, // '关闭'
    AdLimeMTA_CLICK_EVENT_TYPE_SKIP, // '跳过'
    AdLimeMTA_CLICK_EVENT_TYPE_MUTE, // '静音'
    AdLimeMTA_CLICK_EVENT_TYPE_UNMUTE, // '取消静音'
    AdLimeMTA_CLICK_EVENT_TYPE_VIDEO // '视频'
};

typedef NS_ENUM(NSInteger, AdLimeMTA_REQUEST_EVENT_METHID) {
    AdLimeMTA_REQUEST_EVENT_METHID_GET       = 0, // get
    AdLimeMTA_REQUEST_EVENT_METHID_POST      = 1 //post
};

@class AdLimeMTAExpressAd;

@protocol AdLimeMTAExpressAdDelegate  <NSObject>

@optional
- (void)ExpressAdRenderDidFinish:(AdLimeMTAExpressAd *)ad;
- (void)expressAd:(AdLimeMTAExpressAd *)ad didRenderFailWithError:(AdLimeMTAError * _Nullable)error;

//- (void)ExpressAdRenderReady:(AdLimeMTAExpressAd *)ad message: (NSDictionary * _Nullable)message;

- (void)ExpressAdOnClick:(AdLimeMTAExpressAd *)ad clickType: (AdLimeMTA_CLICK_EVENT_TYPE)clickType startPoint: (CGPoint)startPoint endPoint: (CGPoint)endPoint;

- (void)ExpressAdCustomEvent: (AdLimeMTAExpressAd *)ad eventID: (AdLimeMTA_CUSTOM_EVENT)eventID message: (NSDictionary * _Nullable)message;

- (void)ExpressAdReportEvent: (AdLimeMTAExpressAd *)ad message: (NSDictionary *)message;
- (void)ExpressAdRequestEvent: (AdLimeMTAExpressAd *)ad method: (AdLimeMTA_REQUEST_EVENT_METHID)method host: (NSString *)host param: (NSDictionary * _Nullable)param needGlobalParam: (BOOL)needGlobalParam;

@end

@interface AdLimeMTAExpressAd : UIView

@property (nonatomic, weak) id<AdLimeMTAExpressAdDelegate> delegate;

+ (instancetype) renderAdUnit: (NSString *)adunitID adData: (AdLimeMTAAdCreative *)adData viewFrame: (CGRect) viewFrame delegate: (id<AdLimeMTAExpressAdDelegate>)delegate;

- (instancetype)initWithAdUnit: (NSString *)adunitID adData: (AdLimeMTAAdCreative *)adData viewFrame: (CGRect) viewFrame delegate: (id<AdLimeMTAExpressAdDelegate>)delegate;

- (void)startRender;

- (void)playVideo;
- (void)pauseVideo;
- (void)resumeVideo:(NSTimeInterval) duarion;
- (void)completeVideo;
- (BOOL)templateIsReady;
- (NSString *)currentTemplateId;
- (NSString *)currentJSRenderVer;

- (void)noUseExpressAd;

- (void)bringWebViewToFront;
@end

NS_ASSUME_NONNULL_END
