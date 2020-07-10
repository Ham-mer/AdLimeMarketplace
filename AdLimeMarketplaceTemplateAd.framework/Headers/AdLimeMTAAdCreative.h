//
//  AdLimeMTAAdCreative.h
//  AdLimeMarketplaceTemplateAd
//
//  Created by nathads on 2020/4/23.
//  Copyright © 2020 nathads. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdLimeMTAAdCreative : NSObject

@property (nonatomic, strong) NSString *videoUrl;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *body;
@property (nonatomic, strong) NSString *iconUrl;
@property (nonatomic, strong) NSString *callToAction;

@property (nonatomic, strong) NSString *videoCover;
@property (nonatomic) BOOL voiceControl;
@property (nonatomic) CGFloat rating;
@property (nonatomic) NSInteger target;

@property (nonatomic) NSInteger adType;           //1:激励视频，2：插屏

@property (nonatomic, strong) NSString *endCoverHtml;
@property (nonatomic, strong) NSString *endCoverImage;

@property (nonatomic, strong) NSDictionary *customParam;

@end

NS_ASSUME_NONNULL_END
