//
//  NSItemProvider+UIKitAdditions.h
//  UIKit
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <CoreGraphics/CoreGraphics.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIPreferredPresentationStyle) {
    UIPreferredPresentationStyleUnspecified = 0,
    UIPreferredPresentationStyleInline,
    UIPreferredPresentationStyleAttachment,
};

@interface NSItemProvider (UIKitAdditions)

@property (nonatomic, copy, nullable) NSData *teamData API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

// Estimated presentation size, in points. CGSizeZero value indicates this information is not available.
@property (nonatomic) CGSize preferredPresentationSize API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@property (nonatomic) UIPreferredPresentationStyle preferredPresentationStyle;

@end

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos)
@protocol UIItemProviderPresentationSizeProviding <NSObject>

// Implement this on an object which conforms to the NSItemProviderWriting protocol.
// When the object is registered to NSItemProvider, this property will be used to automatically set
// the `preferredPresentationSize` property on NSItemProvider.
// Return CGSizeZero to indicate that this information is not available.
@property (nonatomic, readonly) CGSize preferredPresentationSizeForItemProvider;

@end

NS_ASSUME_NONNULL_END
