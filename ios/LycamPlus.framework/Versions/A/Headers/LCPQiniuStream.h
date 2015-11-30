//
//  LCPQiniuStream.h
//  Pods
//
//  Created by no on 15/11/9.
//
//

#import "LCPStream.h"
extern const struct LCPQiniuStreamAttributes {
    __unsafe_unretained NSString *bucketName;
    __unsafe_unretained NSURL *uploadURLBackup;
    __unsafe_unretained NSString *uploadIP;
    __unsafe_unretained NSString *uploadIPBackup;
    __unsafe_unretained NSString *uploadPort;
} LCPQiniuStreamAttributes;

@interface LCPQiniuStream : LCPStream
@property (nonatomic, strong) NSString *bucketName;
@property (nonatomic, strong) NSURL *uploadURLBackup;
@property (nonatomic, strong) NSString *uploadIP;
@property (nonatomic, strong) NSString *uploadIPBackup;
@property (nonatomic) NSInteger uploadPort;


@end
