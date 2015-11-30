//
//  LCPAPIClient.h
//  LycamPlus
//
//  Created by xman on 10/15/15.
//  Copyright (c) 2014 xman. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCPStream.h"
#import "AFNetworking/AFNetworking.h"
#import <CoreLocation/CoreLocation.h>
#import "LCPPaginationInfo.h"
extern  NSString* const kLCPAPIClientErrorDomain;



/**
 *  Use LCPAPIClient to interact with the lycam.tv API.
 */
@class LCPAPIClient,LCPClientConfig;

@protocol LCPAPIClientDelegate <NSObject>
- (void) clientDidFinishRecording:(LCPAPIClient*)client error:(NSError*)error;
@end


@interface LCPAPIClient : AFHTTPSessionManager 
{

}
@property (nonatomic, weak) id<LCPAPIClientDelegate> delegate;

/**
 *  Singleton for easy access around your project
 *
 *  @return LCPAPIClient singleton
 */
+ (LCPAPIClient*) sharedClient;

//- (instancetype) initWithConfig:(LCPClientConfig *) config;

///-------------------------------
/// @name Users
///-------------------------------

/**
 *  Requests new active LCPUser.
 *
 *  @param username      (optional) desired username
 *  @param callbackBlock called when the request completes with either an active user or an error
 */
- (void) registerNewUser:(NSString*)username callbackBlock:(void (^)(LCPUser *activeUser, NSError *error))callbackBlock;

/**
 *  Requests new active LCPUser.
 *
 *  @param username      (optional) desired username
 *  @param password User's password
 *  @param email User's email address
 *  @param displayName Name shown instead of username
 *  @param extraInfo Any additional context-specific information you'd like to store for your user.
 *  @param callbackBlock called when the request completes with either an active user or an error
 */
- (void) registerNewUser:(NSString*)username password:(NSString*)password email:(NSString*)email  displayName:(NSString*)displayName extraInfo:(NSDictionary*)extraInfo callbackBlock:(void (^)(LCPUser *activeUser, NSError *error))callbackBlock;

/**
 *  Logs in an existing user. This fetches the credentials required for streaming
 *  and makes it the current active LCPUser.
 *
 *  @param username Existing LycamPlus username
 *  @param password User's password
 *  @param callbackBlock called when the request completes with either an active user or an error
 */
- (void) login:(NSString*)username password:(NSString*)password callbackBlock:(void (^)(LCPUser *activeUser, NSError *error))callbackBlock;

/**
 *  Logs out an existing user. This fetches the credentials required for streaming
 *  and makes it the current active LCPUser.
 *
 *  @param username Existing LycamPlus username
 *  @param password User's password
 *  @param callbackBlock called when the request completes with either an active user or an error
 */

- (void) logout:(void (^)(BOOL success, NSError *error))callbackBlock;

/**
 *  Updates existing user metadata.
 *
 *  @param email User's email address
 *  @param newPassword (optional) For changing the user's current password
 *  @param displayName Name shown instead of username
 *  @param extraInfo Any additional context-specific information you'd like to store for your user.
 *  @param callbackBlock called when the request completes with either an active user or an error
 */
- (void) updateMetadataForActiveUserWithNewPassword:(NSString*)newPassword email:(NSString*)email displayName:(NSString*)displayName extraInfo:(NSDictionary*)extraInfo callbackBlock:(void (^)(LCPUser *updatedUser, NSError *error))callbackBlock;

/**
 *  Fetches public data for an existing username.
 *
 *  @param username Existing user's username
 *  @param callbackBlock Serialized existing user or error
 *
 */
- (void) requestUserInfoForUsername:(NSString*)username callbackBlock:(void (^)(LCPUser *existingUser, NSError *error))callbackBlock;

///-------------------------------
/// @name Stream Lifecycle
///-------------------------------

/**
 *  Starts a new public stream to be fed to LCPRecorder
 *
 *  @param endpointCallback Called when request completes for new stream or error
 */
- (void) startNewStream:(void (^)(LCPStream *newStream, NSError *error))endpointCallback;

