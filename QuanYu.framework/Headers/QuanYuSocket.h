//
//  QuanYuSocket.h
//  QuanYu
//
//  Created by 周新 on 2020/2/25.
//  Copyright © 2020 周新. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol QuanYuSocketDelegate <NSObject>

@required

/// 收到的消息
/// @param message 消息内容
- (void)onMessage:(NSString *)message;

@optional

/// 连接服务器时触发
/// @param attempts 重试次数
- (void)onConnecting:(int)attempts;

/// 连接成功 （包括重启连接）
- (void)onConnected;

/// 连接断开 （退出登录不触发）
/// @param code 错误代码
/// @param reason 错误原因
- (void)onDisconnectedWithCode:(int)code WithReason:(NSString *)reason;

/// 登录失败
/// @param code 错误代码
/// @param reason 错误原因
- (void)onConnectFailedWithCode:(int)code WithReason:(NSString *)reason;

@end



@interface QuanYuSocket : NSObject

//心跳时间间隔   - 默认值120
@property (nonatomic, assign) int heartbeatInterval;

//最大重连时间间隔   - 默认值30
@property (nonatomic, assign) int connectionRecoveryMaxInterval;

//最小重连时间间隔   - 默认值2
@property (nonatomic, assign) int connectionRecoveryMinInterval;

//重连次数   - 默认值0
@property (nonatomic, assign, readonly) int reconnectAttempts;

//代理
@property (nonatomic, weak) id<QuanYuSocketDelegate > delegate;

+ (instancetype)shared;

// 登录
- (void)login:( NSString * _Nonnull )loginUrl;

// 退出登录
- (void)logout;

// 发送请求方法sendRequest
- (void)sendRequestWithMessage:(NSString *)str;

// 设置app保活方法 默认NO NO:不保活 YES:保活
- (void)setupKeepAlive:(BOOL)sender;

@end

NS_ASSUME_NONNULL_END
