//
//  LCPStream.h
//  Lycamplus
//
//  Created by xman on 10/15/15.
//  Copyright (c) 2014 xman. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "Mantle/Mantle.h"

@class LCPUser;


typedef NS_ENUM(NSUInteger, LCPStreamState) {
    LCPStreamStateUndefined = 0,
    LCPStreamStateStreaming = 1,
    LCPStreamStatePaused = 2,
    LCPStreamStateStopped = 3,
    LCPStreamStateFinished = 4,
    LCPStreamStateFailed = 5
};


/**
 *  Native object for serialized /api/stream responses
 */
@interface LCPStream : MTLModel <MTLJSONSerializing>

@property (nonatomic, strong) NSDictionary* json;
@property (nonatomic, readonly) NSInteger maxBitrate;
@property (nonatomic, readonly) NSInteger maxKeyFrame;
@property (nonatomic, readonly) NSInteger segmentDurationSeconds;
@property (nonatomic, readonly) NSInteger hlsListSize;
@property (nonatomic, strong) NSString *prefix;

@property (nonatomic, readonly) BOOL useAdaptiveBitrate;

/**
 *  Stream owner, maps to a LCPUser
 *  @see LCPUser
 */
@property (nonatomic, strong) NSString *username;

/**
 *  Stream UUID (unique identifier)
 */
@property (nonatomic, strong, readonly) NSString *streamID;

/**
 *  HLS or RTMP (currently only HLS is supported)
 */
@property (nonatomic, strong, readonly) NSString *streamType;

/**
 *  Currently unused (for RTMP support)
 */
@property (nonatomic, strong, readonly) NSURL *uploadURL;

/**
 *  Location of raw .m3u8 HLS manifest for use in native media players
 */
@property (nonatomic, strong, readonly) NSURL *streamURL;

/**
 *  lycam.tv URL for public consumption on the web
 */
@property (nonatomic, strong, readonly) NSURL *resourceURL;

/**
 *  When recording was started
 */
@property (nonatomic, strong, readonly) NSDate *startDate;

/**
 *  When recording was finished
 */
@property (nonatomic, strong, readonly) NSDate *finishDate;

/**
 *  URL for thumbnail jpg, generated client-side for local recordings
 */
@property (nonatomic, strong) NSURL *thumbnailURL;

/**
 *  City metadata returned by local reverse geocoder
 */
@property (nonatomic, strong) NSString *city;
/**
 *  Country
 */
@property (nonatomic, strong) NSString *country;
/**
 *  State
 */
@property (nonatomic, strong) NSString *state;

/**
 *  Start location of recording
 */
@property (nonatomic, strong) CLLocation *startLocation;

/**
 *  End location of recording
 */
@property (nonatomic, strong) CLLocation *endLocation;

/**
 *  State of the stream
 *  @see LCPStreamState
 */
@property (nonatomic) LCPStreamState streamState;
@property (nonatomic, readonly) NSString *transportProtocol;


/**
 *  Whether or not a recording is currently being broadcast.
 *  Currently this is calculated by the startDate and finishDate info.
 *
 *  @return It's live!
 */
- (BOOL) isLive;

@end
