//
//  LCPS3Stream.h
//  LycamPlus
//
//  Created by xman on 10/15/15.
//  Copyright (c) 2014 xman. All rights reserved.
//

#import "LCPStream.h"

extern const struct LCPOSSStreamAttributes {
    __unsafe_unretained NSString *bucketName;
	__unsafe_unretained NSString *accessKey;
	__unsafe_unretained NSString *secretKey;
    __unsafe_unretained NSString *prefix;
    __unsafe_unretained NSString *endpoint;
} LCPOSSStreamAttributes;


@interface LCPOSSStream : LCPStream


@property (nonatomic, strong) NSString *endpoint;

@property (nonatomic, strong) NSString *bucketName;
@property (nonatomic, strong) NSString *accessKey;
@property (nonatomic, strong) NSString *secretKey;
@property (nonatomic, strong) NSString *sessionToken;
@property (nonatomic, strong) NSDate *expirationDate;
@property (nonatomic, strong) NSString *region;

@end
