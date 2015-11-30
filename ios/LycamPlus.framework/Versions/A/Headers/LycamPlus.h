//
//  LycamPlus.h
//  FFmpegEncoder
//
//  Created by xman on 10/15/15.
//  Copyright (c) 2014 xman. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LCPDefines.h"
#import "LCPConst.h"

//#define SERVIER_BOOT_URL @"http://192.168.1.105:1337/bootstrap"
//#define LCP_SERVICE_API_ROOT_URL @"http://192.168.1.105:1337"
//#define SERVIER_BOOT_URL @"http://192.168.1.9:1337/bootstrap"
//#define LCP_SERVICE_API_ROOT_URL @"http://192.168.1.9:1337"


/**
 *  Block executed when stream is ready.
 *
 *  @param streamURL URL to the streamable m3u8
 *  @see presentBroadcasterFromViewController:ready:completion:
 */
typedef void (^LCPBroadcastReadyBlock)(NSDictionary *stream);

/**
 *  Block executed when completed live broadcast
 *
 *  @param success Whether or not broadcast was successful
 *  @param error   Any error that occurred
 *  @see presentBroadcasterFromViewController:ready:completion:
 */
typedef void (^LCPBroadcastCompletionBlock)(BOOL success, NSError* error);
typedef void (^LCPSignInCompletionBlock)(BOOL success, NSError* error);
typedef void (^LCPSignOutCompletionBlock)(BOOL success, NSError* error);


/**
 *  LycamPlus is the easiest way to broadcast live video. Sign up today at https://lycam.tv
 */
@interface LycamPlus : NSObject

//@interface LycamPlus()
@property (nonatomic, copy) NSString *apiKey;
@property (nonatomic, copy) NSString *apiSecret;
@property (nonatomic,readonly) NSUInteger maxBitrate;
@property (nonatomic,readonly) NSUInteger maxKeyFrame;
@property (nonatomic,readonly) BOOL useAdaptiveBitrate;
@property (nonatomic,readonly) NSUInteger segmentDurationSeconds;
@property (nonatomic,readonly) NSInteger hlsListSize;

//@end

///-------------------------------
/// @name Setup
///-------------------------------

/**
 *  Initilize the LycamPlus client.
 *
 *  @param key    API key from lycam.tv
 *  @param secret API secret from lycam.tv
 */
+ (void) initWithAppKey:(NSString*)key secret:(NSString*)secret;

/**
 *  Returns the active API key.
 *
 *  @return API key from lycam.tv
 *  @see setupWithAPIKey:secret:
 */
+ (NSString*) apiKey;
/**
 *  Returns the active API secret
 *
 *  @return API secret from lycam.tv
 *  @see setupWithAPIKey:secret:
 */
+ (NSString*) apiSecret;

///-------------------------------
/// @name Broadcast
///-------------------------------

/**
 *  Presents LCPBroadcastViewController from your view controller.
 *
 *  @param viewController  Presenting controller
 *  @param readyBlock      Called when streamURL is ready
 *  @param completionBlock Called when broadcaster is dismissed
 */
+ (void) presentBroadcasterViewController:(UIViewController*)viewController ready:(LCPBroadcastReadyBlock)readyBlock completion:(LCPBroadcastCompletionBlock)completionBlock;

///-------------------------------
/// @name Configuration
///-------------------------------

/**
 *  Maximum bitrate (combined video + audio)
 *  @warn Do not set this value to lower than ~300 Kbps
 *
 *  @return Defaults to 2 Mbps
 */
+ (double) maxBitrate;



/**
 *  Whether or not to actively adjust the bitrate to network conditions.
 *
 *  @return Defaults to YES
 */
+ (BOOL) useAdaptiveBitrate;

/**
 *  Whether or not to actively adjust the bitrate to network conditions.
 *
 *  @param enabled BOOL
 */
+ (void) setUseAdaptiveBitrate:(BOOL)enabled;

+ (LycamPlus*) sharedInstance;

+ (void) logout:(LCPSignOutCompletionBlock)completionBlock;

+ (void) login:(NSString*) username withPassword:(NSString *) password completion:(LCPSignInCompletionBlock)completionBlock;
+ (void) initWithAppKey:(NSString*)key secret:(NSString*)secret withUsername:(NSString*) username withPassword:(NSString *) password completion:(LCPSignInCompletionBlock)completionBlock;

@end