/**
 *  Starts a new private stream to be fed to LCPRecorder
 *
 *  @param endpointCallback Called when request completes for new stream or error
 */
- (void) startNewPrivateStream:(void (^)(LCPStream *newStream, NSError *error))endpointCallback;

/**
 *  Marks the stream as stopped on the server
 *
 *  @param stream        stream to be stopped
 *  @param callbackBlock (optional) whether or not this was successful
 */
- (void) stopStream:(LCPStream*)stream callbackBlock:(void (^)(BOOL success, NSError *error))callbackBlock;

/**
 *  Posts to /api/stream/change the changes in your LCPStream. This will return a new
 *  stream object, leaving the original object unchanged.
 *
 *  @param stream        stream to be updated
 *  @param callbackBlock (optional) serialized LCPStream response or error
 */
- (void) updateMetadataForStream:(LCPStream*)stream callbackBlock:(void (^)(LCPStream* updatedStream, NSError *error))callbackBlock;

- (void) updateStatusForStream:(LCPStream *)stream withStatus:(NSDictionary *)parameters callbackBlock:(void (^)(NSDictionary* respond, NSError *))callbackBlock ;


///-------------------------------
/// @name Stream Search
///-------------------------------

/**
 *  Requests all streams created by a particular user
 *
 *  @param username      username to filter by
 *  @param pageNumber    desired page offset for paginating results. The first page starts at 1, not 0.
 *  @param itemsPerPage  desired number of items per page (max 200), default 25.
 *  @param callbackBlock Returns array of LCPStream and a LCPPaginationInfo for pagination information, or an error.
 *  @see LCPPaginationInfo
 */
- (void) requestStreamsForUsername:(NSString*)username pageNumber:(NSUInteger)pageNumber itemsPerPage:(NSUInteger)itemsPerPage callbackBlock:(void (^)(NSArray *streams, LCPPaginationInfo *paginationInfo, NSError *error))callbackBlock;

/**
 *  Returns all the streams created near a certain location
 *
 *  @param location      Center point of search
 *  @param radius        (optional)
 *  @param pageNumber    desired page offset for paginating results. The first page starts at 1, not 0.
 *  @param itemsPerPage  desired number of items per page (max 200), default 25.
 *  @param callbackBlock Returns array of LCPStream and a LCPPaginationInfo for pagination information, or an error.
 *  @see LCPPaginationInfo
 */
- (void) requestStreamsForLocation:(CLLocation*)location radius:(CLLocationDistance)radius pageNumber:(NSUInteger)pageNumber itemsPerPage:(NSUInteger)itemsPerPage callbackBlock:(void (^)(NSArray *streams, LCPPaginationInfo *paginationInfo, NSError *error))callbackBlock;

/**
 *  Returns all the streams with metadata containing keyword
 *
 *  @param keyword (Optional) If this parameter is omitted it will return all streams
 *  @param pageNumber    desired page offset for paginating results. The first page starts at 1, not 0.
 *  @param itemsPerPage  desired number of items per page (max 200), default 25.
 *  @param callbackBlock Returns array of LCPStream and a LCPPaginationInfo for pagination information, or an error.
 *  @see LCPPaginationInfo
 */
- (void) requestStreamsByKeyword:(NSString*)keyword pageNumber:(NSUInteger)pageNumber itemsPerPage:(NSUInteger)itemsPerPage callbackBlock:(void (^)(NSArray *streams, LCPPaginationInfo *paginationInfo, NSError *error))callbackBlock;

/**
 *  Returns all the streams associated with this application.
 *
 *  @param pageNumber    desired page offset for paginating results. The first page starts at 1, not 0.
 *  @param itemsPerPage  desired number of items per page (max 200), default 25.
 *  @param callbackBlock Returns array of LCPStream and a LCPPaginationInfo for pagination information, or an error.
 *  @see LCPPaginationInfo
 */
- (void) requestAllStreamsWithPageNumber:(NSUInteger)pageNumber itemsPerPage:(NSUInteger)itemsPerPage callbackBlock:(void (^)(NSArray *streams, LCPPaginationInfo *paginationInfo, NSError *error))callbackBlock;



@end
