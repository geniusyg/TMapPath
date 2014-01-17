//
//  TMapMarker.h
//  SKP-Sample
//
//  Created by developer on 12. 9. 25..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TMapLayer.h"

@interface TMapMarker : TMapLayer
{
    UIView  *label;
    UIColor *textForegroundColor;
    UIColor *textBackgroundColor;
}

@property (nonatomic, retain) UIView  *label;

@property (nonatomic, retain) UIColor *textForegroundColor;

@property (nonatomic, retain) UIColor *textBackgroundColor;

@property (nonatomic, retain) NSArray *aniCGImages;

@property (nonatomic, assign) double aniDuration;

@property (nonatomic, assign) BOOL isCustomMarker;

@property (nonatomic, assign) BOOL isLowZPosition;

+ (UIFont *)defaultFont;

- (id)initWithUIImage:(UIImage *)image;
- (id)initWithUIImage:(UIImage *)image anchorPoint:(CGPoint)anchorPoint;

- (void)changeLabelUsingText:(NSString *)text;
- (void)changeLabelUsingText:(NSString *)text position:(CGPoint)position;
- (void)changeLabelUsingText:(NSString *)text font:(UIFont *)font foregroundColor:(UIColor *)textColor backgroundColor:(UIColor *)backgroundColor;
- (void)changeLabelUsingText:(NSString *)text position:(CGPoint)position font:(UIFont *)font foregroundColor:(UIColor *)textColor backgroundColor:(UIColor *)backgroundColor;

- (void)toggleLabel;
- (void)showLabel;
- (void)hideLabel;

- (void)replaceUIImage:(UIImage *)image;
- (void)replaceUIImage:(UIImage *)image anchorPoint:(CGPoint)anchorPoint;

- (void)startAnimation:(BOOL)presenting;
- (void)startImageAnimation;
@end
