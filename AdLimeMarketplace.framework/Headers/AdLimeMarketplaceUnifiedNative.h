//
//  AdLimeMarketplaceUnifiedNative.h

//
//  Created by AdLimeMarketplace on 2019/6/19.
//  Copyright © 2019 AdLimeMarketplace. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AdLimeMarketplaceMaterialType) {
    AdLimeMarketplaceMaterialType_Unknown = 0,            //未知
    AdLimeMarketplaceMaterialType_Small_Image= 1,         //小图
    AdLimeMarketplaceMaterialType_Large_Image= 2,         //大图
    AdLimeMarketplaceMaterialType_Group_Image= 3,         //组图
    AdLimeMarketplaceMaterialType_Video= 4,               //视频
};

typedef NS_ENUM(NSUInteger, AdLimeMarketplaceNativeTargetType) {
    AdLimeMarketplaceNativeTargetType_Unknown = 0,            //未知
    AdLimeMarketplaceNativeTargetType_Web = 1,               //网页跳转
    AdLimeMarketplaceNativeTargetType_Download= 2,            //下载
};


@interface AdLimeMarketplaceUnifiedNative : NSObject

- (instancetype)initNativeAds: (NSObject *)responseData nativeObject: (NSObject *)nativeObject;

@property (nonatomic, readonly) NSString * title;
@property (nonatomic, readonly) NSString * body;
@property (nonatomic, readonly) NSString * callToAction;
@property (nonatomic, readonly) NSString * iconUrl;
@property (nonatomic, readonly) NSArray<NSString *> *imageUrls;
@property (nonatomic, readonly) NSString * advertiser;
@property (nonatomic, readonly) NSString * store;
@property (nonatomic, readonly) NSString * price;
@property (nonatomic, readonly) CGFloat rating;


@property (nonatomic, readonly) AdLimeMarketplaceMaterialType materialType;

@property (nonatomic, readonly) AdLimeMarketplaceNativeTargetType targetType;

@property (nonatomic, readonly) CGFloat mainImageWidth;
@property (nonatomic, readonly) CGFloat mainImageHeight;


-(UIView *)getMediaViewWithFrame:(CGRect)frame;


@property (nonatomic)   BOOL hasImpressioned;

- (void) registerViewForInteraction:(UIView *)adview clickableViews: (NSArray<UIView *> *) viewList;

@end

NS_ASSUME_NONNULL_END
