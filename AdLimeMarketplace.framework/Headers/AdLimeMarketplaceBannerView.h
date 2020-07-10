//
//  AdLimeMarketplaceBannerView.h
//
//  Created by AdLimeMarketplace on 2019/6/10.
//  Copyright © 2019 AdLimeMarketplace. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdLimeMarketplaceAdError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AdLimeMarketplaceBannerViewDelegate;

@interface AdLimeMarketplaceBannerView : UIView


// The delegate `AdLimeMarketplaceBannerViewDelegate` of the ad view. Typically this is a UIViewController.
@property (nonatomic, weak) id<AdLimeMarketplaceBannerViewDelegate> delegate;
// Required to set this banner view to a proper size. (320*50 300*250)
@property (nonatomic, assign) CGSize  adSize;
@property (nonatomic, assign) CGFloat bidFloor;
@property (nonatomic, weak, nullable) UIViewController *rootViewController;

/// Returns YES if the banner is ready to be loaded. The delegate's
/// bannerAdDidLoad: will be called after this property switches from NO to YES.
@property(nonatomic, readonly) BOOL isReady;



- (double) getBidPrice;

/**
 * Initializes an AdLimeMarketplaceBannerView with the given ad unit ID and banner size.
 *
 * @param adUnitId A string representing a Sdk ad unit ID.
 * @param adSize The desired ad size. A list of standard ad sizes is available in MPConstants.h.
 * @return A newly initialized ad view corresponding to the given ad unit ID and size.
 */
- (instancetype _Nonnull )initWithAdUnitId:(NSString *_Nullable)adUnitId size:(CGSize)adSize;

/**
 * Requests a new ad from the WePub ad server.
 *
 * If the ad view is already loading an ad, this call will be ignored.
 */
- (void)loadAd;

@end

@protocol AdLimeMarketplaceBannerViewDelegate  <NSObject>

@optional

/** @name Detecting When a Banner Ad is Loaded */

/**
 * Sent when an ad view successfully loads an ad.
 *
 * Your implementation of this method should insert the ad view into the view hierarchy, if you
 * have not already done so.
 *
 * @param view The ad view sending the message.
 */
- (void)bannerAdDidLoad:(AdLimeMarketplaceBannerView *)view;

/**
 * Sent when an ad view fails to load an ad.
 *
 * To avoid displaying blank ads, you should hide the ad view in response to this message.
 *
 * @param view The ad view sending the message.
 * @param error The error
 */
- (void)adView:(AdLimeMarketplaceBannerView *)view didLoadedFailWithError:(AdLimeMarketplaceAdError *)error;

/** @name Detecting When a User Interacts With the Ad View */

/**
 * Sent when an ad view is about to present modal content.
 *
 * This method is called when the user taps on the ad view. Your implementation of this method
 * should pause any application activity that requires user interaction.
 *
 * @param view The ad view sending the message.
 * @see `didDismissModalViewForAd:`
 */
- (void)willPresentModalViewForAd:(AdLimeMarketplaceBannerView *)view;

/**
 * Sent when an ad view has dismissed its modal content, returning control to your application.
 *
 * Your implementation of this method should resume any application activity that was paused
 * in response to `willPresentModalViewForAd:`.
 *
 * @param view The ad view sending the message.
 * @see `willPresentModalViewForAd:`
 */
- (void)didDismissModalViewForAd:(AdLimeMarketplaceBannerView *)view;

/**
 * Sent when a user is about to leave your application as a result of tapping
 * on an ad.
 *
 * Your application will be moved to the background shortly after this method is called.
 *
 * @param view The ad view sending the message.
 */
- (void)willLeaveApplicationFromAd:(AdLimeMarketplaceBannerView *)view;

@end

NS_ASSUME_NONNULL_END
