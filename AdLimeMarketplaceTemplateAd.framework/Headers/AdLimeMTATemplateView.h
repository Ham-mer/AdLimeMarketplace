//
//  AdLimeMTATemplateView.h
//  AdLimeMarketplaceTemplateAd
//
//  Created by nathads on 2020/4/30.
//  Copyright © 2020 nathads. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdLimeMTAAdCreative.h"
#import "AdLimeMTAExpressAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdLimeMTATemplateView : AdLimeMTAExpressAd


- (instancetype)initWithAdUnitId: (NSString *)adUnitID adData:(AdLimeMTAAdCreative *)adData frame: (CGRect)frame delegate: (id<AdLimeMTAExpressAdDelegate>)delegate;

- (void) addMediaView:(UIView *)mediaView;

@end

NS_ASSUME_NONNULL_END
