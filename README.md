# LycamPlus SDK (iOS)

[![CI Status](http://img.shields.io/travis/xman/LycamPlus.svg?style=flat)](https://travis-ci.org/xman/LycamPlus)
[![Version](https://img.shields.io/cocoapods/v/LycamPlus.svg?style=flat)](http://cocoapods.org/pods/LycamPlus)
[![License](https://img.shields.io/cocoapods/l/LycamPlus.svg?style=flat)](http://cocoapods.org/pods/LycamPlus)
[![Platform](https://img.shields.io/cocoapods/p/LycamPlus.svg?style=flat)](http://cocoapods.org/pods/LycamPlus)


## 安装

LycamPlus 通过来 [CocoaPods](http://cocoapods.org) 发布. 
你应该首先安装 [Cocoapods](http://cocoapods.org) .
    
添加下面的文本到你的 `Podfile` 文件中:

    pod "FFmpeg"
	pod "LycamPlus",:git=>'https://github.com/lycam/LycamPlusSDK-iOS.git'
 
通过 Cocoapods 来安装所有的依赖包

    $ pod install

注意，以上操作完成后，xcode 应该打开 .xcworkspace 后缀的工程文件，而不是原来的`.xcodeproj` 文件



# LycamPlus SDK (iOS)

[LycamPlus](http://plus.lycam.tv) 云平台可以为你的 iOS 应用提供一种视频直播的快速开发的解决方案 . 你可以使用简单的几行代码来完成视频直播功能. [LycamPlus iOS SDK 范例](https://github.com/lycam/lycamplus-ios-example) 是演示代码.

## 开速开始

最快的方法是 直接克隆 [LycamPlus iOS SDK 范例](https://github.com/lycam/lycamplus-ios-example) 项目 . 使用 `CPBroadcastViewController` 来开始一个视频直播:

```objc

#import "LycamPlus.h"
// 初始化 LycamPlus SDK,并使用已知用户

[LycamPlus initWithAppKey:@"API_KEY" secret:@"API_SECRET" withUsername:@"your_username" withPassword:@"password" completion:^(BOOL success, NSError* error){
	if(success==NO)
        NSLog(@"认证失败: %@", error);
}];

...

- (void) broadcastButtonPressed:(id)sender {

	[LycamPlus presentBroadcasterViewController:self ready:^(NSDictionary *stream) {
        if (stream) {
            NSLog(@"Stream is ready at URL: %@", [stream objectForKey:kLCPStreamURL]);
        }
    } completion:^(BOOL success, NSError* error){
	      if (!success) {
            NSLog(@"Error setting up stream: %@", error);
        } else {
            NSLog(@"Done broadcasting");
        }
    }];
}
```


    
## 文档

为了进一步了解 LycamPlus SDK iOS，你可以阅读 [iOS 文档](https://github.com/lycam/lycamplus-docs/ios) . 亦可以查看[教程](ttps://github.com/lycam/lycamplus-docs) 来帮助你入门.
    
## 作者

no777 , wt@lycam.tv

## 版权申明

Apache 2.0

	Copyright 2015 Lycam, Inc.
	
	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at
	
	    http://www.apache.org/licenses/LICENSE-2.0
	
	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.