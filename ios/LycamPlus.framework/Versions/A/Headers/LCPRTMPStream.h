//
//  LCPRTMPEndpoint.h
//  LycamPlus
//
//  Created by xman on 10/15/15.
//  Copyright (c) 2014 xman. All rights reserved.
//

#import "LCPStream.h"

@interface LCPRTMPStream : LCPStream

@property (nonatomic, strong) NSURL *rtmpURL;

@end
