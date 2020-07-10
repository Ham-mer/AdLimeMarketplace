//
//  AdLimeMarketplaceSplash.h

//
//  Created by AdLimeMarketplace on 2020/02/02.
//  Copyright © 2020 AdLimeMarketplace. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdLimeMarketplaceAdError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AdLimeMarketplaceSplashDelegate;

/// An Splash ad. This is a full-screen advertisement shown at natural transition points in
/// your application such as between game levels or news stories.
@interface AdLimeMarketplaceSplash : NSObject


/// Initializes an Splash with an ad unit created on the Sdk website. Create a new ad unit
/// for every unique placement of an ad in your application. Set this to the ID assigned for this
/// placement. Ad units are important for targeting and statistics.
- (instancetype _Nonnull )initWithAdUnitId:(NSString *_Nullable)adUnitId;

#pragma mark Pre-Request

/// Optional delegate object that receives state change notifications from this AdLimeMarketplaceSplash.
@property(nonatomic, weak, nullable) id<AdLimeMarketplaceSplashDelegate> delegate;

@property(nonatomic) CGFloat bidFloor;

@property (nonatomic, assign) NSInteger fetchDelay;

#pragma mark Making an Ad Request

/// Makes an Splash ad request. Additional targeting options can be supplied with a request
/// object. Only one Splash request is allowed at a time.
///
/// This is best to do several seconds before the Splash is needed to preload its content.
/// Then when transitioning between view controllers show the interstital with
/// presentFromViewController.
- (void)loadAndShow: (UIWindow *)window;

- (double) getBidPrice;

@end

@protocol AdLimeMarketplaceSplashDelegate <NSObject>

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Called when an splash ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)splashAdDidLoad:(AdLimeMarketplaceSplash *)ad;

/// Called when an splash ad request completed without an splash to
/// show. This is common since splashs are shown sparingly to users.
- (void)splash:(AdLimeMarketplaceSplash *)ad didLoadedFailWithError:(AdLimeMarketplaceAdError *)error;

#pragma mark Display-Time Lifecycle Notifications

/// Called just before presenting an splash. After this method finishes the splash will
/// animate onto the screen. Use this opportunity to stop animations and save the state of your
/// application in case the user leaves while the splash is on screen (e.g. to visit the App
/// Store from a link on the splash).
- (void)splashWillPresentScreen:(AdLimeMarketplaceSplash *)ad;

/// Called when |ad| did to present.
- (void)splashDidPresentScreen:(AdLimeMarketplaceSplash *)ad;

/// Called before the splash is to be animated off the screen.
- (void)splashWillDismissScreen:(AdLimeMarketplaceSplash *)ad;

/// Called just after dismissing an splash and it has animated off the screen.
- (void)splashDidDismissScreen:(AdLimeMarketplaceSplash *)ad;

/// Called just before the application will background or terminate because the user clicked on an
/// ad that will launch another application (such as the App Store). The normal
/// UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
/// before this.
- (void)splashWillLeaveApplication:(AdLimeMarketplaceSplash *)ad;

@end

NS_ASSUME_NONNULL_END
