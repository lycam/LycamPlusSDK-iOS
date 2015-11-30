//
//  LCPUser.h
//  FFmpegEncoder
//
//  Created by xman on 1/22/14.
//  Copyright (c) 2014 xman. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Mantle/Mantle.h"

/**
 *  Native user model based on LycamPlus API responses. All user data within
 *  the public data will be queryable and assumed to be public information.
 */
@interface LCPUser : MTLModel <MTLJSONSerializing>

///-------------------------------
/// @name Public Data
///-------------------------------

/**
 *  Username returned by the server
 */
@property (readonly, nonatomic, strong) NSString *username;

/**
 *  User's desired display name
 */
@property (readonly, nonatomic, strong) NSString *displayName;

/**
 *  URL to the user's avatar
 */
@property (readonly, nonatomic, strong) NSURL *avatarURL;

/**
 *  Any additional information you'd like to store with a user.
 *  This is publicly queryable so do not store sensitive information here.
 *  @note Must be JSON serializable!
 */
@property (nonatomic, strong) NSDictionary *extraInfo;

/**
 *  lycam.tv app name
 */
@property (readonly, nonatomic, strong) NSString *appName;

///-------------------------------
/// @name Private Data for the Active User
///-------------------------------


/**
 *  Unique identifier (UUID) returned by the server. This is used as an
 *  authentication token for the API.
 *  @note Do not expose this publicly.
 */
@property (readonly, nonatomic, strong) NSString *uuid;

/**
 *  Password for active user's account. Stored in the iOS Keychain.
 */
@property (nonatomic, strong) NSString *password;

///-------------------------------
/// @name Setting the Active User
///-------------------------------

/**
 *  Active LCPUser for communication with API, stored in `NSUserDefaults`.
 *
 *  @return active user, or nil if not availible
 */
+ (instancetype) activeUser;

/**
 *  Store the active user to `NSUserDefaults`
 *
 *  @param user if this parameter is nil, it will remove the active user.
 */
+ (void) setActiveUser:(LCPUser*)user;

@end
