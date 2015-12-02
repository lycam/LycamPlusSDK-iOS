//
//  LCPDefines.h
//  Pods
//
//  Created by xman on 15/11/18.
//
//

#ifndef LCPDefines_h
#define LCPDefines_h

extern NSString * const kLCPServiceAPIDomain;
extern NSString * const kLCPAPIVersion;
extern NSString * const kLCPOAuthRootDomain;

#define LCP_SERVICE_API_URL [LycamPlus sharedInstance].useSSL?[NSString stringWithFormat:@"https://%@/v%@",kLCPServiceAPIDomain,kLCPAPIVersion]:[NSString stringWithFormat:@"http://%@/v%@",kLCPServiceAPIDomain,kLCPAPIVersion]

#define KLCP_OAUTH2_URL [LycamPlus sharedInstance].useSSL?[NSString stringWithFormat:@"https://%@/%@",kLCPOAuthRootDomain,@"oauth2/token/"]:[NSString stringWithFormat:@"http://%@/%@",kLCPOAuthRootDomain,@"oauth2/token/"]

#define KLCP_STREAM_START_URL @"stream/start"
#define KLCP_STREAM_STOP_URL @"stream"
#define KLCP_STREAM_UPDATE_URL @"stream"
#define KLCP_STREAM_URL @"stream"


#endif /* LCPDefines_h */
